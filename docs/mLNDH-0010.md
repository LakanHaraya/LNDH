## *mLNDH-0010*

# 📦 MK Espesipikasyon ng Pakete ng Kontrol
**LNDH Malayuang Kontroler (MK)**  
**Bersiyon:** 0.1.0 (Prototipo)  
**May-akda:** Lakan Haraya Dima  
**MCU:** Arduino Nano ESP32  

---

## 1. Panimula

Ang **Pakete ng Kontrol (Control Packet)** ay ang pangunahing *hamba ng datos (data frame)* na ipinapadala patungo sa iba't ibang yunit upang maisakatuparan ang mga utos ng piloto.

### 1.1 Mga Tumatanggap na Yunit
- **PS (Pangunahing Sasakyan)** – Tumanggap ng mga *real-time control commands* para sa paggalaw, direksiyon, tulok, at boyansi.
- **TD (Takad Daungan)** – Tumanggap ng mga *auxiliary control commands* para sa pagdaong, paglipad, o pagposisyon ng lunday.
- **KL (Kontrol sa Lupa)** – Tumanggap ng *status packets* mula sa MK bilang ulat ng aktuwal na estado ng mga kontrol, hindi bilang direktang utos.

### 1.2 Pagkakahiwalay ng Estruktura

Bagamat sabay-sabay at magkaparallel ang pagpapadala ng datos sa mga yunit na ito, **magkaiba ang layunin at bahagyang magkaiba ang estruktura ng mga pakete**:

| Daluyan | Uri ng Pakete | Nilalaman |
| --- | --- | --- |
| MK → PS | `MK_PS_Command` | Mga direktang utos ng piloto para sa propulsiyon, direksiyon, at altitud. |
| MK → TD | `MK_TD_Command` | Mga utos kaugnay ng pagdaong, paglipad, at posisyon ng pantalan o base. |
| MK → KL | `MK_KL_Status` | Impormasyong pansubaybay gaya ng kasalukuyang ipinadalang utos ng MK para sa PS at TD, bilang telemetriya at diyagnostika. |

### 1.3 Layunin ng Pakete
Layunin ng sistemang ito na:
- Magpasa ng *sabay-sabay na kontrol* sa PS at TD;
- Maghatid ng *katayuang pang-ulat* sa KL;
- Panatilihin ang *pagkakasabay-sabay* sa lahat ng hugpong ng network;
- Magbigay ng matatag na balangkas para sa pagproseso ng mga datos sa hinaharap (diyagnostika, kontrol na ginagabayan ng AI, atbp.).

---

## 2. Estruktura ng `ControlPacket`

Ang **`ControlPacket`** ay binubuo ng magkakasunod na bytes na ipinapadala mula sa **MK (Malayuang Kontroler)** patungo sa mga yunit ng PS, TD, at KL.

1. **Pamuhatan (`Header`)** – naglalaman ng pagkakakilanlan, oras, at uri ng pakete.
2. **Nilalaman (`Payload`)** – naglalaman ng aktuwal na datos ng kontrol o ulat, depende sa tatanggap.
3. **Pamakasan (`Trailer`)** – naglalaman ng pansuri sa ipinadalang datos.

### 2.1 Paghahamba (Framing) at Delimiter

Upang matukoy nang malinaw ang simula at dulo ng bawat pakete sa *serial* o *RF link,* ginagamit ang framing delimiter.
Ito ay kinakailangang hindi lumalabas sa karaniwang nilalaman ng mga byte.

### 2.1.1 Inirerekomendang Anyo

``` sh
[0x7E] [Pamuhatan] [Nilalaman] [Pamakasan] [0x7F]
```

| Simbolo | Byte | Tawag | Layunin |
| --- | --- | --- | --- |
| `[0x7E]` | 126 | Start Delimiter | Tanda ng simula ng pakete |
| `[0x7F]` | 127 | End Delimiter | Tanda ng pagtatapos ng pakete |

> **Tandaan:** Kung sakaling lumitaw ang `0x7E` o `0x7F` sa loob ng datos, gumamit ng **byte-stuffing** (hal. ipasok ang `0x7D` bilang escape byte at i-XOR sa `0x20` ang kasunod).  
>
> Ang ganitong framing ay tugma sa mga radio modules gaya ng **HC-12**, **LoRa**, o **NRF24L01**, at sa karaniwang **Serial** transmission.


