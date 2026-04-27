# LNDH-YMK: Dokumento ng Batayang Arkitektura 

**Proyekto:** LundayHangin (LNDH)
**Yunit:** Yunit Malayuang Kontroler (YMK)
**Bersiyon:** 0.1.0 (2026)

---

## I. Herarkiya ng Kayarian
*Structural Hierarchy*

Susundin natin ang pagkakaayos ng ito upang matiyak na ang ating arkitektura ay modular at scalable.

### 1. Ang Sistema (LNDH)
- Binubuo ng apat na pangunahing hugpong.
- Ang bawat hugpong ay dapat may kakayahang makipag-ugnayan sa isa't isa nang deterministiko.

### 2. Ang Hugpong (YMK)
- **Materyal:** Arduino Nano ESP32, MCP23017, LoRa, RTC, SD Card, OLED, pushbuttons, swithes, analog sticks.
- **Tatagsil:** Arduino Framework (C++).
- **Lohika:** Event-driven at Hierarchical Command Sructure.

### 3. Ang mga Subsistema ng YMK

Hahatiin ang YMK sa limang (5) pangunahing subsistema:

| Kodigo | Ngalan | Tungkulin |
| --- | --- | --- |
| `ssPSK` | Subsistema ng Pagkuha ng Input (Input Harvesting) | Nakatutok sa pagbasa ng lahat ng digital at analog inputs. |
| `ssTLA` | Subsistema ng Oras at Tala (Time & Logging) | Pinamamahalaan ang RTC at SD Card para sa kasaysayan ng operasyon. |
| `ssKOM` | Subsistema ng Komunikasyon (Communication) | Nakatuon sa LoRa at pagbabalot ng data packets. | 
| `ssTNW` | Subsistema ng Pagpapatanaw (HMI/Feedback) | OLED display, buzzer, at LEDs | 
| `ssENE` | Subsistema ng Enerhiya (Power) | Battery management at voltage regulation. |

---

## II. Arkitektura ng YMK
*YMK Architecture*

Ang arkitektura ng YMK ay nakabatay sa prinsipyo ng **Pagbubukod ng Pananagutan** (*Separation of Concerns*). Tinitiyak nito na ang bawat subsistema ay nagsasarili ngunit may maayos na ugnayan sa kabuuan ng hugpong.

### 1. Arkitektura ng Materyal at Bus
*Physical & Bus Architecture*

Upang matiyak ang bilis at katatagan ng pagpapadala ng datos sa loob ng materyal, hinahati ang mga koneksiyon sa tatlong pangunahing landas:



#### A. I2C Bus (Landas ng Kontrol)
Ito ang pangunahing highway para sa mga mabababang bilis ngunit kritikal na kagamitan.
* **Kagamitan:** 2x MCP23017 (`0x20`, `0x21`), DS3231 RTC, at OLED Display.
* **Lohika ng Katatagan:** Pagpapatupad ng *I2C Bus Recovery* kung sakaling magkaroon ng pag-lockup sa SCL/SDA pins dahil sa ingay ng kuryente (noise).

#### B. SPI Bus (Landas ng Datos)
Ginagamit para sa mga kagamitang nangangailangan ng mataas na bilis ng paglilipat ng impormasyon.
* **Kagamitan:** LoRa Module (SX127X) at SD Card Module.
* **Lohika ng Katatagan:** Paghihiwalay ng *Chip Select (CS)* pins upang maiwasan ang banggaan ng datos sa pagitan ng komunikasyon (LoRa) at pagtatala (SD Card).

#### C. Analog Direct-Link (Landas ng Galaw)
* **Kagamitan:** Apat (4) na axis ng dalawang Analog Sticks.
* **Koneksyon:** Direkta sa ADC pins ng Arduino Nano ESP32 upang makamit ang pinakamababang *latency* (pagkaantala).

---

### 2. Latag ng Tatagsil (Firmware Layers)
*Firmware Layering*

Ang lohika ng YMK ay binuo sa apat na antas upang maging modular at madaling palawakin:

