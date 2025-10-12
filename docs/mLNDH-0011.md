## *mLNDH-0011*

# 🧭 Pinagkaisang Balangkas sa Pagtatala ng Oras
*(Pangunahing Sasakyan / Malayuang Kontroler / Takad Daungan / Kontrol sa Lupa)*

---
---
---
- **May-akda:** L. H. Dima  
- **Bersiyon:** 0.1 — *Paunang Balangkas*  
- **Petsa:** Oktubre 2025  
- **Kodigo ng Dokumento:** `mLNDH-0011`  
- **Pag-uuri:** Panloob – Para sa Unang Yugto ng Pagpapaunlad  
- **Kaugnay na mga Dokumento:**  
    - `mLNDH-0011` – Pinagkaisang Balangkas sa Pagtatala ng Oras

Itinatakda ng dokumentong ito ang **estruktura, layunin, at siklo ng pagsasapanahon** ng oras mula sa iba't ibang batis na orasan. Layunin nitong magbigay ng pamantayan sa pagpapanatili ng konsistensi sa pagtatala at pagsubaybay sa oras.

---
---
---

## 1. Layunin

Ang dokumentong ito ay naglalarawan ng **iisang mekanismo ng pagsubaybay sa oras** para sa lahat ng subsistema ng LNDH network.  
Layunin nitong:
- Magbigay ng **pamantayang format** ng oras (ISO 8601 / UNIX epoch).
- Magpanatili ng **consistency sa log timestamps** ng lahat ng device.
- Magsilbing **portable abstraction layer** sa iba’t ibang batis ng oras.

---

## 2. Pangkalahatang Katangian
| Katangian | Paglalarawan |
| --- | --- |
| **Portability** | Maaaring gamitin sa Arduino, ESP32, Raspberry Pi, o iba pang embedded platform. |
| **Hierarchical Time Source** | Nakabatay sa apat na antas ng pinagmumulan ng oras na may *automatic fallback*. |
| **Unified API** | Iisang interface sa code kahit mag-iba ang aktuwal na hardware o koneksyon. |
| **Synchronization Logging** | May tagatala kung kailan huling na-sync ang oras at mula saan. |

--- 

## 3. Arkitektura ng Batis ng Oras (*Time Source Hierarchy*)

Ang sistema ay gumagamit ng **multi-tier fallback system** ayon sa availability ng hardware at network:

``` txt
     [ Tier 1 ]  NTP (Network Time Protocol)
          ↓ fallback
     [ Tier 2 ]  GPS Time (via UART)
          ↓ fallback
     [ Tier 3 ]  RTC Module (DS3231, PCF8563, etc.)
          ↓ fallback
     [ Tier 4 ]  Internal millis()-based counter

```

> Kung hindi available ang mas mataas na tier, awtomatikong gagamitin ang susunod na available na batis.  
>
> Kapag muling naging available ang mas mataas na tier (hal. nagbalik ang GPS), auto-resync.

---

## 4. Mga Pangunahing Bahagi

| Bahagi | Paglalarawan |
| --- | --- |
| **TimeCore** | Pangunahing klase na humahawak sa kasalukuyang timestamp at hierarchy. |
| **TimeSource Interface** | Abstract base class para sa anumang time provider (GPS, RTC, NTP, Internal). |
| **SyncManager** | Nag-aasikaso ng periodic synchronization at switching logic. |
| **TimeUtils** | Nagbibigay ng conversion at formatting (ISO 8601, UNIX epoch, custom). |

---

## 5. API Overview

### 5.1. Core Functions

``` cpp
void Time.begin();                   // Initialize system clock
void Time.sync();                    // Force synchronization
String Time.nowISO();                // Return ISO timestamp
unsigned long Time.nowEpoch();       // Return UNIX time
bool Time.isSynced();                // Check if time is valid
```

### 5.2. Configuration

``` cpp
void Time.setSyncInterval(unsigned long ms);
void Time.setPreferredSource(TimeSourceType src);
```

### 5.3. Diagnostics
``` cpp
String Time.getSourceName();
String Time.getLastSyncISO();
```

---

## 6. Format ng Oras

| Format | Halimbawa | Paggamit |
| --- | --- | --- |
| ISO 8601 | `2025-10-12T14:57:09Z` | Default log timestamp |
| Short Time | `14:57:09` | Local debug display |
| UNIX Epoch | `1760284629` | Numeric synchronization &  computation |

---

## 7. Mga Time Source Implementation

### 7.1. 🕐 *Internal (millis-based)*

- Batay sa uptime ng system (`millis()`).
- Nagsisimula mula sa zero tuwing power-up.
- Ginagamit lamang kapag walang aktuwal na oras mula sa RTC/GPS/NTP.

### 7.2. 💾 *RTC Module*

- DS3231 o PCF8563 recommended.
- Nagbibigay ng real-world time kahit naka-off ang device.
- Maaaring iset mula sa GPS o NTP sa unang sync.

### 7.3. 🛰️ *GPS Sync*

- Gumagamit ng GPS module (e.g., NEO-6M, NEO-M8N).
- Binabasa ang UTC time mula sa `$GPRMC` o `$GPGGA` sentence.
- Highest reliability sa field operations kung walang internet.

