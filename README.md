<p style="font-size:32px; font-weight:700; margin:0; display:flex; align-items:center; gap:8px;">
  <img src="./assets/icons/dirihible.svg" width="90">
  LNDH — <i>LundayHangin</i>
</p>

![Status](https://img.shields.io/badge/status-experimental-orange)
![Development Board](https://img.shields.io/badge/development%20board-Arduino%20Nano%20ESP32-blue)
![Framework](https://img.shields.io/badge/framework-Arduino-00979D)
![Architecture](https://img.shields.io/badge/architecture-distributed-lightgreen)
![Type](https://img.shields.io/badge/type-airship%20drone-informational)
![Language](https://img.shields.io/badge/language-Filipino-green)
![License](https://img.shields.io/badge/license-TBD-red)

Ang **LNDH / *LundayHangin*** ay isang pangmatagalang proyektong pang-inhenyeriya na nakatuon sa pagbuo ng isang mababang gastos ngunit sistematikong plataporma ng dron na dirihible gamit ang mga abot-kayang kagamitang elektroniko, bukás na mapagkukunang lohisil, at paraang paulit-ulit na pagpapaunlad ng sistema.

Layunin ng proyekto na magsilbing eksperimental na plataporma para sa pag-aaral at pagpapaunlad ng mga konsepto sa sistemang nakaembed, komunikasyong walangkawad, telemetriya, malayuang operasyon, awtonomong asal ng sistema, at mga sistemang robotiko na nakapamahagi.

Ang paunang balangkas ng sistema ay binubuo ng mga modular na yunit na may kani-kaniyang tungkulin sa operasyon, kabilang ang Yunit ng Dron na Dirihible (YDD/ADU), Yunit ng Malayuang Kontrol (YMK/RCU), Yunit ng Takad na Daungan (YTD/DBU), at Himpilan ng Kontrol sa Lupa (HKL/GCS).

Bagaman nasa eksperimental na yugto pa lamang, sinisikap nitong sundin ang ilang pangunahing konseptong karaniwang matatagpuan sa mga sistemang pang-inhenyeriya at pang-industriyang antas gaya ng modularidad, telemetriya, pagtukoy ng mga depekto, mantenebilidad, at paunti-unting integrasyon ng mga bahagi nito.

Hindi layunin ng proyektong ito na agad makabuo ng ganap na awtonomong plataporma ng dirihible. Sa halip, binibigyan ng halaga nito ang maingat at unti-unting pagpapaunlad, parktikal na eksperimento, dokumentasyon, at patuloy na pagkatuto habang lumalawak ang kakayahan ng sistema.

---

## Pangkalahatang Tanaw ng Sistema

## Mga Yunit

| Yunit | Buong Pangalan | Tungkulin | Katayuan |
| --- | --- | --- | --- |
| YDD / ADU | Yunit ng Dron na Dirihible | Pangunahing sasakyan sa hangin | 🟠 Binubuo | 
| YMK / RCU | Yunit ng Malayuang Kontrol | Kontrol na hawak ng opereytor | 🟠 Binubuo |
| YTD / DBU | Yunit ng Takad na Daungan | Pagdaong at suporta sa lupa | 🔴 Nakaplano |
| HKL / GCS | Himpilan ng Kontrol sa Lupa | Telemetriya at pagmamasid | 🔴 Nakaplano |

## Plataporma at Mga Kahingian

- Arduino Nano ESP32 — lahat ng yunit
- Arduino framework (PlatformIO)
- *Mga karagdagang dependensiya: tingnan ang bawat `src/[yunit]/`*

## Estruktura ng Repositoryo

**Panukala:**
```
LNDH/
├── src/
│   ├── ydd/        # Yunit ng Dron na Dirihible
│   ├── ymk/        # Yunit ng Malayuang Kontrol
│   ├── ytd/        # Yunit ng Takad na Daungan
│   └── hkl/        # Himpilan ng Kontrol sa Lupa
├── docs/
│   ├── architecture.md
│   ├── comms-protocol.md
│   └── ...
└── README.md
```

## Dokumentasyon

- [Halimbawa ng Dokumentasyon](docs/pamagat-ng-doku.md)

<!-- - [Arkitektura ng Sistema](docs/architecture.md)
- [Protokol ng Komunikasyon](docs/comms-protocol.md)
- [Gabay sa Pagpapaunlad](docs/dev-guide.md)
- [Talaan ng mga Pagbabago](docs/changelog.md) -->

## Lisensiya


---

<!-- ## 🎯 Layunin sa Mataas na Antas

* Bumuo ng **isang lumilipad na pangunahing sasakyan** na kayang magsagawa ng misyon.
* Bumuo ng **hiwalay ngunit magkakaugnay na mga yunit** para sa kontrol, daungan, at pagmamanman.
* Magkaroon ng **iisang codebase** na kayang maghatid ng maraming firmware variants sa pamamagitan ng roles.
* Maglatag ng **malinaw na arkitektura at dokumentasyon** upang madaling mapanatili at mapalawak ang sistema.

Sa kabuoan, layunin nitong magbigay ng **isang malinaw, modular, at madaling paunlarin** na sistemang pang‑airship‑drone.

---

## 🧭 Saklaw ng Proyekto

**Kasama sa saklaw:**

* Firmware para sa maraming MCU na may kanya‑kanyang tungkulin
* Isang repository na may maraming PlatformIO environments
* Mga dokumentong pamantayan (`docs/mLNDH-XXXX`)
* Malinaw na versioning at changelog

**Hindi pa kasama (sa ngayon):**

* Mechanical / CAD design ng airframe
* Production tooling
* End‑user or consumer‑grade UX

---

## 🧩 Arkitektura sa Mataas na Antas

Ang LNDH ay binubuo ng **mga role‑based nodes**:

* **LH_PS** — Pangunahing Sasakyan (airship / vehicle side)
* **LH_MK** — Malayuang Kontroler (handheld / operator side)
* **LH_TD** — Takad Daungan (docking / base station)
* **LH_KL** — Kontrol sa Lupa (ground control / supervision)
* **LH_TEST** — Kaligirang pansubok para sa eksperimento

Bawat role ay:

* May sariling PlatformIO environment
* May malinaw na saklaw ng responsibilidad
* Nakikipag‑ugnayan sa iba sa pamamagitan ng tinukoy na interfaces

> Ang eksaktong detalye ng bawat role ay idodokumento sa `docs/`.

---

## 📁 Estruktura ng Repository (Sa Mataas na Antas)

```
LNDH/
├─ src/            # Source code (shared at per‑role)
├─ include/        # Shared headers (hal. version info)
├─ docs/           # mLNDH documents at design references
├─ lib/            # Mga hiwalay na aklatan (kung kinakailangan)
├─ test/           # Kaligirang pansubok
├─ platformio.ini  # Multi‑environment configuration
├─ CHANGELOG.md    # Kasaysayan ng mga pagbabago
└─ README.md       # Ikaw ay narito 🙂
```

---

## 🏷️ Versioning at Disiplina

Sumusunod ang proyekto sa **Semantic Versioning**:

```
MAJOR.MINOR.PATCH
```

* Ang kasalukuyang bersiyon ay tinutukoy sa `include/lndh_version.h`
* Ang lahat ng makabuluhang pagbabago ay itinatala sa `CHANGELOG.md`

---

## 🔧 Development (Sa Pangkalahatan)

* Ginagamit ang **PlatformIO** bilang build system
* Bawat role ay may sariling environment
* Maaaring magkaiba ang target MCU depende sa papel

> Ang step‑by‑step na paggamit ay sadyang wala muna rito; ilalagay iyon sa hiwalay na dokumento upang manatiling *high‑level* ang README na ito.

---

## 📚 Dokumentasyon

Ang folder na `docs/` ay naglalaman ng mga dokumentong **mLNDH-XXXX** na:

* Nagtatakda ng mga pamantayan at patakaran
* Naglilinaw ng mga desisyon sa disenyo
* Nagsisilbing "saligang‑batas" ng proyekto

Kung may hindi malinaw sa code: **malamang nasa docs ang sagot** (o kasalanan ng docs — inaamin naman 😄).

---

## ⚠️ Babala

Ito ay **eksperimental** na proyekto. Walang garantiya ng:

* Katatagan
* Kaligtasan
* O sapat na oras para tutukan ng may‑akda

Gamitin sa sariling pananagutan.

---

## ✍️ May‑akda

Lakan Haraya Dima

---

## 🔑 Lisensiya

*(Tinutukoy pa)* -->