1.  **Latag ng Abstraksiyon ng Materyal (HAL):** Direktang kumakausap sa mga driver ng MCP23017, LoRa, at RTC. Kinukuha nito ang mga *raw values*.
2.  **Latag ng Pagsasala (Signal Processing):** Dito isinasagawa ang *Debouncing* para sa mga pushbutton at *Exponential Moving Average (EMA)* para sa pagpapakinis ng galaw ng analog sticks.
3.  **Latag ng Pagpapasya (Command Arbiter):** Isinasalin ang mga sinalang input tungo sa mga **Atas** (Commands). Dito rin tinitingnan ang kasalukuyang estado ng hugpong (hal. kung ito ay `ARMED` o `DISARMED`).
4.  **Latag ng Transportasyon (Communication):** Binabalot ang mga Atas sa loob ng isang **Pakete** (Packet) na may kasamang *Checksum* para sa integridad ng datos.

---

### 3. Daloy ng Lohika ng Subsistema (`ssPSK` patungong `ssKOM`)
*Logical Data Flow*

Ang bawat siklo (cycle) ng programa ay sumusunod sa deterministikong daloy:

* **Pagsagap (Sensing):** Pag-aani ng `ssPSK` sa estado ng lahat ng 32 digital pins at 4 analog axes.
* **Pagtatatak (Timestamping):** Pagkuha ng `ssTLA` ng eksaktong oras mula sa RTC para sa bawat mahalagang pagbabago ng estado.
* **Paghuhubog (Packaging):** Pagbuo ng `struct` na naglalaman ng lahat ng impormasyon.
* **Pagpapadala (Transmission):** Pag-uutos sa `ssKOM` na itawid ang Pakete sa pamamagitan ng LoRa link.

---

### 4. Protokol ng Kaligtasan at Failsafe
*Safety and Failsafe Protocols*

Bilang isang industrial-grade na hugpong, ang YMK ay may mga sumusunod na pananggalang:

* **Watchdog Timer (WDT):** Awtomatikong pagre-restart ng tatagsil kung ang programa ay hindi tumugon sa loob ng 1 segundo.
* **Bus Health Monitor:** Kung ang `ssPSK` ay hindi makabasa mula sa mga MCP23017, agad na itatakda ang `Failsafe_Flag` upang pigilan ang pagpapadala ng maling atas sa drone.
* **Power Awareness:** Ang `ssENE` ay maglalabas ng babala sa `ssTNW` (OLED/Buzzer) kung ang boltahe ng baterya ay kritikal na.

---

## III. ssPSK: Subsistema ng Pagkuha ng Input *(Input Harvesting Subsystem)* - Technical Specification

Ang ssPSK ay gumagamit ng dalawang (2) **MCP23017 GPIO Expanders** na nakikipag-ugnayan via I2C Bus. Ang arkitektura ay nakadisenyo para sa **Interrupt-Driven Event Handling** upang masiguro ang *real-time execution* at *deterministic behavior*.

### 1. Kumpigurasyon ng Hardware
- **I2C Clock Frequency:** 400 kHz (Fast Mode)
- **Interrupt Logic:** Active-Low, Open-Drain configuration.
- **Pull-up Resistors:** Internal 100kΩ (enabled via GPPU register).

### 2. Mapa ng mga Pin (Pin Mapping)

#### A. Modyul U1 (I2C Address: `0x20`)
*Tungkulin: Nabigasyon, Sistema, at Kaliwang Kontrol*

