LundayHangin (LNDH)   
**Dokumento:** mLNDH-0001   
**Katayuan:** Balangkas  
**Kategorya:** Panimulang Sanggunian  

L. H. Dima  
Purok Labimpito  
Enero 2026

---

<h1 align="center">Pangkalahatang Tanaw ng LundayHangin</h1>


## Abstrak

Ang mLNDH-0001 ay naglalahad ng pangkalahatang layunin,
saklaw, at prinsipyong gumagabay sa Proyektong LundayHangin (LNDH),
isang modular na proyektong dron na nakabatay sa lundayhangin (airship) at
idinisenyo para sa pag-aaral at praktikal na aplikasyon ng inhenyeriya
ng sistema at sistemang nakalubog (embedded systems).

Inilalarawan ng dokumentong ito ang hangganan ng proyekto, ang konsepto
ng Pinakamunting Mabisang Sistema (PMMS), ang pangunahing segmentong
pang-operasyon, at ang mga prinsipyong pangkaligtasan at dokumentasyon
na sinusunod sa buong siklo ng buhay ng sistema.

## Katayuan ng Dokumentong Ito

Ang dokumentong ito ay isang **balangkas** at nagsisilbing panimulang
sanggunian at batayang dokumento ng serye ng malapamantayan (**mLNDH**)
ng Proyektong LundayHangin (LNDH). Ito ay inilaan para sa panloob na
paggamit ng proyekto at maaaring baguhin o palawakin habang umuunlad
ang sistema.

Ang dokumentong ito ay hindi bumubuo ng eksternal na pamantayang panregulasyon. Ito ay malayang maipamahagi sa loob ng konteksto ng proyekto.

---

## 1. Layunin

Ang dokumentong **mLNDH-0001** ay nagsisilbing unang opisyal na sanggunian ng
**Proyektong LundayHangin (LNDH)**. Nilalayon nitong magbigay ng malinaw,
obhetibo, at mataas na antas ng paglalarawan ng proyekto, sapat upang:

- maunawaan ang kabuoang layunin at saklaw ng sistema,
- magsilbing panimulang batayan para sa mga susunod na teknikal na dokumento, at
- magtakda ng pamantayang maihahambing sa industriya at propesyonal na inhenyeriya, ngunit angkop sa antas ng proyektong ito.

Ang dokumentong ito ay *hindi* detalyadong disenyo, *hindi* manwal ng gagamit, at *hindi* gabay sa implementasyon. Ito ay isang **antas na pantanaw sa proyekto** na naglalahad ng kung ano ang binubuo ng proyekto at kung paano ito lalapitan sa sistematikong paraan.

## 2. Paglalarawan

Ang **LundayHangin (LNDH)** ay isang modular na proyektong dron panghimpapawid na
idinisenyo para sa pag-aaral, eksperimento, at praktikal na aplikasyon ng mga 
prinsipyo ng:

- pisika at aerodinamika ng mga sasakyang mas-magaan-sa-hangin (physics and aerodynamics of lighter-than-air vehicles),
- inhenyeriya ng elektrikal at disenyo ng elektronikong sirkito (electrical engineering and electronic circuit design),
- sistemang nakalubog (embedded systems),
- arkitektura ng nakapamahaging kontrol (distributed control architectures),
- inhenyeriya ng sistema (systems engineering), at
- disenyong nakatuon sa kaligtasan (safety-oriented design).

Bagamat pang-aliwan ang antas ng proyekto, ang LNDH ay sinadyang idinisenyo
gamit ang propesyonal na disiplina sa pagbuo ng sistema, kabilang ang
dokumentasyon, kontrol ng bersiyon, at malinaw na paghihiwalay ng tungkulin
ng bawat bahagi.

## 3. Saklaw at Hangganan

### 3.1 Saklaw

Sinasaklaw ng LNDH ang disenyo at pagbuo ng isang platapormang panghimpapawid batay sa lundayhangin (airship) na may:

- pangunahing kakayahan na lumipad at manatiling matatag,
- kontroladong paggalaw at direksiyon,
- ligtas at planadong pagbaba, at 
- kakayahang subaybayan at kontrolin mula sa lupa.

### 3.2 Hindi Saklaw

Sa unang yugto ng proyekto, hindi saklaw ang:

- ganap na awtonomiya,
- masulong na katalinuhang artipisyal, at
- sertipikasyong komersiyal o pag-aproba sa regulatoryo.

Ang mga ito ay maaaring isaalang-alang sa mga susunod na yugto ngunit hindi
bahagi ng kasalukuyang batayan.

## 4. PMMS – Pinakamunting Mabisang Sistema

Ang paunang implementasyon ng LNDH ay ibinabatay sa konsepto ng **PMMS (Pinakamunting Mabisang Sistema)**.

Ang PMMS ay tumutukoy sa pinakasimpleng anyo ng sistema na:

- kayang patunayan ang pangunahing arkitektura,
- nakakatugon sa mga batayang kinakailangan sa kaligtasan, at
- nagbibigay ng matibay na pundasyon para sa pagpapalawak.

