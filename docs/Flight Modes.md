# Mga Moda ng Lipad (`moLIPAD`)

Flight Modes

## `moLIPAD 0` Tamlay — Moda ng Antabay

### `0` Paglalarawan

Ang **Tamlay** ay ang panimulang estado ng LundayHangin (LNDH) kapag hindi pa naka-arm at wala pang napiling moda ng lipad.

* Nagsisilbi itong **ligtas na kondisyon ng pagtigil** habang nakabukas ang sistema.
* Ang pangunahing layunin nito ay panatilihin ang sasakyan sa **matatag at hindi aktibong estado** hanggang pumili ang opereytor ng naaangkop na moda ng lipad.
* Hindi ito itinuturing na “paglipad,” kundi **paghahanda at pag-antabay** lamang.

### `0` Layunin

* Maging ligtas na **nakatakdang moda** pagkatapos ng pagbuhay ng koryente.
* Magbigay ng oras para sa **inisyalisasyon ng sistema** (kalibrasyon ng sensor, pagsuri ng komunikasyon, estado ng lastre).
* Harangin ang anumang hindi sinasadyang utos ng motor o propeller habang hindi pa handa.
* Ihanda ang opereytor para sa **manwal o awtomatikong paglipad** sa susunod na moda.

### `0` Pangunahing Katangian

* **Walang thrust o flight control output** maliban sa basic stabilization kung kinakailangan (hal., panatilihin ang neutral ballast).
* **Pinagana ang lahat ng sensor at komunikasyon** (GNSS, IMU, telemetry, RC link).
* **Health monitoring active** — battery, pump/valve, comms, at iba pang critical subsystems.
* **Geofence at safety features naka-arm sa background** pero walang aktibong flight restriction (sapagkat wala pang paglipad).
* **Operator prompt:** malinaw na indikasyon sa MK at HL na nasa moda *Tamlay* ang sasakyan.

### `0` Mga Kinakailangang Kakayahan
  
> **Kailangan:** `HRNG`, `SURI`, `MODA`, `TALA`  
> **Opsiyonal/Kondisyonal:** `BGAT` (kung may ballast system) 
 
#### **Core Safety Interlocks**

1. `HRNG` **Motor Lockout**
    
    * **Kailangan**

    * *Ang sistema ay dapat* magpanatiling naka-lock ang lahat ng motor at actuator habang nasa Moda 0.

2. `BGAT` **Fail-safe Ballast**

    * **Opsiyonal / Kondisyonal** (kung may ballast subsystem)

    * *Ang sistema ay dapat* magpanatili ng kaunting "mas-mabigat-sa-hangin" na kondisyon sa pamamagitan ng ballast upang maiwasan ang kusang pag-angat.

#### **System Integrity**

3. `SURI` **Pre-flight System Check**

    * **Kailangan**

    * *Ang sistema ay dapat* magsagawa ng paunang awtomatikong pagsusuri ng istatus ng sensor, komunikasyon, koryente, GNSS, IMU, pump/valve, at iba pa bago lumipat mula Moda 0.

4. `MODA` **Mode Transition Protection** 

    * **Kailangan**

    * *Ang sistema ay dapat* pigilan ang paglipat sa mas mataas na moda kung may nakitang fault o kulang na kondisyon (hal. kulang sa telemetriya, koryente, o GPS lock).

#### **Logging & Traceability**

5. `TALA` Logging and Telemetry 

    * **Kailangan**

    * *Ang sistema ay dapat* magtala ng lahat ng pangyayari, diyagnostikong istatus, at resulta ng pre-flight check habang nasa Moda 0.

---

### `0` Mga Rekomendadong Nakatakdang Halaga

| Parametro              | Nakatakdang Halaga                     |
| ---------------------- | -------------------------------------- |
| Motor status           | Locked (no output)                     |
| Ballast state          | Neutral to slightly negative buoyancy  |
| GNSS lock requirement  | ≥ 6 satellites (3D fix)                |
| IMU calibration        | Mandatory before arming                |
| Comms check            | MK + HL link both active               |
| Battery minimum        | ≥ 80% capacity bago payagan ang flight |
| Transition requirement | 2-step confirmation sa MK at HL        |

