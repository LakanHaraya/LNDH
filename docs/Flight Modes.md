# Mga Moda ng Lipad (`moLIPAD`)

Flight Modes

## `moLIPAD 0` Tamlay


## `moLIPAD 1` M+25 — Moda ng Manwal Mabagal

### Paglalarawan

Ang M+25 ay ang *Moda ng Manwal Mabagal* ng LundayHangin (LNDH).

* Idinisenyo ito para sa **pagsasanay, tumpak na pagmamaniobra, at operasyong mababa ang panganib**.
* Nakapaloob dito ang **limitasyon ng bilis na 2.5 m/s** (≈ 9.0 km/h), na sapat para sa kontroladong paglipad habang nagbibigay pa rin ng sapat na pagtugon.
* Layunin nitong bigyan ng kalayaan ang opereytor na magpatakbo ng sasakyan, habang may kasabay na mga **awtomatikong proteksiyon** laban sa mga panganib ng labis na bilis, taas, at koryente.

### Layunin

* Magbigay ng ligtas na kapaligiran para sa **unang pagsasanay** ng opereytor.
* Pahintulutan ang **tumpak na pagmamaniobra** tulad ng pagdaong o inspeksiyon sa mababang-altitud.
* Panatilihin ang **modular na arkitektura** kung saan puwedeng ikumpigura ang mga limitasyon ayon sa disenyo ng yunit at kondisyon ng kapaligiran.

### Pangunahing Katangian

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

### Mga Tampok Pangkaligtasan

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

### Mga Rekomendadong Nakatakdang Halaga

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

### Operasyonal na Paalala

* **Rekomendadong Kapaligiran:** Kalmadong panahon (≤ 3 m/s hangin).

* **Gampanin ng Opereytor:** Dapat ay nagsasanay, nagsusubok, o nagsasagawa ng tumpak na gawain.

* **Paghihigpit:** Hindi dapat gamitin ang M+25 sa malayuang paglalakbay o kapaligiran na malakas ang hangin.

* **Pagkakalatag:** Ang mga limitasyon ng M+25 ay nakapaloob sa mismong moda ng lipad,
habang ang APL (Awtomatikong Proteksiyon ng LNDH) ay nakalapat bilang mas malawak na proteksiyon na umiiral sa ibabaw ng lahat ng moda (maliban sa Espesyal).

