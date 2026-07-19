# ADR-0003 — Domain at Context Model

**Estado:** Tinanggap (Accepted)  
**Petsa:** 2026-07-19  
**Proyekto:** LNDH-SKLB (Saklob Command Operating Environment)

---

## Konteksto

Matapos maitatag sa **ADR-0001** ang *Salig* bilang Root Command Environment at Session Manager, at sa **ADR-0002** ang Session Identity at Prompt Grammar, kinakailangang itatag ang lohikal na organisasyon ng command operating environment.

Habang lumalawak ang kakayahan ng SKLB, inaasahang darami ang mga subsystem, command, at workflow ng bawat node sa loob ng ekosistemang LNDH. Kinakailangan ng isang pare-pareho, malinaw, at napapalawak na modelo upang maorganisa ang mga operasyong ito nang hindi nakatali sa isang partikular na implementasyon.

Ang dokumentong ito ang nagtatatag ng opisyal na lohikal na modelo ng Domain at Context ng SKLB, kabilang ang kanilang ugnayan sa Session, Node, Navigation, at Configuration Workspace.

---

## Suliranin

Kinakailangang magkaroon ng isang lohikal na modelo na:

* naghihiwalay sa **operational responsibility** at **operational focus**;
* nagbibigay ng pare-parehong command navigation sa lahat ng node;
* nananatiling simple ngunit madaling mapalawak;
* nagsisilbing pundasyon ng command language at command parser ng SKLB.

---

## Desisyon

Ang mga sumusunod na subseksiyon ang nagtatakda ng mga pangunahing konsepto, ugnayan, at panuntunang bumubuo sa opisyal na Domain at Context Model ng SKLB.

### Domain

Ang **Domain** ang pangunahing lohikal na kapaligiran ng operasyon (*logical operational environment*) sa loob ng isang Session.

Ito ang kumakatawan sa **operational responsibility** ng gumagamit at nagtatakda ng saklaw ng mga operasyong pinahihintulutan, mga command na maaaring gamitin, at pangkalahatang workflow ng kasalukuyang session.

Sa bawat Session, iisa lamang ang maaaring maging aktibong Domain.


### Context

Ang **Context** ay isang espesyalisadong **operational focus** sa loob ng kasalukuyang Domain.

Hindi ito bumubuo ng panibagong Domain at hindi nito binabago ang operational responsibility ng gumagamit. Sa halip, inilalantad nito ang isang tiyak na bahagi ng kakayahan ng kasalukuyang node bilang isang lohikal na kapaligiran ng operasyon.

Sa bawat aktibong Domain, maaaring walang aktibong Context o magkaroon lamang ng iisang aktibong Context sa bawat sandali.

### Ugnayan ng Session, Domain, Context, at Node

Ang bawat Session ay naglalaman ng iisang aktibong Domain.

Ang bawat aktibong Domain ay maaaring magkaroon ng wala o isang aktibong Context.

Ang Context ay isang **estado ng command navigation** at umiiral lamang sa loob ng kasalukuyang Domain.

Samantala, ang mga resource, setting, configuration, telemetry, at iba pang kakayahan ay pagmamay-ari ng kasalukuyang **Node**. Ang mga ito ay ina-access sa pamamagitan ng Context at nananatiling bahagi ng Node anuman ang kasalukuyang Domain, alinsunod sa mga pahintulot ng gumagamit.

### Operational at Configuration Context

Dalawang uri ng Context ang kinikilala ng SKLB.

#### Operational Context

Ang Operational Context ay ginagamit para sa pagmamasid, operasyon, pagsusuri, at iba pang gawaing hindi nangangailangan ng configuration workspace.

Maaari itong direktang pasukin mula sa kasalukuyang Domain.

#### Configuration Workspace

Ang **`kumpig`** ay isang espesyal na **Configuration Workspace** na ipinapakita bilang isang Context sa Prompt Grammar.

Ito ang parent environment ng lahat ng Configuration Context at nagsisilbing katumbas ng *configuration mode* ng Cisco IOS.