Ang anumang kakayahang hindi kritikal sa ligtas na operasyon ay sadyang ipinagpapaliban sa mga susunod na bersiyon.

## 5. Pangkalahatang Arkitektura ng Sistema (Segmentong Pang-operasyon)

Ang LNDH ay binubuo ng **apat (4) na pisikal na bahagi**, na magkakaugnay
ngunit may malinaw na hangganan ng tungkulin. Ang mga ito ay kolektibong tinutukoy bilang *LNDH Segmentong Pang-operasyon*:

1. **`sPS` – Pangunahing Sasakyan (*Primary Aerial Segment*)**
    
    Ang mismong dron ng lundayhangin na naglalaman ng mga sistemang kritikal sa paglipad at kaligtasan.

2. **`sMK` – Malayuang Kontroler (*Remote Control Segment*)**
    
    Ang sangrabaw (interface) ng opereytor para sa manwal na utos at pangunahing interaksiyon.

3. **`sTD` – Takad Daungan (*Docking and Support Segment*)**
    
    Ang pisikal na daungan para sa pagparada, pagkakarga (charge), at suporta ng operasyon.

4. **`sKL` – Kontrol sa Lupa (*Ground Control Station Segment*)**
    
    Ang sistema para sa pagsusubaybay, diyagnostika, at pagpaplano sa antas ng misyon.

## 6. Prinsipyo sa Kaligtasan at Disenyo

Ang LNDH ay tumatalima sa mga sumusunod na prinsipyong pangkaligtasan:

- malinaw na paghihiwalay ng **bital** at **di-bital** komponent,
- **ligtas-sa-pagkabigo** (fail-safe) bilang nakatakdang estado, 
- **marikit na degradasyon** sa harap ng pagkabigo, at
- deterministikong asal ng mga bahagi na kritikal sa kaligtasan.

Ang kaligtasan ay itinuturing na pangunahing kahingian ng disenyo, at hindi
isang karagdagang tampok.

## 7. Pamantayan sa Pagpapaunlad at Dokumentasyon

### 7.1 Pamantayan sa Pagpapaunlad ng Sistema

Ang proyektong LNDH ay sumusunod sa kinikilalang mabubuting gawi
(best practices) sa pagpapaunlad ng mga sistemang binubuo ng
**software at hardware**. Ang mga disiplinang ito ay itinuturing na magkakaugnay
at pinamamahalaan sa ilalim ng iisang balangkas ng inhenyeriya ng sistema.

Kabilang sa mga pamantayang ito ang:

- malinaw at deterministikong asal ng mga bahaging kritikal sa kaligtasan,
- malinaw na paghihiwalay ng lohika, kumpigurasyon, at akses sa pisikal na kagamitan,
- paggamit ng neutral at teknikal na terminolohiya sa pagbibigay ng pangalan,
- sistematikong kontrol ng bersiyon at nababakas na kasaysayan ng pagbabago, at
- dokumentasyon bilang primera-klaseng bahagi ng sistema, kapantay ng mismong implementasyon.

Ang mga pamantayang ito ay ipinatutupad upang matiyak ang kalidad, kaligtasan, at pangmatagalang pagpapanatili ng proyekto.

### 7.2 Wikang Gagamitin sa Dokumentasyon

Ang pangunahing wikang gagamitin sa proyektong ito ay **wikang Filipino**.

Ito ay ilalapat sa:

- teknikal na dokumentasyon
- paliwanag ng disenyo at arkitektura, at
- mga komento sa loob ng source code.

Ang wikang Ingles ay gagamitin lamang kung:

- ito ay bahagi ng mismong sintaksis o susing-salita ng wikang pamprograma, o
- kinakailangan para sa pakikipag-ugnayan sa eksternal na modyul, kasangkapan, o pamantayan.

## 8. Antas ng Dokumento at Mga Susunod na Hakbang

Ang dokumentong ito ay nagsisilbing panimulang sanggunian at
batayang punto ng buong hanay ng dokumentasyon ng Proyektong LundayHangin.
Ito ay kabilang sa antas ng **pangkalahatang tanaw**, at hindi naglalaman
ng detalyadong teknikal na espesipikasyon.

Mula dito ay lilikhain ang mga karagdagang dokumento na maaaring kabilang sa:

- mga depinisyon at saklaw ng sistema,
- arkitektura at disenyo ng mga bahagi at ugnayan nito,
- mga prinsipyo at patakaran sa kaligtasan at disiplina ng inhenyeriya,
- mga pamantayan at mabubuting kasanayan (best practices) sa
  pagpapaunlad ng software at hardware,
- mga plano at pamamaraan para sa pagsubok, beripikasyon, at pagbabago; at
- mga gabay sa pagpapanatili at pagpapalawak ng sistema.

Ang lahat ng susunod na dokumento ay inaasahang magiging konsistent sa mga
prinsipyo, saklaw, at layuning inilatag sa dokumentong ito at bubuo ng iisang magkakaugnay na balangkas ng dokumentasyon.

## 10. Kasaysayan

- **v0.1.0** – Paunang balangkas ng dokumento. *(2025-02-01)*
- **v0.1.1** – Munting pagsasaayos ng balangkas. *(2025-04-01)*