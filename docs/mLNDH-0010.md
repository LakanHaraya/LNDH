## *mLNDH-0010*

# 📦 MK Espesipikasyon ng Pakete ng Kontrol
*(Malayuang Kontroler → Pangunahing Sasakyan / Takad Daungan / Kontrol sa Lupa)*

---
---
---
- **May-akda:** L. H. Dima  
- **Bersiyon:** 0.1 — *Paunang Balangkas*  
- **Petsa:** Oktubre 2025  
- **Kodigo ng Dokumento:** `mLNDH-0010`  
- **Pag-uuri:** Panloob – Para sa Unang Yugto ng Pagpapaunlad  
- **Kaugnay na mga Dokumento:**  
  - `mLNDH-0001` – Pangkalahatang Arkitektura  
  - `mLNDH-0020` – Mga Depinisyon ng Flag  

Itinatakda ng dokumentong ito ang **estruktura, layunin, at siklo ng pagpapadala** ng *Control Packet* mula sa **MK (Malayuang Kontroler)** patungo sa mga yunit ng **PS**, **TD**, at **KL**. Layunin nitong magbigay ng pamantayan sa datos na ipinadadala sa pagitan ng mga bahagi ng sistema upang matiyak ang pagkakatugma ng firmware, komunikasyon, at debugging.

---
---
---

## 1. Panimula

Ang **Pakete ng Kontrol (Control Packet)** ay ang pangunahing *hamba ng datos (data frame)* na ipinapadala patungo sa iba't ibang yunit upang maisakatuparan ang mga utos ng piloto.

### 1.1 Mga Tumatanggap na Yunit
- **PS (Pangunahing Sasakyan)** – Tumanggap ng mga *real-time control commands* para sa paggalaw, direksiyon, tulok, at boyansi.
- **TD (Takad Daungan)** – Tumanggap ng mga *auxiliary control commands* para sa pagdaong, paglipad, o pagposisyon ng lunday.
- **KL (Kontrol sa Lupa)** – Tumanggap ng *status packets* mula sa MK bilang ulat ng aktuwal na estado ng mga kontrol, hindi bilang direktang utos.

### 1.2 Pagkakahiwalay ng Estruktura

Bagamat sabay-sabay at magkaparallel ang pagpapadala ng datos sa mga yunit na ito, **magkaiba ang layunin at bahagyang magkaiba ang estruktura ng mga pakete**:

| Daluyan | Uri ng Pakete | Nilalaman |
| --- | --- | --- |
| MK → PS | `MK_PS_Command` | Mga direktang utos ng piloto para sa propulsiyon, direksiyon, at altitud. |
| MK → TD | `MK_TD_Command` | Mga utos kaugnay ng pagdaong, paglipad, at posisyon ng pantalan o base. |
| MK → KL | `MK_KL_Status` | Impormasyong pansubaybay gaya ng kasalukuyang ipinadalang utos ng MK para sa PS at TD, bilang telemetriya at diyagnostika. |

### 1.3 Layunin ng Pakete
Layunin ng sistemang ito na:
- Magpasa ng *sabay-sabay na kontrol* sa PS at TD;
- Maghatid ng *katayuang pang-ulat* sa KL;
- Panatilihin ang *pagkakasabay-sabay* sa lahat ng hugpong ng network;
- Magbigay ng matatag na balangkas para sa pagproseso ng mga datos sa hinaharap (diyagnostika, kontrol na ginagabayan ng AI, atbp.).

---

## 2. Estruktura ng `ControlPacket`

Ang **`ControlPacket`** ay binubuo ng magkakasunod na bytes na ipinapadala mula sa **MK (Malayuang Kontroler)** patungo sa mga yunit ng PS, TD, at KL.

1. **Pamuhatan (`Header`)** – naglalaman ng pagkakakilanlan, oras, at uri ng pakete.
2. **Nilalaman (`Payload`)** – naglalaman ng aktuwal na datos ng kontrol o ulat, depende sa tatanggap.
3. **Pamakasan (`Trailer`)** – naglalaman ng pansuri sa ipinadalang datos.

### 2.1 Paghahamba (Framing) at Delimiter

