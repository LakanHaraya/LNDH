# PARAMDATOS: *Gabay sa Arkitektura ng Mga Parametro ng Datos*

Ang dokumentong ito ay nagsisilbing opisyal na talaan ng mga parametro at
pagbabago sa arkitektura ng datos ng bawat yunit sa ilalim ng proyekto.
Nilalayon nitong magbigay ng malinaw na sanggunian para sa mga tagabuo,
tagapagsubok, at tagapanatili ng sistema, upang masubaybayan ang ebolusyon ng
mga kontrol at kakayahan ng bawat bersiyon.

---

## [`MK-PARAMDATOS@0.1.0`] – MK-PMMS : Malayuang Kontroler – Pinakamunting Mabisang Sistema

Ang *Malayuang Kontroler – Pinakamunting Mabisang Sistema* (PS-PMMS) ang
nagsisilbing **base o unang bersiyon** ng bawat yunit. Sa antas na ito,
tinutukoy ang mga pangunahing parametro para sa operasyon at kontrol, kabilang
ang propulsion, direksiyon, thrust vectoring, at mga pangunahing mode ng
sistema. Ang mga talahanayan sa bahaging ito ay naglalarawan ng aktibong mga
parametro, kanilang kodigo, saklaw ng halaga, paliwanag, at layunin. Ang
MK-PMMS ang pundasyon kung saan ibabatay ang lahat ng susunod na pagpapalawak o
pagbabago sa arkitektura ng datos.

| **Parametro** *(Direksiyon)* | **Kodigo** | **Halaga o Saklaw** | **Paliwanag** | **Dahilan** |
| --- | --- | --- | --- | --- |
| `throttle` <br> *ipapadala patungo sa PS at KL* | `MK_THR` | 0–100 (%) | Kinakatawan ang average na bilis ng kaliwa at kanang brushless DC motors sa pangunahing shaft. Maaaring isama ang internal differential para sa yaw o roll control. | Pangunahing utos para sa forward propulsion. Pinagsama upang mabawasan ang system complexity at mapanatili ang balanseng thrust sa unang bersiyon. |
| `rudder_angle` <br> *ipapadala patungo sa PS at KL* | `MK_RUD` | –45 hanggang 45 (°) | Kontrol sa sabayang galaw ng upper at lower rudders sa fins para sa yaw control. | Pinagsama upang mapadali ang direksiyon at maiwasan ang labis na stress sa mga fins. |
| `elevator_angle` <br> *ipapadala patungo sa PS at KL* | `MK_ELE` | –45 hanggang 45 (°) | Kontrol sa sabayang galaw ng left at right elevators sa horizontal tails para sa pitch control. | Tinutulungan ang altitude stability at iniiwasan ang labis na dive o ascent. |
| `swivel_angle` <br> *ipapadala patungo sa PS at KL* | `MK_SWV` | 0–90 (°) | Kontrol sa swivelling mechanism ng motor shaft para sa thrust vectoring. | Pinapayagan ang direktang pag-adjust ng thrust direction para sa mas episyenteng paggalaw at hovering. |
| `mode_switch` <br> *ipapadala patungo sa PS at KL* | `MK_MOD` | 0–3 (e.g., <br> 0=idle, <br> 1=manual, <br> 2=stabilize, <br> 3=RTL) | Pagpili ng flight mode ng sistema. | Nagbibigay ng kontrol sa antas ng automation at fail-safe operations, kabilang ang idle mode para sa ligtas na pagsisimula. |
| `takeoff_command` <br> *ipapadala patungo sa PS at KL* | `MK_TKO` | true/false | Command signal para sa pagsisimula ng pag-alis mula sa lupa.  | Nagsisilbing simpleng trigger na may mga pre-check bago ang operasyon. |
| `heartbeat` <br> *ipapada patungo sa PS at KL* | `MK_HBT` | Timestamp (Unix seconds) | Regular na signal para sa koneksyon at system monitoring. | Ginagamit upang matukoy ang konektibidad at pag-andar ng mga pangunahing bahagi. |


---

## [Darating] – Mga Pagpapalawak at Bagong Parametro

Ang bahaging ito ay nakalaan para sa mga paparating na bersiyon o *development
stages* ng sistema. Dito itinatala ang mga bagong parametro na planong
**idadagdag**, **palalawakin**, o **papalitan** batay sa PMMS base
configuration. Bawat item ay minarkahan ng katumbas na tag gaya ng [Idadagdag],
[Papalitan], o [Tatanggalin] upang malinaw na matukoy ang uri ng pagbabago.
Nilalayon ng seksiyong ito na mapanatili ang maayos na dokumentasyon ng mga
update at mapadali ang pagsasabay ng hardware at software sa susunod na mga
yugto ng pag-unlad.

| **Parametro** | **Kodigo** | **Halaga o Saklaw** | **Paliwanag** | **Dahilan** |
| --- | --- | --- | --- | --- |
| `buoyancy_valve` [Idadagdag] | `MK_BUV` | 0–50 (%)  | Kontrol sa gas release valve ng envelope para sa pagsasaayos ng lift o buoyancy level. | Idadagdag upang mapahusay ang kakayahan sa fine-tuning ng buoyancy. Hindi isinama sa PMMS base upang mapanatiling simple ang unang bersiyon. |
| `emergency_stop` [Idadagdag] | `MK_EMS` | true/false | Command na agad nagse-set ng zero output sa lahat ng actuators. | Idadagdag bilang karagdagang safety feature para sa mga vectored systems at emergency response. |
| `led_mode` [Idadagdag] | `MK_LMD` | 0–5 (e.g., <br> 0=off, <br> 1=steady, <br> 2=flash) | Kontrol sa LED lighting pattern para sa visibility at status indication. | Idadagdag upang suportahan ang operasyon sa mababang liwanag at magbigay ng visual status feedback. |