### `0` Operasyonal na Paalala

* Ang **Tamlay** ang nakatakdang moda pagkatapos ng pagkabuhay ng koryente at tuwing hindi pa naka-arm ang LNDH.
* Lahat ng aktibong paghahanda (kalibrasyon, lipadpaunang surian, kaayusang kom) ay isinasagawa sa estado na ito.
* **Hindi dapat laktawan** ang Tamlay; ito ang pangunahing garantiya laban sa hindi sinasadyang takeoff.
* Pagkatapos makompleto ang lahat ng pagsusuri sa kalusugan at kahandaan ng sistema, maaaring lumipat ang opereytor mula **Tamlay → M+25** (para sa manwal na pagsasanay) o direkta sa ibang moda ng lipad depende sa operasyon.

---

## `moLIPAD 1` M+25 — Moda ng Manwal Mabagal

### `1` Paglalarawan

Ang M+25 ay ang *Moda ng Manwal Mabagal* ng LundayHangin (LNDH).

* Idinisenyo ito para sa **pagsasanay, tumpak na pagmamaniobra, at operasyong mababa ang panganib**.
* Nakapaloob dito ang **limitasyon ng bilis na 2.5 m/s** (≈ 9.0 km/h), sapat upang mapanatili ang ligtas ngunit tumutugong opersyon.
* Ang moda na ito at nakatuon sa *responsiveness* at *kontroladong galaw* kaysa sa bilis.
* Bagamat ang M+25 ay may sariling limitasyon, ang **APL (Awtomatikong Proteksiyon ng LNDH)** ay nananatiling aktibong nakalapat bilang mas mataas na proteksiyon laban sa labis na utos o mapanganib na kondisyon.

### `1` Layunin

* Magbigay ng ligtas na kapaligiran para sa **unang pagsasanay** ng opereytor.
* Payagan ang **tumpak na pagmamaniobra** tulad ng pagdaong, paglapit sa lupa, o inspeksiyon sa mababang-altitud.
* Panatilihin ang **modular na arkitektura** kung saan maaaring iakma ang mga limitasyon depende sa disenyo ng yunit at kondisyonng kapaligiran.
* Maglingkod bilang **transisyonal na hakbang** bago pumunta sa mas mataas na antas ng awtomasyon (APL at AOL).

### `1` Pangunahing Katangian

* **Responsive low-speed flight** — max airspeed limit: **2.5 m/s**.
* **Throttle soft-cap**: max 30–40% thrust output.
* **Altitude ceiling**: default +30 m mula sa takeoff point.
* **Climb/Descent rate cap**: ±0.25–0.5 m/s.
* **Tilt limit**: max ±10–15° pitch/roll.
* **Geofence protection**: may soft at hard boundaries.
* **Battery safeguard**: multi-level na babala at aksiyon.
* **RC/telemetry loss handling**: auto-loiter, auto-RTL kung matagal ang pagkawala.
* **Basic proximity awareness**: auto-stop o alert kapag may bagay <1.5 m.
* **Logging at telemetry**: lahat ng aksiyon at babala ay naka-log para sa pagsusuri.

### `1` Mga Tampok Pangkaligtasan

#### **Pangunahing Paggalaw at Limitasyon**

1. `BLIS` **Speed Limiter**
    <!-- Bilis -->

    * **Kailangan**

    * *Ang sistema ay dapat* limitahan ang forward airspeed hanggang **2.5 m/s** kapag nasa Moda 1.

2. `TLOK` **Throttle / Thrust Cap**
    <!-- Tulok -->

    * **Kailangan**
    
    * *Ang sistema ay dapat* ipatupad ang throttle soft-cap na **30–40%** ng rated continuous thrust upang pigilan ang biglaang surge.

3. `AKYT` **Climb / Descent and Altitude Ceiling**
    <!-- Akyat -->

    * **Kailangan**

    * *Ang sistema ay dapat* limitahan ang climb/descent rate sa **±0.25–0.5 m/s** at pigilan ang pag-akyat lmapas sa **+30 m** mula sa takeoff point.