Upang matukoy nang malinaw ang simula at dulo ng bawat pakete sa *serial* o *RF link,* ginagamit ang framing delimiter.
Ito ay kinakailangang hindi lumalabas sa karaniwang nilalaman ng mga byte.

### 2.1.1 Inirerekomendang Anyo

``` sh
[0x7E] [Pamuhatan] [Nilalaman] [Pamakasan] [0x7F]
```

| Simbolo | Byte | Tawag | Layunin |
| --- | --- | --- | --- |
| `[0x7E]` | 126 | Start Delimiter | Tanda ng simula ng pakete |
| `[0x7F]` | 127 | End Delimiter | Tanda ng pagtatapos ng pakete |

> **Tandaan:** Kung sakaling lumitaw ang `0x7E` o `0x7F` sa loob ng datos, gumamit ng **byte-stuffing** (hal. ipasok ang `0x7D` bilang escape byte at i-XOR sa `0x20` ang kasunod).  
>
> Ang ganitong framing ay tugma sa mga radio modules gaya ng **HC-12**, **LoRa**, o **NRF24L01**, at sa karaniwang **Serial** transmission.


### 2.2  Pamuhatan ng Pakete (`MK_Header`)

| Larang | Laki | Uri | Halimbawa | Paglalarawan |
|-------|------|------|------------|---------------|
| `id` | 1 B | `uint8_t` | `0xA1` | Natatanging ID ng tagapagdala ng pakete (MK unit) |
| `timestamp` | 4 B | `uint32_t` | `20251011T102312Z` | Oras ng paglikha ng pakete (UNIX epoch o ISO 8601) |
| `type` | 1 B | `uint8_t` | `0x01` | Uri ng pakete: `0x01=PS_CMD`, `0x02=TD_CMD`, `0x03=KL_STAT` |

### 2.3 Nilalaman ng Pakete (Magkakaiba)

#### 2.3.1. `MK_PS_Command`
Utos para sa **Pangunahing Sasakyan** – tumutukoy sa mga pangunahing utos gaya ng *tulok, timon, boyansi, at iba pa*.

| Larang | Laki | Saklaw | Nakatakda | Paglalarawan |
|--------|------|--------|----------|---------------|
| `PScmd_flags` | 1 B | bits | `0x00` | Mga espesyal na bit (arm, disarm, override, atbp.) |
| `thrust` | 1 B | 0 – 255 | 128 | Kontrol sa lakas ng propeller; <br> 0 = paurong, 128 = matamlay, 255 = pasulong |
| `rudder` | 1 B | 0 – 255 | 128 | Kontrol sa pagliko ng lunday; <br> 0 = pakaliwa, 128 = tuwid, 255 = pakaliwa |
| `elevator` | 1 B | 0 – 255 | 128 | Kontrol sa pagtango ng lunday; <br> 0 = payuko, 128 = matamlay, 255 = paliyad |
| `swiveller` | 1 B | 0 – 255 | – | Kontrol sa anggulo ng nakavektor na pantulok; <br> 0 = pahiga, 255 = patayo |
| `ballonet` | 1 B | 0 – 255 | – | Kontrol sa antas ng hangin sa ballonet; <br> 0 = paimpis, 255 = papintog |

---

#### 2.3.2. `MK_TD_Command`
Utos para sa **Takad Daungan** – tumutukoy sa pagposisyon, paglipad, o pagdaong ng lunday.

| Larang | Laki | Saklaw | Nakatakda | Paglalarawan |
|--------|------|--------|----------|---------------|
| `TDcmd_flags` | 1 B | bits | `0x00` | Mga kontrol sa kaligtasan at override |
| `dock_cmd` | 1 B | 0 – 3 | 0 | 0 = manwal, 1 = kusandaong, 2 = ilunsad, 3 = kapit |
| `winch_cmd` | 1 B | 0 – 255 | 0 | Bilis/direksiyon ng tangkalag para sa tali o kable <br> 0 = palapit, 255 = palayo |

---

#### 2.3.3. `MK_KL_Status`
Impormasyong ipinadadala sa **Kontrol sa Lupa** para sa telemetriya at diyagnostika.