### 2.2  Pamuhatan ng Pakete (`MK_Header`)

| Larang | Laki | Uri | Halimbawa | Paglalarawan |
|-------|------|------|------------|---------------|
| `id` | 1 B | `uint8_t` | `0xA1` | Natatanging ID ng tagapagdala ng pakete (MK unit) |
| `timestamp` | 4 B | `uint32_t` | `20251011T102312Z` | Oras ng paglikha ng pakete (UNIX epoch o ISO 8601) |
| `type` | 1 B | `uint8_t` | `0x01` | Uri ng pakete: `0x01=PS_CMD`, `0x02=TD_CMD`, `0x03=KL_STAT` |

### 2.3 Nilalaman ng Pakete (Magkakaiba)

#### 2.3.1. `MK_PS_Command`
Utos para sa **Pangunahing Sasakyan** – tumutukoy sa mga pangunahing utos gaya ng *tulok, timon, boyansi, at iba pa*.

| Larang | Laki | Saklaw | Nakatakda | Paglalarawan |
|--------|------|--------|----------|---------------|
| `PScmd_flags` | 1 B | bits | `0x00` | Mga espesyal na bit (arm, disarm, override, atbp.) |
| `thrust` | 1 B | 0 – 255 | 128 | Kontrol sa lakas ng propeller; <br> 0 = paurong, 128 = matamlay, 255 = pasulong |
| `rudder` | 1 B | 0 – 255 | 128 | Kontrol sa pagliko ng lunday; <br> 0 = pakaliwa, 128 = tuwid, 255 = pakaliwa |
| `elevator` | 1 B | 0 – 255 | 128 | Kontrol sa pagtango ng lunday; <br> 0 = payuko, 128 = matamlay, 255 = paliyad |
| `swiveller` | 1 B | 0 – 255 | – | Kontrol sa anggulo ng nakavektor na pantulok; <br> 0 = pahiga, 255 = patayo |
| `ballonet` | 1 B | 0 – 255 | – | Kontrol sa antas ng hangin sa ballonet; <br> 0 = paimpis, 255 = papintog |

---

#### 2.3.2. `MK_TD_Command`
Utos para sa **Takad Daungan** – tumutukoy sa pagposisyon, paglipad, o pagdaong ng lunday.

| Larang | Laki | Saklaw | Nakatakda | Paglalarawan |
|--------|------|--------|----------|---------------|
| `TDcmd_flags` | 1 B | bits | `0x00` | Mga kontrol sa kaligtasan at override |
| `dock_cmd` | 1 B | 0 – 3 | 0 | 0 = manwal, 1 = kusandaong, 2 = ilunsad, 3 = kapit |
| `winch_cmd` | 1 B | 0 – 255 | 0 | Bilis/direksiyon ng tangkalag para sa tali o kable <br> 0 = palapit, 255 = palayo |

---

#### 2.3.3. `MK_KL_Status`
Impormasyong ipinadadala sa **Kontrol sa Lupa** para sa telemetriya at diyagnostika.

| Larang | Laki | Saklaw | Nakatakda | Paglalarawan |
|--------|------|------|-------|--------|
| `PScmd_flags` | 1 B | bits | `0x00` | Mga espesyal na bit (arm, disarm, override, atbp.) |
| `thrust` | 1 B | 0 – 255 | 128 | Kontrol sa lakas ng propeller; <br> 0 = paurong, 128 = matamlay, 255 = pasulong |
| `rudder` | 1 B | 0 – 255 | 128 | Kontrol sa pagliko ng lunday; <br> 0 = pakaliwa, 128 = tuwid, 255 = pakaliwa |
| `elevator` | 1 B | 0 – 255 | 128 | Kontrol sa pagtango ng lunday; <br> 0 = payuko, 128 = matamlay, 255 = paliyad |
| `swiveller` | 1 B | 0 – 255 | – | Kontrol sa anggulo ng nakavektor na pantulok; <br> 0 = pahiga, 255 = patayo |
| `ballonet` | 1 B | 0 – 255 | – | Kontrol sa antas ng hangin sa ballonet; <br> 0 = paimpis, 255 = papintog |
| `TDcmd_flags` | 1 B | bits | `0x00` | Mga kontrol sa kaligtasan at override |
| `dock_cmd` | 1 B | 0 – 3 | 0 | 0 = manwal, 1 = kusandaong, 2 = ilunsad, 3 = kapit |
| `winch_cmd` | 1 B | 0 – 255 | 0 | Bilis/direksiyon ng tangkalag para sa tali o kable <br> 0 = palapit, 255 = palayo |
| `MKbatt` | 1 B | % | – | Natitirang lakas ng baterya ng MK |
| `link_quality` | 1 B | % | – | Lakas ng koneksiyon sa network |
| `MKstatus_flags` | 1 B | bits | – | Mga indikador: low-bat, comm-loss, sensor-error, atbp. |

