# ADR-0001 — Salig bilang Root Command Environment at Session Manager

**Estado:** Tinanggap (Accepted)  
**Petsa:** 2026-07-19  
**Proyekto:** LNDH-SKLB (Saklob Command Operating Environment)  

## Konteksto

Sa pagdidisenyo ng SKLB, kinakailangang tukuyin ang papel ng **Salig**, na unang iminungkahi bilang salin ng *root* sa mga sistemang katulad ng Unix/Linux.

Dalawang pangunahing arkitektura ang isinasaalang-alang:

1. **Salig bilang Root User Mode**, kung saan ito ang pinakamataas na user mode at may direktang ugnayan sa mga mode na Balana, Malim, at Bahala.

2. **Salig bilang Root Command Environment**, kung saan ito ang pangunahing kapaligiran ng SKLB na nagsisilbing entry point, session manager, at system administration context. Ang Balana, Malim, at Bahala ay hiwalay na mga user domains na pinapasok mula sa Salig.

Kinailangan ding isaalang-alang ang posibilidad ng pagkakaroon ng user accounts, multi-session support, at pagpapalawak ng SKLB sa hinaharap nang hindi binabago ang pundamental na disenyo ng prompt at command language.

## Desisyon

Napagpasyahang gamitin ang **ikalawang arkitektura**.

Ang **Salig** ay ituturing bilang **Root Command Environment** ng SKLB at hindi bilang ordinaryong user domain.

Pagkatapos mag-boot ang sistema, ang unang aktibong command environment ay ang Salig.

Halimbawa:

```text
salig@lndh(dron)>
```

Mula sa Salig, maaaring:

* magsimula ng **Balana** session;
* magpatunay (authenticate) upang pumasok sa **Malim** o **Bahala**;
* magsagawa ng **login** kapag gumagamit ng user accounts;
* magsagawa ng mga command na nauukol mismo sa SKLB, gaya ng `saklob(kumpig)`.

Kapag may configuration context ang mismong SKLB:

```text
salig@lndh(dron):saklob(kumpig)#
```

## Arkitekturang Napili

```text
                   Salig
        (Root Command Environment)
                     │
     ┌───────────────┼───────────────┐
     │               │               │
  login          balana         saklob
                     │
             ┌───────┴────────┐
             │                │
          malim           bahala
```

Sa modelong ito:

* ang **Salig** ang namamahala sa session lifecycle;
* ang **Balana**, **Malim**, at **Bahala** ay mga **user domains**;
* ang **Saklob** ay isang **system domain** na responsable sa mismong command operating environment.

## Mga Dahilan

Napili ang arkitekturang ito dahil:

* malinaw ang paghihiwalay ng **system administration** at **user operation**;
* madaling suportahan ang parehong **Appliance Mode** (walang user accounts) at **Multi-user Mode** nang hindi binabago ang prompt grammar;
* nagbibigay ng natural na lugar para sa mga command na nauukol sa SKLB mismo;
* naaayon sa distributed architecture ng LNDH kung saan maraming node ang maaaring pamahalaan sa iisang command language;
* madaling palawakin para sa remote sessions, auditing, automation, at identity management.

## Mga Bunga

### Positibo

* Nananatiling pareho ang prompt grammar sa lahat ng deployment.
* Hindi kailangang baguhin ang command parser kapag nagdagdag ng user accounts.
* May malinaw na entry point para sa authentication at session management.
* Hiwalay ang command domains ng gumagamit at ng mismong command operating environment.
* Mas madaling suportahan ang recovery, maintenance, at emergency operations.

### Mga Limitasyon

* Kailangang magpatupad ng hiwalay na session manager sa loob ng SKLB.
* Kailangang malinaw na maipaliwanag sa dokumentasyon ang pagkakaiba ng **Salig**, **Balana**, **Malim**, at **Bahala**, sapagkat hindi ito katulad ng tradisyunal na Unix privilege model.

## Kaugnay na Desisyon

Ang ADR na ito ang nagtatatag ng pundasyon para sa mga susunod na espesipikasyon, kabilang ang:

* Prompt Grammar Specification
* Authentication and Authorization Specification
* Session Management Specification
* Domain and Context Specification
* Command Language Specification

Ang lahat ng susunod na desisyong pang-arkitektura ay inaasahang magiging tugma sa modelong ito maliban kung may bagong ADR na magpapawalang-bisa o magbabago rito.