4. `TKWS` **Tilt / Attitude Limit**
    <!-- Tikwas -->

    * **Kailangan**

    * *Ang sistema ay dapat* pigilan ang pitch/roll na lumagpas ng **±10–15°** sa Moda 1 (override o kinokorek ang operator input).

#### **Safety Layers & Protection**

5. `LBAG` **APL Overlay Behavior**
    <!-- Labag -->

    * **Kailangan**

    * *Ang sistema ay dapat* payagan ang APL (global protection layer) na magmonitor at mag-intervene sa Moda 1 para pigilan ang mga aksiyon na labag sa safety rules (e.g., paglabag sa geofence, kritikal na baterya).

6. `BKOD` **Geofence**
    <!-- Bakodhangin -->

    * **Kailangan**

    * *Ang sistema ay dapat* magpatupad ng soft geofence warnings at hard fence action (auto-loiter o RTL) kapag lumagpas sa itinakdang limit.

7. `KYNT` **Power Safeguards**
    <!-- Koryente -->

    * **Kailangan**

    * *Ang sistema ay dapat* magbigay ng multi-level battery warnings (30% warning, 20% auto-loiter, 10% forced RTL/descent) at isagawa ang kaukulang aksiyon.

8. `HKAG` **Emergency Stop**
    <!-- Hinto Pangkagipitan -->

    * **Kailangan**

    * *Ang sistema ay dapat* tanggapin ang hardware/software kill input at agarang i-block ang propulsion at actuator outputs.

#### **Komunikasyon at Handling ng Pagkawala ng Link**

9. `WTEL` **RC/Telemetry Loss Policy**
    <!-- Walang Telemetriya -->

    * **Kailangan**

    * *Ang sistema ay dapat* mag-loiter sa maikling pagkawala ng link (2–5 s) at mag-execute ng auto-RTL o controlled descent sa sustained loss (20–30 s), alinsunod sa kumpigurasyon.

10. `KOMU` **Comms Integrity Monitor**
    <!-- Komunikasyon -->

    * **Opsiyonal / Rekomendado**

    * *Ang sistema ay dapat* magmonitor ng packet loss at latency at makabuo ng alert / degradations mode bago umabot sa full loss.

#### **Obstacle at Ballonet Protections**

11. `LPIT` **Proximity Alert**
    <!-- Lapit -->

    * **Kailangan** (para sa precision/docking role)

    * *Ang sistema ay dapat* mag-alert at ipatupad ang auto-stop ng forward command kapag nakita ang obstacle sa loob ng **<1.5 m**.

12. `BBAP` **Ballonet & Pressure Safeguard**
    <!-- Bantay Ballonet at Presyon -->

    * **Kondisyonal** (Kailangan kung may ballonet subsystem)

    * *Ang sistema ay dapat* limitahan ang bilis ng pagbabago ng ballonet volume at isara ang valves kapag nakitang may abnormal pressure/flow.

#### **Mga Pangangasiwa ng Sistema at Traceability**

13. `SURI` **Pre-flight System Check** 

    * **Kailangan**

    * *Ang sistema ay dapat* magsagawa ng paunang awtomatikong pagsusuri (hal., istatus ng sensor, komunikasyon, koryente, GNSS, IMU, pump/valve, at iba pa) at harangan ang arming kung may error.

14. `TALA` **Logging & Telemetry**
    <!-- Talaan -->

    * **Kailangan**

    * *Ang sistema ay dapat* mag-log ng operator inputs, controller states, safety events, at mga alert na may timestamps at i-uplink / store on board.

15. `MODA` **Mode Transition Protection**

    * **Kailangan**

    * *Ang sistema ay dapat* humingi ng deliberate confirmation bago lumipat papunta o palabas ng Moda 1; i-log lahat ng transitions.

#### **Diagnostics at Runtime Helath**

