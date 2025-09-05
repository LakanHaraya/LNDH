# Mga Moda ng Lipad (`moLIPAD`)

Flight Modes

## `moLIPAD 0` Tamlay — Walang Moda

### `0` Paglalarawan

Ang **Tamlay** ay ang panimulang estado ng LundayHangin (LNDH) kapag hindi pa nakabitbit at wala pang napiling moda ng lipad.

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

* **Motor lockout** — walang propeller o actuator ang gagalaw hanggang may explicit arming command.
* **Fail-safe ballast logic** — panatilihing neutral o bahagyang mas-mabigat-kaysa-hangin para hindi basta lumipad pataas.
* **Pre-flight system check**
    * Battery voltage
    * GNSS lock status
    * IMU at sensor calibration
    * Comms health (MK ↔ PS, HL ↔ PS)
    * Pump/valve responsiveness
* **Mode transition guard** — kinakailangan ng deliberate na utos para lumipat mula Tamlay patungong M+25, APL, o AOL.
* **Logging** — lahat ng initialization at pre-flight checks ay awtomatikong naitatala para sa maintenance at analysis.

### `0` Mga Rekomendadong Nakatakdang Halaga

| Parametro             | Nakatakdang Halaga                       |
| ---------------------- | -------------------------------------- |
| Motor status           | Locked (no output)                     |
| Ballast state          | Neutral to slightly negative buoyancy  |
| GNSS lock requirement  | ≥ 6 satellites (3D fix)                |
| IMU calibration        | Mandatory before arming                |
| Comms check            | MK + HL link both active               |
| Battery minimum        | ≥ 80% capacity bago payagan ang flight |
| Transition requirement | 2-step confirmation sa MK at HL        |

### `0` Operasyonal na Paalala

* Ang **Tamlay** ang nakatakdang moda pagkatapos ng pagkabuhay ng koryente at tuwing hindi pa nakabibit ang LNDH.
* Lahat ng aktibong paghahanda (kalibrasyon, lipadpaunang surian, kaayusang kom) ay isinasagawa sa estado na ito.
* **Hindi dapat laktawan** ang Tamlay; ito ang pangunahing garantiya laban sa hindi sinasadyang takeoff.
* Pagkatapos makompleto ang lahat ng pagsusuri sa kalusugan at kahandaan ng sistema, maaaring lumipat ang opereytor mula **Tamlay → M+25** (para sa manwal na pagsasanay) o direkta sa ibang moda ng lipad depende sa operasyon.

---

## `moLIPAD 1` M+25 — Moda ng Manwal Mabagal

### `1` Paglalarawan

Ang M+25 ay ang *Moda ng Manwal Mabagal* ng LundayHangin (LNDH).

* Idinisenyo ito para sa **pagsasanay, tumpak na pagmamaniobra, at operasyong mababa ang panganib**.
* Nakapaloob dito ang **limitasyon ng bilis na 2.5 m/s** (≈ 9.0 km/h), na sapat para sa kontroladong paglipad habang nagbibigay pa rin ng sapat na pagtugon.
* Layunin nitong bigyan ng kalayaan ang opereytor na magpatakbo ng sasakyan, habang may kasabay na mga **awtomatikong proteksiyon** laban sa mga panganib ng labis na bilis, taas, at koryente.

### `1` Layunin

* Magbigay ng ligtas na kapaligiran para sa **unang pagsasanay** ng opereytor.
* Pahintulutan ang **tumpak na pagmamaniobra** tulad ng pagdaong o inspeksiyon sa mababang-altitud.
* Panatilihin ang **modular na arkitektura** kung saan puwedeng ikumpigura ang mga limitasyon ayon sa disenyo ng yunit at kondisyon ng kapaligiran.

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

1. **Speed Limiter** *(Hanggambilis)* `BLIS`
    * **Limitasyon:** 2.5 m/s airspeed cap.
    * **Aksiyon:** i-saturate ang utos ng operator kung lalampas.

2. **Throttle / Thrust Cap** *(Tugatog ng Tulok)* `TLOK`
    * **Limitasyon:** 30–40% max continuous output.
    * **Aksiyon:** pigilan ang biglaang surge sa motor at propellers.

3. **Altitude Protection** *(Proteksiyon sa Altitud)* `TAAS`
    * **Ceiling:** default +30 m mula sa takeoff point.
    * **Vertical rate:** ±0.25–0.5 m/s.
    * **Aksiyon:** auto-hold kapag lumapit sa ceiling.

4. **Tilt Limit** *(Hanggantikwas)* `TWAS`
    * **Limitasyon:** max ±10–15° pitch/roll.
    * **Aksiyon:** override ang utos kung lumampas.

5. **Geofence** *(Bakodhangin)* `BKOD`
    * **Soft boundary:** magbigay ng babala at unti-unting slowdown.
    * **Hard boundary:** auto-RTL kung lumampas >10 s.

6. **Power Safeguards** *(Sanggalan ng Koryente)* `SKOR`
    * **Babala:** 30% battery capacity.
    * **Aksiyon:** auto-loiter sa 20%.
    * **Critical:** forced RTL o descent sa 10%.

7. **RC/Telemetry Loss Protection** *(Proteksiyon sa Kawalan ng Telemetriya)* `WTEL`
    * **Short loss (2–5 s):** auto-loiter.
    * **Sustained loss (20–30 s):** auto-RTL o controlled descent.

8. **Proximity Alert** *(Alerto sa Kalapitan)* `LPIT`
    * **Sensor:** ultrasonic / LiDAR-lite.
    * **Aksiyon:** alert + auto-stop kapag <1.5 m.

9. **Ballonet & Pressure Safeguard** *(Sanggalan ng Ballonet at Presyon)* `BNET`
    * **Aksiyon:** rate limit sa buoyancy changes, auto-close valves kung may fault.

10. **Emergency Stop** *(Hinto Pangkagipitan)* `HKAG`
    * **Opsiyon:** hardware kill switch + remote kill.
    * **Proteksiyon:** software interlock na i-block ang throttle kapag naka-engage.

11. **Mode Transition Protection** *(Proteksiyon sa Paglipat ng Moda)* `LPTM`
    * **Requirement:** deliberate action bago pumasok/umalis sa M+25.
    * **Aksiyon:** visual + audible confirmation.

12. **Logging & Telemetry** *(Talalimbagan at Telemetriya)* `TALA`
    * **Nilalaman:** inputs, states, alerts, safety events.
    * **Medium:** onboard SD + uplink sa Ground Control Station (HL).

13. **Pre-flight Health Check** *(Lipadpaunang Surian ng Kalusugan)* `SURI`
    * **Kinakailangan:** battery, GNSS, IMU, pump/valve, comms.
    * **Aksiyon:** i-block ang arming kung hindi pumasa.

### `1` Mga Rekomendadong Nakatakdang Halaga

| Parametro        | Nakatakdang Halaga         |
| ---------------- | --------------------- |
| Max Airspeed     | 2.5 m/s               |
| Throttle Cap     | 30–40%                |
| Altitude Ceiling | +30 m                 |
| Climb/Descent    | ±0.25–0.5 m/s         |
| Max Tilt     | ±10–15°               |
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

