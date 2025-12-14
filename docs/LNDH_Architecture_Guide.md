# LNDH Gabay sa Arkitektura
*Bersiyon 0.1 – Balangkas / Buhay na Dokumento*  
*Para sa: Nakabatay sa Arduino Nano ESP32 na Tigbayon ng LNDH*  
*Mga Yunit: Airship Drone (LH_PS) • Remote Controller (LH_MK) • Docking Base (LH_TD) • Ground Control Station (LH_KL)*

---

## ⚙️ Pangkalahatang Tanaw ng Pitong Latag ng LNDH

Ang **kalatagang LNDH** ay isang abstraksiyon ng herarkiyang modular na nagbibigay ng malinaw na pagkakabahagi ng tungkulin sa bawat yunit (Pangunahing Sasakyan, Malayuang Kontroler, Takad Daungan, at Kontrol sa Lupa). Ang sistemang LNDH ay hinati sa **pitong (7) pangunahing latag**, bawat isa ay may tiyak na papel.  

Hindi lahat ng yunit ay kailangang magkaroon ng lahat ng latag

---

## 🎯 Layunin
Ang dokumentong ito ay nagsisilbing gabay sa pagbubuo ng **modular at pleksibleng tigbayon ng tatagsil ng LNDH**.  

Layunin nitong magtaguyod ng:
- Malinis na dependensiya (dependency chain)
- Magaan at matipid na paggamit ng resource (RAM/Flash/Power)
- Mga karaniwang interfeys at kumbensiyon ng pagpapangalan.
- Inter-operabilidad ng apat na yunit.
- Pagbabago habang lumalawak ang sistema.

---

### 🧱 LATAG 0 — *Ubod / Batayan ng Sistema*  
**Pinakapundasyon ng lahat ng yunit.**

📘 **Layunin:**  
Magbigay ng mga batayang utilidad, uri ng datos, at iisang *runtime environment abstraction*.

**Mga Modyul:**
- `lndh_types` — mga *typdefs*, *enum*, konstant, at error codes (hal. `LNDH_OK`, `LNDH_FAIL`)  
- `lndh_utils` — mga katulong sa math, CRC, conversion, string ops  
- `lndh_eeprom` — persistent na imbakan ng kumpig  
- `lndh_serial` — base abstraction ng UART/USB logging   
- `lndh_config` — global configuration loader/saver

**Karaniwang Ginagamit ng:** *lahat ng yunit*

🧩 **Papel:**
- Lahat ng modyul ay **nakasalalay dito**.
- Walang ibang latag ang dapat gumamit ng *raw Arduino API* (hal. `Serial`, `EEPROM`, `millis()`) nang direkta, lahat ay daraan dito.

---

### ⏱ LATAG 1 — *Oras at Sabayan*
**Pamantayang sanggunian ng oras sa buong sistema.**

📘 **Layunin:**  
Pag-isahin ang *timekeeping*, *timestamping*, at *synchronization* ng lahat ng yunit.

**Mga Modyul:**
- `lndh_time` — virtual system clock na may adjustable drift correction 
- `lndh_rtc` — DS3231/DS1307 abstraction  
- `lndh_ntp` — synchronization sa WiFi network (NTP protocol)  
- `lndh_gps` — GNSS time source (UBlox/NEO modules) 
- `lndh_timestamp` — standardized struct (`year, sec, ms`)  

**Ginagamit ng:** Drone, Docking Base, GCS  
**Optional sa:** Remote Controller

🧩 **Papel:**
- Ginagamit ng `lndh_log`, `lndh_scheduler`, at `lndh_proto`.
- Maaaring gumamit ng *time hierarchy*: RTC > GPS > NTP > Internal clock.
- Drone at Dock ang pangunahing tagasalo ng tamang oras.

---

### 📡 Latag 2 — *Komunikasyon*
**Abstraksiyon ng lahat ng data link.**

📘 **Layunin:**   
Pag-isahin ang mga protokol sa RF, WiFi, at Serial upang magkaroon ng iisang *LNDH Packet Format*.