Ang mga Configuration Context ay kinakatawan bilang mga **qualified context** gamit ang tuldok (`.`) bilang hierarchical separator.

Ang mga aktuwal na Context at ang kanilang hierarchy ay inilalarawan sa hiwalay na Specification.

### Node-driven Context Model

Ang SKLB ay hindi nagtatakda ng nakapirming listahan ng mga Context.

Sa halip, ang mga Context ay nakabatay sa:

* kasalukuyang System;
* kasalukuyang Node;
* mga kakayahan (*capabilities*) ng Node.

Dahil dito, maaaring magkaiba ang mga available na Context ng bawat node habang nananatiling pareho ang command model ng SKLB.

### Navigation Model

Ang command navigation ay sumusunod sa mga sumusunod na prinsipyo:

* ang Operational Context ay maaaring direktang pasukin mula sa kasalukuyang Domain;
* ang Configuration Context ay dapat munang dumaan sa `kumpig`;
* ang paglabas ay isinasagawa gamit ang command na `labas`;
* ang `labas` ay laging bumabalik sa parent Context o Domain;
* hindi pinahihintulutan ang direktang paglipat sa sibling Context.

Ang detalyadong navigation behavior ay ilalarawan sa hiwalay na Specification.

### Prompt State

Ang Prompt State (`>` at `#`) ay hiwalay sa Domain at Context.

Ito ay nagsasaad lamang ng kasalukuyang estado ng command operating environment at hindi bumubuo ng bagong Domain o Context.

## Mga Prinsipyong Pang-arkitektura

* Ang **Domain** ang nagtatakda ng saklaw ng mga operasyong pinahihintulutan sa kasalukuyang Session.
* Ang **Node** ang nagmamay-ari ng mga resource, setting, configuration, at kakayahang ginagamit ng sistema.
* Ang **Context** ang naglalantad ng isang tiyak na bahagi ng mga kakayahan ng Node bilang isang lohikal na kapaligiran ng operasyon.
* Ang **Prompt State** ang nagpapakita kung ang kasalukuyang operasyon ay nasa execution state (`>`) o configuration state (`#`).

## Mga Dahilan

Napili ang modelong ito dahil:

* malinaw nitong pinaghihiwalay ang operational responsibility, operational focus, at pagmamay-ari ng resource;
* nagbibigay ito ng pare-parehong command navigation sa buong SKLB;
* umaayon ito sa mga prinsipyong ginagamit ng Cisco IOS habang nananatiling may sariling identidad ang SKLB;
* nagbibigay ito ng matatag at napapalawak na pundasyon para sa command language, session manager, at command parser.

## Mga Bunga

### Positibo

* Pare-pareho ang lohikal na organisasyon ng command operating environment.
* Malinaw ang paghihiwalay ng Session, Domain, Context, at Node.
* Ang bawat node ay maaaring magkaroon ng sariling hanay ng Context nang hindi binabago ang pangunahing arkitektura.
* Napapasimple ang pagpapanatili at pagpapalawak ng SKLB.

### Mga Limitasyon

Hindi tinutukoy ng ADR na ito ang:

* eksaktong listahan ng mga Domain at Context;
* command syntax;
* command hierarchy;
* command parser;
* command navigation details.

Ang mga ito ay ilalagay sa magkakahiwalay na Specification.

## Kaugnay na mga ADR

Nakabatay ang ADR na ito sa:

* **ADR-0001 — Salig bilang Root Command Environment at Session Manager**
* **ADR-0002 — Session Identity at Prompt Grammar**

Magsisilbi naman itong pundasyon ng mga susunod na ADR at Specification na may kaugnayan sa Session Model, Command Language, Navigation, at iba pang bahagi ng SKLB.

## Katayuan

Sa pamamagitan ng dokumentong ito, ang **Domain at Context Model** ang siyang opisyal na lohikal na modelo ng command operating environment ng LNDH-SKLB. Ang lahat ng susunod na desisyong pang-arkitektura at espesipikasyon ay inaasahang magiging kaayon ng modelong itinatag sa ADR na ito.