16. `PNTS` **Sensor Fault Isolation**
    <!-- Pintas -->

    * **Opsiyonal / Rekomendado**

    * *Ang sistema ay dapat* mag-detect ng sensor faults o drift (IMU/GNSS/baro) at mag-switch sa fallback sensor o i-degrade ang mode kung kinakailangan.

17. `INIT` **Thermal Safeguards**

    * **Opsiyonal / Rekomendado** 
    
    * *Ang sistema ay dapat* mag-monitor ng temperature ng battery at motors at mag-degrade ng power o ipatupad ang cooldown policy kapag umabot sa threshold.

#### **Testability & Configuration**

18. `TEST` **Configurability & Test Modes**

    * **Kailangan** 

    * *Ang sistema ay dapat* magbigay ng mga configuration parameters (speed cap, throttle cap, geofence radius, timeout values) at test modes (bench / tether / ground test) para sa safe verification ng mga FR sa field.

19. `LGTS` **Fail-safe Priority**
    <!-- Ligtas -->

    * **Kailangan**

    * *Ang sistema ay dapat* tiyakin na ang APL safety interventions ay may mas mataas na priority kaysa sa operator inputs para sa critical events (bateryang kritikal, hard geofence breach, emergency stop).

---

### `1` Mga Rekomendadong Nakatakdang Halaga

| Parametro        | Nakatakdang Halaga    |
| ---------------- | --------------------- |
| Max Airspeed     | 2.5 m/s               |
| Throttle Cap     | 30–40%                |
| Altitude Ceiling | +30 m                 |
| Climb/Descent    | ±0.25–0.5 m/s         |
| Max Tilt         | ±10–15°               |
| Geofence Warning | 10 m before boundary  |
| Geofence Action  | RTL after 10 s beyond |
| Battery Warning  | 30%                   |
| Battery Action   | 20% auto-loiter       |
| Battery Critical | 10% RTL/descent       |
| RC Loss → Loiter | 2–5 s                 |
| RC Loss → RTL    | 20–30 s               |
| Proximity Stop   | <1.5 m                |
| Max Wind (ops)   | ≤ 3 m/s               |

### `1` Operasyonal na Paalala

* **Rekomendadong Kapaligiran:** Kalmadong panahon (≤ 3 m/s hangin).

* **Gampanin ng Opereytor:** Dapat ay nagsasanay, nagsusubok, o nagsasagawa ng tumpak na gawain.

* **Paghihigpit:** Hindi dapat gamitin ang M+25 sa malayuang paglalakbay o kapaligiran na malakas ang hangin.

* **Pagkakalatag:** Ang mga limitasyon ng M+25 ay nakapaloob sa mismong moda ng lipad,
habang ang APL (Awtomatikong Proteksiyon ng LNDH) ay nakalapat bilang mas malawak na proteksiyon na umiiral sa ibabaw ng lahat ng moda (maliban sa Espesyal).

---

## `moLIPAD 2` APL — Awtomatikong Proteksiyon ng LNDH

### `2` Paglalarawan
* Ang **APL** ay ang *Awtomatikong Proteksiyon ng LundayHangin (LNDH)*.  
* Idinisenyo ito upang magsilbing **aktibong bantay at tagapagpatupad ng mga limitasyon** na higit sa kontrol ng opereytor.  
* Kapag lumampas ang utos o kondisyon sa ligtas na saklaw, awtomatikong pumapasok ang APL upang ikorek, maglimita, o pigilan ang aksiyon.  

### `2` Layunin
* Panatilihin ang **integridad at kaligtasan** ng sasakyan kahit na may maling utos o hindi inaasahang kondisyon.
* Magbigay ng **redundant safety net** para sa lahat ng mababang at mid-level na moda (Moda 0 at Moda 1).
* Payagan ang **semi-awtonomong paglipad** na hindi umaasa sa perpektong input ng tao.
* Ihanda ang sistema para sa **buong awtonomiyang operasyon** (AOL).

