# Batayang Terminolohiya at Arkitektural na Balangkas

## 1. Layunin

Ang dokumentong ito ay nagtatakda ng opisyal, normatibo, at hindi malabong depinisyon ng mga pangunahing terminolohiyang ginagamit sa LundayHangin (LNDH) Project.

Nilalayon nitong: 
- Magbigay ng pinagkaisang bokabularyo
- Iwasan ang kalituhan sa disenyp, dokumentasyon, at implementasyon
- Magsilbing batayang sanggunian ng lahat ng teknikal na dokumento ng LNDH

Ang lahat ng susunod na dokumento, disenyo, at diskusyon sa loob ng proyekto ay dapat sumunod sa mga depinisyong nakasaad dito.

---

## 2. Saklaw

Sinasaklaw ng sokumentong ito ang:
- Konseptuwal na herarkiya ng LNDH
- Ugnayan ng mga pisikal at lohikal na bahagi
- Kahulugan ng mga terminong ginagamit sa arkitektura ng sistema
Hindi nito tinatalakay ang:
- Mga tungkulin o layunin ng operasyon
- Mga moda ng pagtakbo
- Mga polisiya ng desisyon o awtoridad
Ang mga ito ay saklaw ng hiwalay na mga dokumentong operasyonal.

---

## 3. Mga Terminong Arkitektural

### 3.1 Ekosistema (Ecosystem)

Depinisyon: 
Ang Ekosistema ay ang kabuoang hanay ng mga sistema, sugpong, kasangkapan,
lohisil, dokumentasyon, at proseso na magkakaugnay at nagtutulungan upang
suportahan ang buong lifecycle ng LundayHangin, mula disenyo at pagsubok hanggang operasyon at pagpapaunlad.

Katangian:
- Binubuo ng maraming sistema
- May ibinabahaging pamantayan, protokol, at daloy paggawa
- Dinisenyo upang lumawak at umangkop sa paglipas ng panahon

Tala:
Ang Ekosistema ay hindi isang sistema, kundi ang kapaligiran kung saan umiiral at makikipag-ugnayan ang mga sistema.

### 3.2 Sistema (System)

Depinisyon:
Ang Sistema ay isang intgrated at engineered na kabuoan na binubuo ng maraming subsistema at sugpong na magkakaugnay at nagtutulungan upang misagawa ang isang malinaw na pangunahing layunin.

Katangian:
- May iisang overarching function
- Binubuo ng maraming subsistema
- Maaaring distributed sa pisikal na anyo

Halimbawa:
Ang LNDH bilang isang gumaganang airship-drone setup, kasama ang mga kaugnay na sugpong nito.

### 3.3 Subsistema (Subsystem)

Depinisyon:
Ang Subsistema ay isang lohikal at functional na bahagi ng Sistema na nakatuon sa isang tiyak na tungkulin at maaaring ipinapatupad sa isa o higit pang sugpong.

Katangian:
- Functional grouping, hindi kinakailangang pisikal na magkakasama
- Maaaring nakakalat sa maraming sugpong
- May malinaw na saklaw at responisibilidad
Mga halimbawa ng Subsistema:
- Navigation Subsystem `ssNABE` (Nabegasyon)
- Control Subsystem `ssKTRL`(Kontrol)
- Propulsion Subsystem `ssPROP` (Propulsiyon)
- Communication Subsystem `ssKOMU` (Komunikasyon)
- Power Management Subsystem `ssKYNT` (Koryente)

### 3.4 Sugpong (Node)

Depinisyon:
Ang Sugpong ay isang pisikal na hiwalay, may sariling kakayahang komputasyon
at enerhiya, at bahagyang awtonomo na yunit na kalahok sa Sistemang LNDH at 
nagpapatupad ng isa o higit pang bahagi ng mga Subsistema nito.

Katangian:
- Pisikal na magkakahiwalay
- May sariling compute, power source, at software stack
- Kayang gumana nang mag-isa sa limitadong kakayahan
- Mas epektibo kapag konektado sa ibang sugpong
Mga Sugpong ng LNDH:
- Sugpong PS `sPS` — Airship / Flight Node
- Sugpong MK `sMK` — Remote Controller Node
- Sugpong TD `sTD` — Docking Node
- Sugpong KL `sKL` — Ground Control Node

Tala:
Ang Sugpong ay pisikal na entidad, hindi lohikal na tungkulin o papel.

### 3.5 Modyul (Module)

Depinisyon:
Ang Modyul ay isang malinaw na tinukoy at karaniwang mapapalitang functional block sa loob ng isang Sugpong na nagpapatupad ng isang partikular na bahagi ng isang Subsistema.

Katangian:
- Mas maliit kaysa Sugpong
- May malinaw na interface
- Maaaring hardware o software
- Dinisenyo para sa hiwalay ma pagtest, pagpapalit, at pag-upgrade
Halimbawa:
- Modyul GNSS
- Modyul IMU
- Modyul Radyo
- Modyul Pangkontrol ng Motor
- Modyul Panglista ng Datos

### 3.6 Komponent (Component)

Depinisyon:
Ang Komponent ay ang pinakamaliit na pisikal o lohikal na elemento na
bumubuo sa isang Modyul at hindi na hinahati pa sa mas maliit na bahagi sa
antas ng arkitektura.

Katangian:
- Atomiko sa kontekstong arkitektural
- Maaaring hardware o software primitive
Halimbawa:
- IC, sensor, motor, resistor, connector
- Low-level software unit o library primitive

---

## 4. Sangrabaw (Interface)

Depinisyon:
Ang Sangrabaw ay ang pormal na depinisyon ng paraan ng ugnayan sa pagitan ng dalawang subsistema, sugpong, o modyul.

Saklaw:
- Electrical interface
- Communication protocol
- Software API

Ang Sangrabaw ay nagsisilbing hangganan at kontrata sa pagitan ng mga bahagi
ng sistema

--- 

## 5. Opisyal na Arkitektural na Herarkiya

Ang opisyal at normatibong herarkiya ng LNDH ay ang sumusunod:

- Ekosistema
    - Sistema `LNDH`
    - Subsistema `ssXXXX`
    - Sugpong `sXX`
    - Modyul
    - Komponent

Ang herarkiya na ito ay ginagamit bilang batayan ng lahat ng disenyo, 
dokumentasyon, at pagsusuri sa loob ng proyekto.

--- 

## 6. Normatibong Pahayag

Ang mga terminong tinukoy sa dokumentong ito ay may tiyak, awtoritatibo, at
normatibong kahulugan sa loob ng Proyektong LNDH.
Anumang paggamit ng mga terminong ito sa iba pang dokumento ay dapat umayon sa mga depinisyong nakasaad dito.