| Larang | Laki | Saklaw | Nakatakda | Paglalarawan |
|--------|------|------|-------|--------|
| `PScmd_flags` | 1 B | bits | `0x00` | Mga espesyal na bit (arm, disarm, override, atbp.) |
| `thrust` | 1 B | 0 – 255 | 128 | Kontrol sa lakas ng propeller; <br> 0 = paurong, 128 = matamlay, 255 = pasulong |
| `rudder` | 1 B | 0 – 255 | 128 | Kontrol sa pagliko ng lunday; <br> 0 = pakaliwa, 128 = tuwid, 255 = pakaliwa |
| `elevator` | 1 B | 0 – 255 | 128 | Kontrol sa pagtango ng lunday; <br> 0 = payuko, 128 = matamlay, 255 = paliyad |
| `swiveller` | 1 B | 0 – 255 | – | Kontrol sa anggulo ng nakavektor na pantulok; <br> 0 = pahiga, 255 = patayo |
| `ballonet` | 1 B | 0 – 255 | – | Kontrol sa antas ng hangin sa ballonet; <br> 0 = paimpis, 255 = papintog |
| `TDcmd_flags` | 1 B | bits | `0x00` | Mga kontrol sa kaligtasan at override |
| `dock_cmd` | 1 B | 0 – 3 | 0 | 0 = manwal, 1 = kusandaong, 2 = ilunsad, 3 = kapit |
| `winch_cmd` | 1 B | 0 – 255 | 0 | Bilis/direksiyon ng tangkalag para sa tali o kable <br> 0 = palapit, 255 = palayo |
| `MKbatt` | 1 B | % | – | Natitirang lakas ng baterya ng MK |
| `link_quality` | 1 B | % | – | Lakas ng koneksiyon sa network |
| `MKstatus_flags` | 1 B | bits | – | Mga indikador: low-bat, comm-loss, sensor-error, atbp. |

### 2.4 Pamakasan ng Pakete (`MK_Trailer`)
| Larang | Laki | Uri | Halimbawa | Paglalarawan |
|-------|------|------|------------|---------------|
| `checksum` | 1 B | `uint8_t` | – | Pansuri ng bisa (simple XOR o CRC-8) |

### 2.5 Kabuoang Haba ng mga Pakete

| Uri ng Pakete | Laki (bytes) | Kabuoan kasama ang delimiter |
|----------------|-------|-------|
| `MK_PS_Command` | 13 B | 15 B (may `0x7E`, `0x7F`) |
| `MK_TD_Command` | 10 B | 12 B |
| `MK_KL_Status` | 19 B | 21 B |

Ang mga dagdag ng 2 bytes mula sa delimiter ay maliit na overhead lamang ngunit malaki ang tulong sa *pagkakasaby-sabay ng pakete*.

### 2.6 Kakayahan ng Arduino Nano ESP32

Ang **Arduino Nano ESP32** ay may higit na sapat na kakayahan upang hawakan ang naturang mga pakete:

- **RAM:** ≈ 320 KB
- **Flash:** ≈ 1.5 MB
- **Serial baudrate:** hanggang 2 Mbps (maaaring itakda sa 115200 bps pataas)
- **Average packet rate:** kahit 20–50 packets/second (20ms na agwat) ay ligtas; sa mas mababang 1000 ms na agwat, **napakaluwag pa ng latency**.

Kahit na sabay na dumadaloy ang tatlong direksiyon (PS, TD, KL), hindi lalampas sa 1KB/s ang kabuoang daloy ng datos — kaya magaan ito para sa sapad.

### 2.7  Format ng Pagpapadala

``` txt
[0x7E] [Pamuhatan] [Nilalaman] [Pamakasan] [0x7F]
```

Halimbawa sa `MK_PS_Command`:

``` txt
7E A1 65 32 10 01 80 80 80 80 80 80 5F 7F
```

---

### 2.8 Integridad ng Datos ng Pakete ng Kontrol
<!--
*Tandaan:*  
Kung sa hinaharap ay ipatutupad ang iisang CRC scheme sa lahat ng yunit ng LNDH System (MK, PS, TD, KL, at iba pa), maaaring ilipat ang seksiyong ito sa hiwalay na dokumento gaya ng `mLNDH-00XX: Data Integrity and CRC Specification` para sa sentralisadong pamantayan.
-->

