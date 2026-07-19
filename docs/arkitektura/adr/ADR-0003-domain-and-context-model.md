# ADR-0003 — Domain and Context Model

[**NAKABINBING KATANUNGAN**](#open-design-questions)  
**Estado:** Draft    
**Petsa:** 2026-07-19  
**Proyekto:** LNDH-SKLB (Saklob Command Operating Environment)

## Konteksto

Matapos maitatag sa **ADR-0001** ang *Salig* bilang Root Command Environment at *Session Manager*, at sa **ADR-0002** ang opisyal na *Session Identity at Prompt Grammar*, kinakailangan namang tukuyin ang lohikal na organisasyon ng command operating environment.

Habang lumalawak ang kakayahan ng SKLB, inaasahang dadami ang mga command, subsystem, at workflow. Kung walang malinaw na modelo ng organisasyon, maaaring magkaroon ng hindi magkakatugmang command hierarchy, magkakahalong responsibilidad ng mga user mode, at hindi pare-parehong paglipat sa pagitan ng iba't ibang bahagi ng sistema.

Dahil dito, kinakailangang magtakda ng isang pangkalahatang modelo para sa **Domain** at **Context** na magiging batayan ng pag-oorganisa ng lahat ng command at operational workflow ng SKLB.

## Suliranin

Kinakailangang magtakda ng isang lohikal na estruktura na:

* naghihiwalay sa pangunahing tungkulin (*operational responsibility*) at pansamantalang pokus (*operational focus*);
* nananatiling simple at madaling maunawaan ng gumagamit;
* madaling palawakin habang lumalaki ang SKLB;
* umaayon sa command navigation na ginagamit sa mga sistemang tulad ng Cisco IOS nang hindi kinakailangang gayahin ang eksaktong implementasyon nito.

Kung walang malinaw na paghihiwalay ng Domain at Context, maaaring maging magulo ang command hierarchy, magkaroon ng magkakaparehong functionality sa iba't ibang bahagi ng sistema, at maging mahirap ang pagpapanatili ng command language sa paglipas ng panahon.

## Desisyon

Napagpasyahang gamitin ang sumusunod na konseptuwal na modelo sa SKLB.

### Domain

Ang **Domain** ang pangunahing yunit ng organisasyon ng command operating environment.

Ito ay isang lohikal na kapaligiran ng operasyon na kumakatawan sa isang natatanging tungkulin o responsibilidad sa loob ng SKLB. Ang bawat Domain ay maaaring magkaroon ng sariling hanay ng mga command, operational workflow, at mga Context.

Ang paglipat sa ibang Domain ay nangangahulugan ng paglipat sa ibang operational responsibility.

### Context

Ang **Context** ay isang espesyalisadong estado sa loob ng kasalukuyang Domain.

Hindi ito bumubuo ng panibagong Domain. Sa halip, ginagamit ito upang ituon ang kasalukuyang Domain sa isang partikular na subsystem, gawain, o workflow.

Ang pagpasok sa isang Context ay hindi nagbabago sa operational responsibility ng gumagamit; binabago lamang nito ang kasalukuyang pokus ng operasyon.

### Relasyon ng Domain at Context

Sa bawat pagkakataon:

* ang isang Session ay nasa iisang aktibong Domain;
* ang isang Domain ay maaaring walang aktibong Context;
* kung may aktibong Context, ito ay nabibilang lamang sa kasalukuyang Domain;
* iisa lamang ang maaaring maging aktibong Context sa bawat sandali.

Hindi pinahihintulutan ang magkakasabay o magkakapatong na Context.

### Prompt State

Ang mga Prompt State (`>` at `#`) ay hiwalay sa Domain at Context.

Ang Prompt State ay nagsasaad lamang ng kasalukuyang estado ng session (halimbawa, execution o configuration) at hindi bumubuo ng panibagong Domain o Context.

## Mga Dahilan

Napili ang modelong ito dahil:

* malinaw nitong pinaghihiwalay ang *operational responsibility* at *operational focus*;
* pinapanatili nitong simple ang command navigation;
* umaayon ito sa prinsipyong ginagamit ng Cisco IOS na iisang context lamang ang aktibo sa bawat pagkakataon;
* nagbibigay ito ng matatag na pundasyon para sa command parser, session manager, at command language;
* nagbibigay ito ng sapat na kakayahang mapalawak ang SKLB nang hindi binabago ang pangunahing organisasyon ng command operating environment.

## Mga Bunga

### Positibo

* Nagiging pare-pareho ang organisasyon ng mga command sa buong SKLB.
* Nagiging malinaw ang paghihiwalay ng mga responsibilidad at mga workflow.
* Napapadali ang pagdaragdag ng mga bagong Domain at Context sa hinaharap.
* Nagiging mas simple ang pagdidisenyo ng command parser at command navigation.

### Mga Limitasyon

* Hindi pa tinutukoy ng ADR na ito ang kumpletong listahan ng mga Domain at Context.
* Hindi pa nito tinutukoy ang eksaktong paraan ng pagpasok at paglabas sa bawat Context.
* Hindi pa nito tinutukoy ang command syntax o ang implementasyon ng command navigation.
* Ang mga espesipikong Context ay ilalarawan sa hiwalay na teknikal na espesipikasyon o sa mga susunod na ADR kung kinakailangan.

## Kaugnay na Desisyon

Ang ADR na ito ay nakabatay sa:

* **ADR-0001 — Salig bilang Root Command Environment at Session Manager**
* **ADR-0002 — Session Identity at Prompt Grammar**

At magsisilbing pundasyon para sa mga susunod na desisyon tungkol sa:

* Session and Authentication Model
* Command Language Philosophy
* Command Navigation
* Built-in Commands
* Domain and Context Specification

Ang detalyadong listahan ng mga opisyal na Domain, Context, kanilang mga ugnayan, at command hierarchy ay ilalagay sa hiwalay na **Domain and Context Specification**, habang ang ADR na ito ay mananatiling talaan ng pangunahing desisyong pang-arkitektura hinggil sa lohikal na organisasyon ng command operating environment ng SKLB.

---
---

# Open Design Questions

Ang mga sumusunod ay kasalukuyang sinusuri bago tanggapin ang ADR:

- lifecycle ng **Context**;
- papel ng `kumpig`;
- mga panuntunan sa pagpasok at paglabas ng **Context**.