**Mga Modyul:**
- `lndh_link_rf` — driver para sa LoRa/NRF24/RF24
- `lndh_link_wifi` — WiFiClient/UDP/MQTT abstraction
- `lndh_link_serial` — para sa USB/UART pipe
- `lndh_proto` — pinagkaisang estruktura ng paketa `{pamuhatan, uri, lulan, tseksum}`

**Relasyon ng Mga Yunit:**
| Kawing | Daluyan | Tungkulin |
|---|---|---|
| Drone ↔ RC | RF | Telemetriya + Kontrol |
| Drone ↔ Dock | Serial / WiFi | Pagtatablay, sabayan |
| GCS ↔ RC/Dock | WiFi / MQTT | Atas at pagsusubaybay |

🧩 **Papel:**
- Ang bawat yunit ay may sariling *link topology*, ngunit parehong *estruktura ng paketa*.
- Lahat ng komunikasyon (telemetry, control, command) ay dumadaan dito.
- Nakaugnay sa `lndh_log` (telemetry output) at `lndh_ctrl` (command input).

---

### 🧭 LATAG 3 — *Sensor at P/L*
**Pisikal na ugnayan sa mundo.**

📘 **Layunin:**   
Magbigay ng modular abstraction sa hardware I/O (sensor, actuator, power).

**Mga Modyul:**
- `lndh_io` — general-purpose I/O map layer  
- `lndh_sensor_*` — hal. IMU, barometer, temperature, GNSS  
- `lndh_actuator` — motor driver, servo, relay 
- `lndh_power` — voltage/current/battery management 

**Ginagamit ng:** Drone, Docking Base  
**Opsiyonal sa:** RC (pasukang kontrolstik)  
**Minimal sa:** GCS (lohisil lamang)

🧩 **Papel:**
- Pangkilos ng Drone at Dock.
- Naka-interface sa `lndh_ctrl` para sa feedback at control loop.
- Maaaring i-disable o mock sa RC at GCS (simulation mode).

---

### 🧠 LATAG 4 — *Kontrol at Lohika*
**Puso ng operasyon ng bawat yunit.**

📘 **Layunin:**   
Magpatupad ng *state logic, control loops, at automation*.

**Mga Modyul:**
- `lndh_flight_ctrl` — PID stabilization, mission sequencing, navigation  
- `lndh_dock_ctrl` — automated docking routine, charging  
- `lndh_rc_ctrl` — joystick mapping, button handler  
- `lndh_gcs_ctrl` — mission planner, operator console logic, status orchestration 
- `lndh_scheduler` — cooperative multitasking system

**Ginagamit ng:** lahat, may kani-kaniyang espesyalisasyon.

🧩 **Papel:**
- Dito nag-uugnay ang input (sensor) at output (actuator) batay sa layunin.
- Maaaring gumamit ng *finite state machines (FSM)* para sa bawat mode.

---

### 📊 LATAG 5 — *Datos at Lilimbagan*
**Sistema ng pagtatala at pagsusubaybay.**

📘 **Layunin:**   
Magbigay ng estandardisadong paraan ng pag-log, pag-diagnose, at pag-iimbak.

**Mga Modyul:**
- `lndh_log` — syslog-style logging na may severity levels (0–7)
- `lndh_diag` — runtime metrics, uptime, reset cause, performance status
- `lndh_telemetry` — encoding/decoding ng telemetry packet 
- `lndh_storage` — SD/EEPROM/Flash-based data store  

**Ginagamit ng:** Drone, Docking Base, GCS  
**Opsiyonal sa:** Remote Controller

🧩 **Papel:**
- Pinagmumulan ng datos ng *GCS visualization*.
- Pinagkukunan ng *replay o flight diagnostics*.
- Gumagamit ng `lndh_time` at `lndh_proto` para sa consistent timestamped logs.

---

### 🧍 LATAG 6 — *Rabaw Tagagamit (UI)*
**Pakikipag-ugnayan ng tao at makina.**

📘 **Layunin:**
Magbigay ng human interface sa operator o developer.

**Mga Modyul:**
- `lndh_display` — TFT/OLED/CLI display abstraction  
- `lndh_ui` — hierarchical menu system / telemetry dashboard  
- `lndh_console` — serial/WiFi command line interface (CLI) 