Upang matiyak ang kawastuhan ng datos na ipinapadala ng **MK (Malayuang Kontroler)** sa mga yunit ng **PS**, **TD**, at **KL**, ang bawat pakete ay tinatapos sa isang **CRC-8 checksum** na nagsisilbing pansuri ng integridad ng ipinadalang datos.

#### 2.8.1 Layunin
Ang CRC-8 ay ginagamit upang matukoy kung nagkaroon ng anumang *bit error* habang ipinapadala ang pakete sa serial o wireless na daluyan.  
Dahil walang *handshake* o *acknowledgement* na mekanismo sa pagitan ng MK at mga tatanggap nito, mahalaga ang pagkakaroon ng **lightweight error detection** upang mapanatiling ligtas at matatag ang transmisyon.

#### 2.8.2 Pamamaraan

- **Algorithm**: CRC-8, polynomial `0x07` ($x⁸ + ... + x² + x + 1$)  
- **Initial Value**: `0x00`  
- **Input Range**: Lahat ng bytes mula *Pamuhatan* (`Header`) hanggang sa *Nilalaman* (`Payload`), hindi kasama ang CRC byte.  
- **Output**: 1 byte (`uint8_t`) na idinadagdag bilang huling bahagi ng *Pamakasan* (`Trailer`).

Ang CRC ay binibilang ng tagapagdala (MK) at ipinapadala kasabay ng bawat pakete.  
Tinitiyak ng tagatanggap (PS, TD, o KL) na pareho ang kalkuladong CRC sa natanggap na CRC upang mapatunayang buo at tama ang datos.

#### 2.8.3 Mga Dahilan ng Pagpili sa CRC-8

| Katangian | Paliwanag |
|:--|:--|
| **Magaan sa CPU** | Ang CRC-8 ay mabilis kalkulahin kahit sa *tableless implementation*; mainam sa `Arduino Nano ESP32`. |
| **Mababang Overhead** | 1 byte lamang ang dagdag sa bawat pakete (≈3% overhead sa 30-byte packet). |
| **Epektibong Proteksiyon** | Natutukoy ang lahat ng *single-bit* at *double-bit* errors, at karamihan ng *burst errors* ≤ 8 bits. |
| **Angkop sa Real-Time** | Tugma sa *fire-and-forget* na transmisyon na walang retransmission o ack system. |

#### 2.8.4 Mga Pagpapalawig (Opsiyonal)

Kung sakaling kailanganin ng mas mataas na antas ng integridad sa komunikasyon (hal. para sa *critical safety commands* o *telemetry verification*), maaaring gamitin ang mga sumusunod na pagpapalawig:

- Paglipat sa **CRC-16 (poly 0x1021)** para sa mas mataas na proteksiyon laban sa mga *burst errors*; o  
- Pagdagdag ng *sequence counter* at *error flag feedback* mula sa tatanggap, kung papayagan na ang *acknowledged link* sa susunod na bersiyon.

#### 2.8.5 Buod

Ang paggamit ng **CRC-8** bilang pansuri ng integridad ng ipinadalang datos ay nagbibigay ng balanseng *bilis*, *simple*, at *maaasahan* para sa tuloy-tuloy na transmisyon ng datos ng MK patungo sa mga yunit ng PS, TD, at KL.  
Ito ay inirerekomendang panatilihin sa kasalukuyang arkitektura ng `ControlPacket` habang walang nakatalagang *acknowledgement system*.

---

## 3. Ang Kahulugan ng mga Flag
<!-- Tandaan
Huwag kalimutan isapanahon ang mga kaugnay na dokumento ng malapamantayan.
-->

Ang kahulugan ng mga *command flag* (tulad ng `PScmd_flags` at `TDcmd_flags`) ay hindi tinatalakay sa dokumentong ito. Ang mga ito ay itinatakda at ipinaliliwanag nang buo sa dokumentong `mLNDH-00XX`: Mga Depinisyon ng MK Flag (o katumbas kapag natukoy na ang opisyal na kodigo).

---

## 4. Siklo ng Pagpapadala

Itinatakda sa seksiyong ito ang tipikal na dalas ng pagpapadala ng bawat uri ng pakete, bilang gabay sa disenyo ng tatagsil ng MK.

