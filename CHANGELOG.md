# CHANGELOG

Lahat ng mahahalagang pagbabago sa **LNDH** ay idodokumento sa file na ito.

Ang format na ito ay batay sa [Keep a Changelog](https://keepachangelog.com/en/1.0.0/) at sumusunod sa [Semantic Versioning](https://semver.org/).

---

## [0.1.2] - 2026-01-17 - PINAUUSWAG

### Pinalitan

- Binagong estruktura ng dokumentasyon sa `doku/`

---

## [0.1.1] - 2026-01-12 - Batayang Takbuhin (Core Runtime)

### Idinagdag
- **LNDH Core Runtime**: role-agnostic at non-blocking na execution core
- Pangkalahatang kooperatibong kontrata ng gawain (`LndhTask`)
- Ibinabahaging scheduler loop (`lndh_core_init`, `lndh_core_loop`, `lndh_core_register`)
- Pinag-isang abstraksiyon ng timebase (`lndh_now_ms`)
- Firmware banner na nagpapakita ng tungkulin at bersiyon

### Pinalitan
- Estandardisadong estruktura ng `setup()` / `loop()` sa lahat ng tungkulin (PS, MK, TD, KL)
- Sentralisadong ibinabahaging implementasyon sa ilalim ng `src/common/`

### Tandaan
- Wala pang RTOS integration (nakaplano)
- Wala pang system state machine (nakaplano)

---

## [0.1.0] - 2026-01-11 - Paunang Balangkas (Initial Skeleton)
### Idinagdag
- Inisyal na estruktura ng proyekto
- PlatformIO multi-environment configuration 
- Batayang depinisyon ng tungkulin (roles)