### 7.4. 🌐 *NTP Sync*

- Gumagamit ng WiFi o Ethernet connection.
- Primary source kapag may network connectivity.
- May auto-update interval (default: 1 oras).

---

## 8. Fallback Logic (Pseudo-Flow)

### 8.1 Layunin

Ang seksiyong ito ay naglalarawan kung paano **dynamic na pinipili at pinapalitan** ng system ang active time source batay sa:

- **Availability** ng hardware o network
- **Freshness** ng oras (last sync)
- **Precision / accuracy grade** ng source

Layunin nito na **panatilihin ang pinakatumpak na timestamp sa lahat ng yunit**, kahit may temporary offline, hardware failure, o network loss.

### 8.2 Mga Prinsipyo ng Fallback

1. **Tiered hierarchy:**
- Ang mga source ay may pre-defined priority (Tier 1 → Tier 4).
- Mas mataas na tier ay preferred kung available at valid.

2. **Automatic detection:**
- Ang module ay regular na tinitingnan kung available ang mas mataas na tier (e.g., NTP online, GPS fix, RTC readable).
- Kapag bumalik ang mas mataas na source, awtomatikong magre-resync.

3. **Fallback threshold / timeout:**
- Bawat source ay may validity window (e.g., NTP sync expired after 1 hour).
- Kung lumampas ang threshold, magfa-fallback sa susunod na tier.

4. **Non-blocking operation:**
- Fallback at resync ay hindi pipigilan ang main loop o logging.

### 8.3 Arbitartaion Criteria

| Criterion | Deskripsyon | Halimbawa / Pananda |
| --- | --- | --- |
| **Source Availability**  | Ang source ay physically or logically accessible | GPS module connected + fix acquired |
| **Sync Freshness** | Oras mula huling successful sync | NTP last sync < 1 hour → valid |
| **Precision / Accuracy** | Estimated drift o ppm | GPS ±1 µs, RTC ±2 ppm, millis() ±5 ms/s |
| **Stability** | Patuloy na nagbibigay ng consistent time | Temporary GPS signal loss → fallback only if multiple seconds missing |

> Arbitration logic = **weighted evaluation** sa mga criterion: mas mataas ang priority sa mas tumpak at available na source.

### 8.4 Pseudo-Flow ng Fallback Logic

``` txt
flowchart TD
    A[Start Timestamp Module] --> B{Tier 1 NTP available?}
    B -->|Yes & Fresh| C[Use NTP Time]
    B -->|No / Expired| D{Tier 2 GPS available?}
    D -->|Yes & Valid| E[Use GPS Time]
    D -->|No| F{Tier 3 RTC available?}
    F -->|Yes| G[Use RTC Time]
    F -->|No| H[Use millis() / Internal Clock]
    C --> I[Log Active Source]
    E --> I
    G --> I
    H --> I
```

### 8.5 Update & Sync Intervals

| Source | Sync Interval | Validity Window |
| --- | --- | --- |
| NTP | 1 hr default (configurable) | 1 hr |
| GPS | Every fix (1 Hz typical) | 5 sec drift tolerance |
| RTC | Read on boot + periodic | ±5 ppm |
| millis() | Continuous | Only offset-based, resets on power cycle |

> Tandaan:
>
> - Ang `SyncManager` ay nagtatakda ng periodic checks at automatic resync base sa interval at validity window.
>
> - Sa simulation mode, puwede ring i-fake ang sync event para i-test ang logic.

### 8.7 Implementation Notes

1. **Timestamp validity flag:**
- `isSynced()` ay true lamang kung current source ay valid.

2. **Fallback counters:**
- Bilang kung ilang beses na nag-fallback → diagnostic metric.

3. **Soft resync:**
- Kapag bumalik ang mas mataas na tier, *smooth adjustment* (offset correction) para hindi abrupt ang jump sa logs.

4. **Simulation Mode:**
- Sa Arduino Nano ESP32, puwede i-emulate ang fallback sa isang board lang gamit `millis()` at fake GPS/NTP events.

--- 

## 9. Logging at Monitoring

- Bawat yunit ay magtatala ng:
    - Huling oras ng synchronization
    - Source ng huling sync
    - Deviation (kung sinusuportahan ng hardware)
- Ipinapasa sa **System Diagnostic Packet** para sa sentral na talaan.

---

## 10. Mga Susunod na Pagpapalawak

| Feature | Paglalarawan |
| --- | --- |
| **Time Drift Correction** | Auto-adjust ng RTC base sa GPS o NTP drift. |
| **Temperature Compensation** | Para sa mas tumpak na RTC modules. |
| **Cross-Unit Time Sync** | Inter-device sync sa closed network (kung walang GPS/NTP). |
| **Low-Power Timestamping** | Para sa battery-powered units. |

---

## 11. File References

| File | Paglalarawan |
| --- | --- |
| `lndh_time.h` | Header file ng unified timestamp API |
| `lndh_time.cpp` | Core implementation ng module |
| `time_source_gps.cpp` | GPS provider |
| `time_source_ntp.cpp` | NTP provider |
| `time_source_rtc.cpp` | RTC provider |
| `time_source_internal.cpp` | Millis provider |