### 2.4 Pamakasan ng Pakete (`MK_Trailer`)
| Larang | Laki | Uri | Halimbawa | Paglalarawan |
|-------|------|------|------------|---------------|
| `checksum` | 1 B | `uint8_t` | – | Pansuri ng bisa (simple XOR o CRC-8) |

### 2.5 Kabuoang Haba ng mga Pakete

| Uri ng Pakete | Laki (bytes) | Kabuoan kasama ang delimiter |
|----------------|-------|-------|
| `MK_PS_Command` | 13 B | 15 B (may `0x7E`, `0x7F`) |
| `MK_TD_Command` | 10 B | 12 B |
| `MK_KL_Status` | 19 B | 21 B |

Ang mga dagdag ng 2 bytes mula sa delimiter ay maliit na overhead lamang ngunit malaki ang tulong sa *pagkakasaby-sabay ng pakete*.

### 2.6 Kakayahan ng Arduino Nano ESP32

Ang **Arduino Nano ESP32** ay may higit na sapat na kakayahan upang hawakan ang naturang mga pakete:

- **RAM:** ≈ 320 KB
- **Flash:** ≈ 1.5 MB
- **Serial baudrate:** hanggang 2 Mbps (maaaring itakda sa 115200 bps pataas)
- **Average packet rate:** kahit 20–50 packets/second (20ms na agwat) ay ligtas; sa mas mababang 1000 ms na agwat, **napakaluwag pa ng latency**.

Kahit na sabay na dumadaloy ang tatlong direksiyon (PS, TD, KL), hindi lalampas sa 1KB/s ang kabuoang daloy ng datos — kaya magaan ito para sa sapad.

### 2.7  Format ng Pagpapadala

``` txt
[0x7E] [Pamuhatan] [Nilalaman] [Pamakasan] [0x7F]
```

Halimbawa sa `MK_PS_Command`:

``` txt
7E A1 65 32 10 01 80 80 80 80 80 80 5F 7F
```

---

### 2. 8 Integridad ng Datos ng Pakete ng Kontrol
<!--
*Tandaan:*  
Kung sa hinaharap ay ipatutupad ang iisang CRC scheme sa lahat ng yunit ng LNDH System (MK, PS, TD, KL, at iba pa), maaaring ilipat ang seksiyong ito sa hiwalay na dokumento gaya ng `mLNDH-00XX: Data Integrity and CRC Specification` para sa sentralisadong pamantayan.
-->

Upang matiyak ang kawastuhan ng datos na ipinapadala ng **MK (Malayuang Kontroler)** sa mga yunit ng **PS**, **TD**, at **KL**, ang bawat pakete ay tinatapos sa isang **CRC-8 checksum** na nagsisilbing pansuri ng integridad ng ipinadalang datos.

#### 2.8.1 Layunin
Ang CRC-8 ay ginagamit upang matukoy kung nagkaroon ng anumang *bit error* habang ipinapadala ang pakete sa serial o wireless na daluyan.  
Dahil walang *handshake* o *acknowledgement* na mekanismo sa pagitan ng MK at mga tatanggap nito, mahalaga ang pagkakaroon ng **lightweight error detection** upang mapanatiling ligtas at matatag ang transmisyon.

#### 2.8.2 Pamamaraan

- **Algorithm**: CRC-8, polynomial `0x07` ($x⁸ + ... + x² + x + 1$)  
- **Initial Value**: `0x00`  
- **Input Range**: Lahat ng bytes mula *Pamuhatan* (`Header`) hanggang sa *Nilalaman* (`Payload`), hindi kasama ang CRC byte.  
- **Output**: 1 byte (`uint8_t`) na idinadagdag bilang huling bahagi ng *Pamakasan* (`Trailer`).

