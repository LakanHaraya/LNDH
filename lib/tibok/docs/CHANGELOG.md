# 📝 CHANGELOG

Lahat ng mahahalagang pagbabago sa **Tibok** ay idodokumento sa file na ito.

Ang format na ito ay batay sa [Keep a Changelog](https://keepachangelog.com/en/1.0.0/) at sumusunod sa [Semantic Versioning](https://semver.org/).

---

## [0.4.0] - 2025-08-18

### Pinalitan

- Ibinalik sa tibok 0.5 Hz ang `Tibok::NORMAL`.
- Inakma ang buong agwat ng `Tibok::STANBY` sa dalawang segundo.

### Tinanggal

- Tinanggal ang `Tibok::NOTICE` dahil sa kalabuan ng gamit nito. 

### Inayos

- Ginawang kada-halimbagay ang lohika ng pabugsong `Tibok::STANDBY`.
- Nilinaw ang mga dokumentasyon.

## [0.3.0] - 2025-06-02

### Idinagdag

- Idinagdag ang `Tibok::STANDBY` bilang inidkasyon ng pag-antabay.
- Idinagdag ang `Tibok::NOTICE` bilang indikasyon ng pagpapaalala.

### Pinalitan

- Ginawang ganap na nakasindi ang `Tibok::NORMAL`.
- Inilipat sa `Tibok::NOTICE` ang antas ng tibok 0.5 Hz ng dating `Tibok::NORMAL`.
- Pinalitan ang default `HeartbeatLevel` magmula sa `Tibok::NORMAL` patungo sa `Tibok::STANDBY`.

### Tinanggal

- Tinanggal ang `getHeartbeat()` method

### Inayos

- Pagpapahusay sa buong implementasyon ng mga API.
- Pagsasapanahon ng mga dokumentasyon.

---

## [0.2.1] - 2025-05-15

### Pinalitan
- Inilipat ang enum `HeartbeatLevel` sa loob ng `Tibok` class (`Tibok::HeartbeatLevel`) upang maiwasan ang alitan sa ibang libraries. Gamitin na ngayon ang `Tibok::NORMAL`, `Tibok::WARNING`, `Tibok::CRITICAL`, at `Tibok::EMERGENCY`.
- Ibinalik ang malinaw na pangalan ng mga setter method patungo sa `setActiveHigh()`, at `setHeartbeat()`.

### Inayos
- Munting optimisasyon. Walang pagbabago sa lohika.
- Munting pagsasaayos ng dokumentasyon.

---

## [0.2.0] - 2025-04-29

### Idinagdag
- Idinagdag ang mga bagong getter method: `getPin()`, `isActiveHigh()`, `isEnabled()`, `getState()`, `getLastToggle()`, at `getHeartbeat`.
- Dinagdagan ng parameter ang `enable()`, `activeHigh()`, at `heartbeat()`, kasama ang mga default value nito.
- Dinagdagan ng parameter ang konstruktor na `Tibok()` para suportahan ang `level`, `activeHigh`, at `enabled`, kasama ang mga default value nito.
- Dinagdagan ng suporta para sa *chaining  methods*.
- Hinahanda para suportahan ang **Arduino Library Manager**.

### Pinalitan
- Pinalitan ang pangalan ng buong library bilang `Tibok`
- Pinalitan ang pangalan ng mga method na `setLevel()`, at `setActiveHigh()`, patungo sa `heartbeat()`, at `activeHigh()`.

### Tinanggal
- Tinanggal ang `DISABLED` mula sa `HeartbeatLevel`.
- Tinanggal ang `begin()` dahil sinusuportahan na ito sa konstruktor.
- Tinanggal ang `disable()` dahil sinusuportahan na ito sa `enable()`.

### Inayos
- Pangkalahatang pagsasaayos ng mga dokumentasyon at halimbawa.

---

## [0.1.0] - 2025-04-11

### Idinagdag

- Inilabas ang `MuntingTibok` bilang isang minimalistikong bersiyon ng `LundayTibokAkl`.
- Idinagdag ang `HeartbeatLevel` enum batay sa IEC 60073:2002.
- Idinagdag ang `update()` method para sa patuloy na pagtibok.
- Idinagdag ang `enable()` at `disable()` para sa kontrol ng estado.
- Idinagdag ang `begin()` method para sa pagsisimula ng operasyon.
- Idinagdag ang kakayahang tukuyin kung active HIGH o LOW ang pin.
- Idinagdag ang `setLevel()` para sa runtime switching ng tibok.