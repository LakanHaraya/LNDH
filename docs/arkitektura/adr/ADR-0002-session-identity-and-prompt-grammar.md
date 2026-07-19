# ADR-0002 — Session Identity at Prompt Grammar

**Estado:** Tinanggap (Accepted)  
**Petsa:** 2026-07-19  
**Proyekto:** LNDH-SKLB (Saklob Command Operating Environment)

## Konteksto

Matapos maitatag sa **ADR-0001** na ang **Salig** ang magsisilbing *Root Command Environment* at *Session Manager* ng SKLB, kinakailangang tukuyin kung paano kakatawanin ng command operating environment ang kasalukuyang session.

Sa mga tradisyunal na command-line interfaces, ang prompt ay karaniwang nagsisilbi lamang bilang palatandaan na handa ang sistema na tumanggap ng utos. Sa SKLB, ninanais na ang prompt ay magsilbi ring opisyal na representasyon ng buong session upang maging pare-pareho ang pagpapakita ng kasalukuyang kalagayan ng command operating environment.

Kinakailangan ding suportahan ng iisang prompt grammar ang parehong **Appliance Mode** (walang user accounts), **Multi-user Mode**, at ang distributed architecture ng LNDH na binubuo ng maraming nodes.

## Suliranin

Kinakailangang magtakda ng isang pare-pareho at matatag na gramatika ng prompt na:

* kumakatawan sa kasalukuyang session;
* madaling maunawaan ng gumagamit;
* hindi nakatali sa pagkakaroon o kawalan ng user accounts;
* madaling palawakin habang lumalaki ang SKLB;
* nananatiling pareho sa lahat ng nodes at deployment modes.

Kung walang opisyal na prompt grammar, maaaring magkaroon ng hindi magkakatugmang representasyon ng session sa iba't ibang bahagi ng command operating environment, na magpapahirap sa pagpapanatili, dokumentasyon, at implementasyon ng SKLB.

## Desisyon

Napagpasyahang gamitin ang sumusunod na opisyal na gramatika ng prompt para sa lahat ng session ng SKLB.

```text
[identity@]system(node)[:domain[(context)]]prompt
```

Sa modelong ito:

* ang **identity** ay opsyonal at kumakatawan sa kasalukuyang session identity;
* ang **system** ay tumutukoy sa target na ecosystem;
* ang **node** ay nagsasaad ng kasalukuyang host o MCU;
* ang **domain** ay tumutukoy sa kasalukuyang command domain;
* ang **context** ay nagsasaad ng partikular na context at subcontext ng domain;
* ang **prompt symbol** (`>` o `#`) ay nagsasaad ng kasalukuyang command state.

Ang bawat bahagi ng prompt ay may iisang semantikong kahulugan at hindi dapat gamitin para sa ibang layunin.

## Mga Dahilan

Napili ang gramatikang ito dahil:

* nagbibigay ito ng iisang kanonikal na representasyon ng session;
* malinaw ang paghihiwalay ng identity, system, node, domain, at context;
* sumusuporta ito sa parehong Appliance Mode at Multi-user Mode nang hindi binabago ang syntax;
* umaayon ito sa distributed architecture ng LNDH;
* nagbibigay ito ng matatag na pundasyon para sa session manager, prompt renderer, command parser, at iba pang bahagi ng SKLB;
* pinapanatili nito ang pare-parehong karanasan ng gumagamit sa lahat ng nodes ng sistema.

## Mga Bunga

### Positibo

* Nagiging pare-pareho ang representasyon ng session sa buong command operating environment.
* Hindi kailangang baguhin ang prompt grammar kapag nagdagdag ng user accounts, nodes, o bagong command domains.
* Nagiging mas malinaw ang kasalukuyang kalagayan ng session para sa gumagamit.
* Nagiging mas simple ang implementasyon ng session management at prompt rendering.

### Mga Limitasyon

* Hindi tinutukoy ng ADR na ito ang authentication, authorization, o permission model.
* Hindi rin nito tinutukoy ang command syntax, session lifecycle, o implementasyon ng session object.
* Ang eksaktong kahulugan ng bawat domain at context ay ilalarawan sa mga susunod na ADR at teknikal na espesipikasyon.

## Kaugnay na Desisyon

Ang ADR na ito ay nakabatay sa:

* **ADR-0001 — Salig bilang Root Command Environment at Session Manager**

At nagsisilbing pundasyon para sa mga susunod na desisyon tungkol sa:

* Domain and Context Model
* Session and Authentication Model
* Command Language Philosophy
* Prompt Grammar Specification

Ang detalyadong espesipikasyon ng prompt grammar, kabilang ang mga delimiter, mga panuntunan sa pagpapakita, at mga halimbawa ng paggamit, ay ilalarawan sa hiwalay na **Prompt Grammar Specification**. Ang ADR na ito ay nagsisilbing opisyal na talaan ng desisyong pang-arkitektura na nagtatatag ng iisang representasyon ng session sa loob ng SKLB.