| Aytem | Agwat | Funsiyon |
| --- | --- | --- |
| Pakete ng Kontrol (MK → PS) | 20–50 ms (operasyon) <br> 1000 ms (prototipo) | `sendControlToPS()` |
| Pakete ng Kontrol (MK → TD) | 100–200 ms | `sendControlToTD()` |
| Pakete ng Katayuan (MK → KL) | 500–1000 ms | `sendStatusToKL()` |
| Midyum ng Transmisyon | Wireless link *(hal. ESP-NOW, LoRa, o Wi-Fi)* | Isang-tunguhan na brodkast (*one-way broadcast*) |

> **Tala:**
> Sa prototipo, ginagamit pa lamang ang Serial print bilang emulasyon ng wireless link.

Ang **MK** ay patuloy na nagpapadala ng mga *control packet* sa mga katugmang yunit nang walang *acknowledgement handshake*. Dahil dito, inaasahan na ang transmisyon ay **mabilis at magaan**, ngunit ang pagtukoy ng error (CRC-8) sa bawat pakete ang nagsisiguro sa integridad ng datos.

Sa aktuwal na deployment, ang agwat ng pagpapadala ay maaaring **adaptibo**, batay sa bilis ng pagbabago ng mga input ng piloto at sa kondisyon ng koneksiyon.

---

## 5. Mga Susunod na Pagpapalawak

Ang mga sumusunod na pagpapalawak ay itinuturing na bahagi ng mga susunod na yugto ng *MK Control Packet*:

- **Pagpapaunlad ng CRC scheme**
    - Pagsusuri sa paglipat mula CRC-8 patungong CRC-16 kung kinakailangan ng mas mahaba o mas kritikal na transmisyon.

- **Compression ng Data Frame**
    - Pagpapababa ng kabuoang haba ng pakete upang mapabilis ang pagpapadala sa mga mabagal na *wireless links*.

- **Pagdaragdag ng Sequence Number o Timestamp**
    - Para sa mas mahusay na pagkilala ng mga pakete sa pagtanggap, at potensiyal na *replay protection* sa hinaharap.

- **Dynamic Packet Sizing**
    - Pagbibigay-daan sa mga opsiyonal na *modules* gaya ng ilaw (lighting), *camera gimbal*, o telemetry extensions.

- **Encryption at Authentication (Opsiyonal)**
    - Pagsusuri sa paggamit ng magaan na *encryption layer* para sa seguridad sa mga wireless channel.

Ang mga pagpapalawak na ito ay isasama sa mga hiwalay na pamantayang dokumento (`mLNDH-XXXX` series) kapag natukoy na ang kani-kanilang disenyo.

---

## 6. Sanggunian at mga Kaugnay na Dokumento

Ang mga sumusunod na dokumento ay nagbibigay ng karagdagang detalye o kaugnay na kahulugan sa mga bahagi ng sistemang MK:

| Kodigo | Pamagat | Paglalarawan |
|:--|:--|:--|
| `mLNDH-0010` | *MK Espesipikasyon ng Pakete ng Kontrol* | (Kasalukuyang dokumento) — inilalarawan ang estruktura at transmisyon ng mga pakete ng kontrol mula sa MK patungo sa PS, TD, at KL. |
| `mLNDH-00XX` | *Mga Depinisyon ng MK Flag at Paraan ng Kontrol* | Itinatakda ang kahulugan at operasyon ng `PScmd_flags` at `TDcmd_flags`. |
<!-- 
| `mLNDH-00XX` | *Wireless Link Protocol* | Naglalarawan ng pisikal at lohikong antas ng komunikasyon sa pagitan ng MK at mga tumatanggap (Serial, RF, o Wi-Fi-based). |
| `mLNDH-00XX` | *Telemetry and Diagnostic Format* | Itinatakda ang balangkas ng pag-uulat mula sa KL pabalik sa MK. |
-->

> **Tala:**  
> Ang bawat dokumento sa serye ng `mLNDH-XXXX` ay maaaring baguhin o palawakin alinsunod sa pag-unlad ng materyil (*hardware*) at tatagsil (*firmware*) ng MK.

---
---

### *Kasaysayan ng Dokumento*

| Bersiyon | Petsa      | Pagbabago |
| ------- | ---------- | ------- |
| 0.1     | 2025-10-12 | Unang bersiyon ng ineeksperimentong pakete ng kontrol |