### `2` Pangunahing Katangian
* **Multi-axis flight envelope protection** (speed, altitude, tilt, geofence).
* **Energy management**: proteksiyon sa baterya at koryente.
* **Communication resilience**: auto-loiter / auto-RTL sa pagkawala ng link.
* **Environment awareness**: geofence, proximity sensing, ballonet pressure safeguards.
* **Fail-safe transitions**: ligtas na pagbabalik mula sa anumang maling utos.
* **Data integrity**: patuloy na logging at uplink telemetry.
* **Operator assist**: visual at audio alerts para sa real-time feedback.

### `2` Mga Tampok Pangkaligtasan
| #  | Pangalan sa Filipino | Kodigo | Limitasyon / Kondisyon | Aksiyon | Saklaw |
|----|----------------------|--------|-------------------------|---------|--------|
| 1  | Hanggambilis <br> *(Speed Limiter)* | `BLIS` | Max 5.0 m/s (configurable) | Saturation ng utos, auto-slowdown | Flight control, propulsion |
| 2  | Tugatog ng Tulok <br> *(Throttle/Thrust Cap)* | `TLOK` | 60–70% thrust output limit | Pigilan ang surge, i-manage power draw | Propulsion system |
| 3  | Proteksiyon sa Altitud <br> *(Altitude Protection)* | `TAAS` | Default ceiling: +100 m mula takeoff <br> Max climb/descent rate: ±1 m/s | Auto-hold, gradual descent kung lampas | Altitude control |
| 4  | Hanggantikwas <br> *(Tilt Limit)* | `TKWS` | ±20–25° pitch/roll | Override kung lalampas | Attitude control |
| 5  | Bakodhangin <br> *(Geofence)* | `BKOD` | Configurable radius (e.g. 200 m) | Soft: babala + slowdown <br> Hard: auto-RTL | Navigation |
| 6  | Bantay Koryente <br> *(Power Safeguards)* | `BKYT` | 30%: babala <br> 20%: auto-loiter <br> 10%: forced RTL/landing | Energy failsafe sequence | Power management |
| 7  | Proteksiyon sa Kawalan ng Telemetriya <br> *(Telemetry Loss Protection)* | `PSKT` | Short: 5 s <br> Long: 30 s | Auto-loiter / Auto-RTL | Comms, navigation |
| 8  | Alerto sa Kalapitan <br> *(Proximity Alert)* | `LPIT` | Object detected <2 m | Alert + auto-brake/hover | Sensors, navigation |
| 9  | Bantay Ballonet-Presyon <br> *(Ballonet & Pressure Safeguard)* | `BBAP` | Abnormal pressure/flow rate | Auto-valve close, restrict buoyancy change | Ballonet system |
| 10 | Hinto Pangkagipitan <br> *(Emergency Stop)* | `HKAG` | Manual kill engaged | Shutdown propulsion | Propulsion, interlocks |
| 11 | Proteksiyon sa Paglipat ng Moda <br> *(Mode Transition Protection)* | `LPTM` | Kinakailangan ng deliberate sequence | Confirmation prompt | Mode logic |
| 12 | Talalimbagan at Telemetriya <br> *(Logging & Telemetry)* | `TALA` | Inputs, states, alerts | Store + uplink | Logging, GCS |
| 13 | Lipadpaunang Surian ng Kalusugan <br> *(Pre-flight Health Check)* | `SURI` | GNSS, IMU, comms, power | Block arming kung may fault | System health |

### `2` Mga Rekomendadong Nakatakdang Halaga
* **Max Airspeed:** 5.0 m/s  
* **Throttle Cap:** 60–70%  
* **Altitude Ceiling:** +100 m mula sa takeoff point  
* **Climb/Descent Rate:** ±1.0 m/s  
* **Tilt Limit:** ±20–25°  
* **Geofence Radius:** default 200 m (configurable)  
* **Battery Thresholds:** 30% / 20% / 10% (warning/loiter/RTL-landing)  
* **Telemetry Loss Windows:** 5 s (short), 30 s (long)  
* **Proximity Alert Range:** 2.0 m  

