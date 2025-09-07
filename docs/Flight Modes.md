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

### `0` Mga Tampok Pangkaligtasan

| # | Pangalan (Filipino) | Kodigo | Limitasyon / Kondisyon | Aksiyon | Saklaw |
|---|-------------------|------|-------------------------|---------|--------|
| 1 | Harang-Paandar <br> *(Motor Lockout)* | `HRNG` | Lahat ng propeller at actuator ay naka-disable habang nasa Tamlay | Walang output hanggang may explicit arming command | Propulsion at control surface actuators |
| 2 | Ligtas Balanseng Bigat <br> *(Fail-safe Ballast Logic)* | `LTBB` | Panatilihing neutral o bahagyang mas-mabigat-kaysa-hangin | Pigilan ang hindi sinasadyang pag-angat ng sasakyan | Ballast system |
| 3 | Suring Pagsisimula <br> *(Pre-flight System Check)* | `SURI` | Kailangang maayos ang lahat ng sensor at subsystem bago ang arming | Awtomatikong harangan ang arming kung may kulang o error | Battery, GNSS, IMU, comms, pump/valve |
| 4 | Bantay Lipat Moda <br> *(Mode Transition Guard)* | `BTLM` | Kinakailangan ng deliberate na 2-step confirmation | Pinipigilan ang aksidenteng paglipat mula Tamlay patungo sa M+25, APL, o AOL | Flight mode logic |
| 5 | Tala Simula <br> *(Logging)* | `TALA` | Lahat ng initialization at pre-flight checks | Awtomatikong itinatala para sa maintenance at analysis | System logs at storage |

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

| #  | Pangalan sa Filipino | Kodigo | Limitasyon / Kondisyon | Aksiyon | Saklaw |
|----|----------------------|--------|-------------------------|---------|--------|
| 1  | Hanggambilis <br> *(Speed Limiter)* | `BLIS` | Max 2.5 m/s airspeed | I-saturate ang utos ng operator kung lalampas | Flight control, propulsion |
| 2  | Tugatog ng Tulok <br> *(Throttle/Thrust Cap)* | `TLOK` | 30–40% max continuous thrust | Pigilan ang surge sa motor at propellers | Propulsion system |
| 3  | Proteksiyon sa Altitud <br> *(Altitude Protection)* | `TAAS` | Ceiling: +30 m mula takeoff point <br> Vertical rate: ±0.25–0.5 m/s | Auto-hold kapag lumapit sa ceiling | Altitude control |
| 4  | Hanggantikwas <br> *(Tilt Limit)* | `TKWS` | Max ±10–15° pitch/roll | Override ang utos kung lumampas | Attitude control |
| 5  | Bakodhangin <br> *(Geofence)* | `BKOD` | Soft boundary: warning + slowdown <br> Hard boundary: >10 s breach | Auto-RTL kung lumampas | Navigation, flight boundary |
| 6  | Bantay Koryente <br> *(Power Safeguards)* | `BKYT` | 30%: warning <br> 20%: auto-loiter <br> 10%: forced RTL o descent | Multi-level battery failsafe | Power management, propulsion |
| 7  | Proteksiyon sa Kawalan ng Telemetriya <br> *(RC/Telemetry Loss Protection)* | `PSKT` | Short loss: 2–5 s <br> Sustained loss: 20–30 s | Auto-loiter (short), Auto-RTL o descent (long) | Comms, navigation |
| 8  | Alerto sa Kalapitan <br> *(Proximity Alert)* | `LPIT` | <1.5 m obstacle detected | Alert + auto-stop | Proximity sensors, navigation |
| 9  | Bantay Ballonet at Presyon <br> *(Ballonet & Pressure Safeguard)* | `BBAP` | Rate limit sa buoyancy changes | Auto-close valves kung may fault | Buoyancy, ballonet system |
| 10 | Hinto Pangkagipitan <br> *(Emergency Stop)* | `HKAG` | Kill switch (HW/SW) engaged | Block throttle, shutdown propulsion | Propulsion, system interlock |
| 11 | Proteksiyon sa Paglipat ng Moda <br> *(Mode Transition Protection)* | `PSLM` | Kinakailangan ang deliberate action | Visual + audible confirmation bago lipat | Flight mode logic |
| 12 | Talalimbagan at Telemetriya <br> *(Logging & Telemetry)* | `TALA` | Log ng inputs, states, alerts, safety events | Store onboard + uplink sa GCS | Logging system, comms |
| 13 | Paunang Suri ng Kalusugan <br> *(Pre-flight Health Check)* | `SURI` | Kinakailangan: battery, GNSS, IMU, pump/valve, comms | I-block ang arming kung may error | System health, sensors |

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