| Pin | ID (Atas) | Lohika | Deskripsiyon |
| --- | --- | --- | --- |
| **PORT A** | | | **D-PAD / KUMPAS** |
| GPA0 | `PSK_U1_NAV_UP` | Active-Low | Hilaga / Pataas (Up) |
| GPA1 | `PSK_U1_NAV_DN` | Active-Low | Timog / Pababa (Down) |
| GPA2 | `PSK_U1_NAV_LT` | Active-Low | Kanluran / Kaliwa (Left) |
| GPA3 | `PSK_U1_NAV_RT` | Active-Low | Silangan / Kanan (Right) |
| GPA4-7 | `PSK_U1_RES_A` | - | Reserbado (Expansion) |
| **PORT B** | | | **KONTROL-BALIKAT AT SISTEMA** | 
| GPB0 | `PSK_U1_SHL_L1` |Active-Low | Left Bumper (L1) |
| GPB1 | `PSK_U1_SHL_L2` | Active-Low | Left Trigger (L2) |
| GPB2 | `PSK_U1_STK_L3` | Active-Low | Left Stick Click |
| GPB3 | `PSK_U1_SYS_ARM` | Toggle | Master Arming Switch |
| GPB4-7 | `PSK_U1_RES_B` | - | Reserbado (Expansion) |

#### B. Modyul U2 (I2C Address: `0x21`)
*Tungkulin: Aksiyon, Payload, at Kanang Kontrol*

| Pin | ID (Atas) | Lohika | Deskripsiyon |
| --- | --- | --- | --- |
| **PORT A** | | | **FACE BUTTONS / AKSIYON** |
| GPA0 | `PSK_U2_ACT_NT` | Active-Low | Triangle / Y (Action North) |
| GPA1 | `PSK_U2_ACT_ST` | Active-Low | Cross / A (Action South) |
| GPA2 | `PSK_U2_ACT_ET` | Active-Low | Circle / B (Action East) |
| GPA3 | `PSK_U2_ACT_WT` | Active-Low | Square / X (Action West) |
| GPA4-7 | `PSK_U2_RES_A` | - | Reserbado (Expansion) |
| **PORT B** | | | **KONTROL-BALIKAT AT MENU** | 
| GPB0 | `PSK_U2_SHL_R1` | Active-Low | Right Bumper (R1) |
| GPB1 | `PSK_U2_SHL_R2` | Active-Low | Right Trigger (R2) |
| GPB2 | `PSK_U2_STK_R3` | Active-Low | Right Stick Click| 
| GPB3 | `PSK_U2_SYS_STR` | Active-Low | Start / Menu Button |
| GPB4-7 | `PSK_U2_RES_B` | - | Reserbado (Expansion) | 

#### C. Direktang Analog (MCU ADC)
*Tungkulin: Zero-Latency Flight Control*

| Pin (ESP32) | ID (Atas) | Resolution | Tungkulin |
| --- | --- | --- | --- |
| A0 | `ANA_L_HORZ` | 12-bit | Left Stick: Yaw |
| A1 | `ANA_L_VERT` | 12-bit | Left Stick: Throttle |
| A2 | `ANA_R_HORZ` | 12-bit | Right Stick: Roll |
| A3 | `ANA_R_VERT` | 12-bit | Right Stick: Pitch|

### 3. Protokol ng Pagkuha (Harvesting Protocol)
Upang mapanatili ang integridad ng datos sa mataas na antas (Industrial Grade):

1. **Mirroring Mode:** Ang `IOCON.MIRROR` bit ay itatakda sa `1` upang ang `INTA` at `INTB` pins ay gumana bilang iisang interrupt signal.

2. **Capture Mechanism:** Sa bawat interrupt trigger, ang tatagsil ay babasa sa `INTCAP` register sa halip na GPIO register. Pinoprotektahan nito ang estado ng pin sa sandali ng trigger laban sa *signal bouncing*.

3. **Atomic Read:** Ang pagbasa sa parehong Port A at Port B ay isasagawa sa isang (1) I2C transaction (Sequential Read) para sa pagtitipid sa *CPU cycles*.

### 4. Paghawak sa Aberya (Error Handling)

- **I2C Timeout:** Kung ang `ssPSK` ay hindi makatanggap ng tugon mula sa `0x20` o `0x21` sa loob ng 10ms, ang buong subsistema ay magdedeklara ng `BUS_ERROR`.

- **Neutral State Failsafe:** Sa oras ng `BUS_ERROR`, lahat ng analog values ay pipiliting maging `Neutral (0)` at ang `Master Arm` ay itatakda sa `DISARMED`.