### `2` Operasyonal na Paalala
* Laging suriin na **nakapasa sa health check (`SURI`)** bago arming.  
* Siguraduhin na ang **geofence (`BKOD`) ay naka-configure ayon sa aktwal na lugar ng operasyon**.  
* Gumamit ng **redundant power monitoring** upang hindi mabigla sa **`BKYT`** trigger.  
* Ang **proximity sensing** ay kailangang iakma depende sa operasyon (indoor vs outdoor).  
* Ang lahat ng alerto at aksiyon ng APL ay **hindi maaaring laktawan ng opereytor** maliban kung nasa *maintenance override mode*.  


---

### Master Safety Features v2 (Moda 0–2)

| Family | Kodigo | Tungkulin | Saklaw | Moda 0 | Moda 1 | Moda 2 | Notes/Config |
|--------|--------|-----------|--------|--------|--------|--------|--------------|
| **Universal Core** |||||  
|        | `HRNG` | Harang-Paandar <br>*Motor Lockout* | Propulsion, actuators | ✔ | – | – | Default lock sa Tamlay |
|        | `LTBB` | Ligtas Balanseng Bigat <br>*Fail-safe Ballast* | Ballast system | ✔ | – | – | Keep slightly heavier-than-air |
|        | `SURI` | Paunang Suri <br>*Pre-/Post-flight Check* | System health | ✔ | ✔ | ✔ | Battery, GNSS, IMU, comms, pumps |
|        | `MODA` | Bantay Lipat Moda <br>*Mode Transition Guard* | Mode logic | ✔ | ✔ | ✔ | Nag-iiba ng paraan per mode |
|        | `TALA` | Talalimbagan <br>*Logging & Telemetry* | Logs, comms | ✔ | ✔ | ✔ | Store onboard + uplink |
|        | `HKAG` | Hinto Pangkagipitan <br>*Emergency Stop* | Propulsion, interlocks | – | ✔ | ✔ | Kill switch/manual stop |
| **Energy Management** |||||  
|        | `BLIS` | Hanggambilis <br>*Speed Limiter* | Flight control | – | ✔ (≤2.5 m/s) | ✔ (≤5.0 m/s) | Configurable per mode |
|        | `TLOK` | Tugatog ng Tulok <br>*Throttle Cap* | Propulsion | – | ✔ (30–40%) | ✔ (60–70%) | Power draw limiter |
|        | `KYNT` | Bantay Koryente <br>*Power Safeguards* | Power mgmt | – | ✔ (30/20/10%) | ✔ (30/20/10%) | Tiered failsafe actions |
|        | `THTR` | Bantay Init <br>*Thermal Safeguard* | Battery, propulsion | – | – | – | Prevent overheating |
| **Flight Envelope & Navigation** |||||  
|        | `TAAS` | Proteksiyon sa Altitud | Altitude control | – | ✔ (+30 m, ±0.5 m/s) | ✔ (+100 m, ±1 m/s) | Ceiling per mode |
|        | `TKWS` | Hanggantikwas <br>*Tilt Limit* | Attitude control | – | ✔ (±10–15°) | ✔ (±20–25°) | Envelope protection |
|        | `BKOD` | Bakodhangin <br>*Geofence* | Navigation | – | ✔ (soft/hard) | ✔ (configurable) | Auto-RTL on breach |
|        | `LPIT` | Alerto sa Kalapitan <br>*Proximity Alert* | Sensors | – | ✔ (<1.5 m) | ✔ (<2 m) | Obstacle avoidance |
| **Comms & Sensing** |||||  
|        | `WTEL` | Proteksiyon sa Telemetriya <br>*Link Loss* | Comms, nav | – | ✔ (2–5s / 20–30s) | ✔ (5s / 30s) | Auto-loiter / RTL |
|        | `IKOM` | Bantay Integridad Komunikasyon <br>*Comms Integrity Monitor* | Comms | – | – | – | Packet loss/latency monitor |
|        | `SIRA` | Pag-iwas sa Sira <br>*Sensor Fault Isolation* | IMU, GNSS, sensors | – | – | – | Detect & isolate faulty sensors |
| **Buoyancy & Payload** |||||  
|        | `BBAP` | Bantay Ballonet-Presyon | Ballonet system | – | ✔ | ✔ | Auto-valve close, rate limiter |