Ang CRC ay binibilang ng tagapagdala (MK) at ipinapadala kasabay ng bawat pakete.  
Tinitiyak ng tagatanggap (PS, TD, o KL) na pareho ang kalkuladong CRC sa natanggap na CRC upang mapatunayang buo at tama ang datos.

#### 2.8.3 Mga Dahilan ng Pagpili sa CRC-8

| Katangian | Paliwanag |
|:--|:--|
| **Magaan sa CPU** | Ang CRC-8 ay mabilis kalkulahin kahit sa *tableless implementation*; mainam sa `Arduino Nano ESP32`. |
| **Mababang Overhead** | 1 byte lamang ang dagdag sa bawat pakete (≈3% overhead sa 30-byte packet). |
| **Epektibong Proteksiyon** | Natutukoy ang lahat ng *single-bit* at *double-bit* errors, at karamihan ng *burst errors* ≤ 8 bits. |
| **Angkop sa Real-Time** | Tugma sa *fire-and-forget* na transmisyon na walang retransmission o ack system. |

#### 2.8.4 Mga Pagpapalawig (Opsiyonal)

Kung sakaling kailanganin ng mas mataas na antas ng integridad sa komunikasyon (hal. para sa *critical safety commands* o *telemetry verification*), maaaring gamitin ang mga sumusunod na pagpapalawig:

- Paglipat sa **CRC-16 (poly 0x1021)** para sa mas mataas na proteksiyon laban sa mga *burst errors*; o  
- Pagdagdag ng *sequence counter* at *error flag feedback* mula sa tatanggap, kung papayagan na ang *acknowledged link* sa susunod na bersiyon.

#### 2.8.5 Buod

Ang paggamit ng **CRC-8** bilang pansuri ng integridad ng ipinadalang datos ay nagbibigay ng balanseng *bilis*, *simple*, at *maaasahan* para sa tuloy-tuloy na transmisyon ng datos ng MK patungo sa mga yunit ng PS, TD, at KL.  
Ito ay inirerekomendang panatilihin sa kasalukuyang arkitektura ng `ControlPacket` habang walang nakatalagang *acknowledgement system*.

---

---
 
## 5. Iba Pang Mga Flag Bits

<!-- 
``` cpp
// Halimbawa ng bitmask ng flags
#define FLAG_SAFETY_ARMED   0x01  // nakabitbit o aktibo ang propulsiyon
#define FLAG_OVERRIDE_MODE  0x02  // nasa manual override mode
#define FLAG_AUTOPILOT      0x04  // autopilot na aktibo
#define FLAG_FAILSAFE       0x08  // nasa failsafe state
```
 -->

---

## 6. Siklo ng Pagpapadala

| Aytem | Agwat | Funsiyon |
| --- | --- | --- |
| Pakete ng Kontrol | 1000ms (prototipo) | `sendControlToPS()` |
| Midyum ng Transmisyon | ESP-NOW (prototipo: Serial print) | Isang-tunguhan MK → PS |

Sa aktuwal na deployment, ang agwat ay magiging adaptibo (hal. 20–50 ms para sa tugon ng kontrolstik).

---

## 7. Mga Susunod na Pagpapalawak

* Pagsasama ng checksum o CRC byte
* Compression ng data frame para sa mas mabilis na transmisyon
* Pagdadagdag ng sequence number o timestamp
* Dynamic packet sizing (para sa optional modules tulad ng lighting o camera gimbal)

---

## 8. Halimbawa ng Output (Prototype Log)

``` sh
[00:02:03.251] [MK→PS] Kontrol: thr=200, swi=140, rud=130, ele=125, bal=150, flags=0x01
```

---

## 9. Kaugnay na Files

| File           | Deskripsyon                                         |
| -------------- | --------------------------------------------------- |
| `main.cpp`     | Pangunahing loop at scheduler                       |

<!--
| `konstant.h`   | Mga makro at sistematikong parameter                |
| `controller.h` | Basahin at i-map ang mga input ng joystick/pindutan |
| `telemetry.h`  | Para sa paglipat ng Control at Telemetry packets    |
| `display.h`    | UI feedback sa OLED/TFT                             |
-->

---

### Kasaysayan ng Dokumento

| Bersiyon | Petsa      | Pagbabago |
| ------- | ---------- | ------- |
| 0.1     | 2025-10-11 | Unang bersiyon ng ineeksperimentong pakete ng kontrol |