**Ginagamit ng:** RC at GCS  
**Opsiyonal sa:** Drone, Docking Base (LED na panghiwatig)

🧩 **Papel:**
- Ang RC at GCS ang pangunahing tagagamit.
- Ang Drone at Dock ay may minimal interface (LED/signal indicators).
- Maaaring magamit para sa field debugging at configuration access.

---

## 🧭 Talahanayan ng Presensiya ng Latag

| Latag | Dron | Kontroler | Daungan | Kontrol sa Lupa |
|-------|:-----:|:-----------------:|:-------------:|:---:|
| Ubod / Batayang Sistema | ✅ | ✅ | ✅ | ✅ |
| Oras at Sabay | ✅ | ⚙️ | ✅ | ✅ |
| Komunikasyon | ✅ | ✅ | ✅ | ✅ |
| Sensor at P/L | ✅ | ✅ | ✅ | ⚙️ |
| Kontrol at Lohika | ✅ | ✅ | ✅ | ✅ |
| Datos at Lilimbagan | ✅ | ⚙️ | ✅ | ✅ |
| UI / Displey | ⚙️ | ✅ | ⚙️ | ✅ |

✅ = pangunahing bahagi  
⚙️ = opsiyonal o minimal  

---

## 📂 Estruktura ng Folder (Prototipo)

``` sh
/LNDH
├── core/
│   ├── lndh_types.h
│   ├── lndh_utils.c/h
│   ├── lndh_eeprom.c/h
│   └── lndh_serial.c/h
├── time/
│   ├── lndh_time.c/h
│   ├── lndh_rtc.c/h
│   └── lndh_ntp.c/h
├── comm/
│   ├── lndh_link_rf.c/h
│   ├── lndh_link_wifi.c/h
│   └── lndh_proto.c/h
├── io/
│   ├── lndh_sensor_xx.c/h
│   ├── lndh_actuator.c/h
│   └── lndh_power.c/h
├── control/
│   ├── lndh_scheduler.c/h
│   ├── lndh_flight_ctrl.c/h
│   ├── lndh_rc_ctrl.c/h
│   └── lndh_dock_ctrl.c/h
├── data/
│   ├── lndh_log.c/h
│   ├── lndh_diag.c/h
│   └── lndh_storage.c/h
└── ui/
    ├── lndh_display.c/h
    ├── lndh_ui.c/h
    └── lndh_console.c/h
```

---

## 🔗 Ugnayang Teknolohikal ng mga Latag

``` sh
[Latag 6: UI]
    │
[Latag 5: Lilimbagan]
    │
[Latag 4: Kontrol at Lohika]
    │
[Latag 3: Sensor at P/L]
    │
[Latag 2: Komunikasyon]
    │
[Latag 1: Oras at Sabay]
    │
[Latag 0: Ubod]
```

Ang daloy ng dependency ay **pababa**, habang ang inter-aksiyon ng runtime ay **pataas** (mula hardware papunta sa UI). Ang bawat latag ay may malinaw na API na hindi direktang tumatawid sa higit sa isang antas sa ibaba.

---

## 🧩 Mga Susunod na Hakbang
1. Tukuyin kung aling latag ang uunahing buoin (nakatakda: **Latag Ubod**).  
2. Gumawa ng minimal na hulmahan ng pamuhatan (`.h`) at batayang liligpit na C (`.c`).  
3. Magtakda ng estilo ng pagkokodigo at kumbensiyon ng pagpapangalan (`lndh_*`).  
4. Magturing ng karaniwang kodigo ng `LNDH_STATUS` at struct ng `LNDH_Config`.  
5. Magdagdag ng seksiyon ng talapalitan sa dulo ng dokumento.

---

## 📜 Talapalitan
- **v0.1 (2025-10-25):** Unang balangkas ng LNDH arkitektura ng latag.

---

> *Ang dokumento ay pinananatili sa ilalim ng LNDH Inisyatibo ng Pauswagan.*  
> *Ang lahat ng pagbabago ay dapat talakayin, ribyuhin, at bersiyonin nang naaayon.*
