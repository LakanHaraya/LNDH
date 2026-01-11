# 🌬️ LNDH — *LundayHangin*

**Isang modular na airship‑drone ecosystem** para sa eksperimento, pagkatuto, at maingat na pag-scale mula prototype hanggang mas disiplinadong sistema.

---

## 📌 Ano ito?

Ang **LNDH (LundayHangin)** ay isang **maramihang‑yunit** na proyektong panghimpapawid. Binubuo ito ng ilang MCU‑based na *roles* na may kanya‑kanyang tungkulin ngunit **nakikipag‑ugnayan bilang iisang sistema** upang patakbuhin ang isang airship‑drone.

Dinisenyo ang proyekto na:

* 🔁 **Modular** — madaling palitan o dagdagan ang bahagi
* 🧱 **Role‑based** — malinaw ang hangganan ng responsibilidad
* 📐 **Documented‑by‑design** — may pormal na mLNDH documents at changelog
* 🧪 **Prototype‑first** — inuuna ang pagkatuto, pero may disiplina sa pag‑unlad

Sa madaling sabi: *mas gusto ng LNDH ang maayos na proseso kaysa sa magulong “gumagana naman”.* (Oo, mas mabagal — pero mas tahimik ang konsensya.)

---

## 🎯 Layunin sa Mataas na Antas

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

*(Tinutukoy pa)*
