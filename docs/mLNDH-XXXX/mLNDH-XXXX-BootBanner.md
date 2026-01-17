LundayHangin (LNDH)   
**Dokumento:** mLNDH-XXXX-BootBanner  
**Katayuan:** Balangkas  
**Kategorya:** Teknikal 

L. H. Dima  
Purok Labimpito  
Enero 2026

---

<h1 align="center">Paskil Pambungad</h1>

## 1. Layunin at Prinsipyo ng Paskil Pambungad

### 1.1 Layunin 

Ang paskil pambungad ay dapat:
- Magpakilala ng node identity
- Magpahayag ng estado ng sistema sa bungad (boot)
- Magbigay ng diagnostic minimum (hindi log dump)
- Maging pare-pareho ngunit may personalidad ayon sa tungkulin

### 1.2 Prinsipyo
- Deterministiko: parehong format, parehong pagkakasunod.
- Readable sa serail: walang sobrang arte.
- Language-consistent: Filipino bilang pangunahing wika, teknikal kung kailangan.
- Tahimik kapag maayos: walang drama kung walang problema.

---

## 2. Iminumungkahing Karaniwang Balangkas ng Paskil Pambungad

Ito ang parehong estruktura para sa PS, MK, TD, at KL:
``` sh
========================================
 LNDH :: <NODE-CODE> :: <NODE-NAME>
----------------------------------------
 Role        : <maikling papel>
 Firmware    : <version> (<git/commit>)
 Build       : <date> <time>
 Board       : <mcu / platform>
----------------------------------------
 Takna       : <ISO-8601 | di-balido>
 Time Q      : <0-3> (<kahulugan>)
 Uptime      : <monotonic ms>
----------------------------------------
 Status      : INIT | READY | DEGRADED
========================================
```

**Tandaan:**
- Ang paggamit ng `Takna` dito ay akma at eleganteng pagpapatunay na arkitektural ang oras sa LNDH, hindi lang utility.

---

## 3. Pag-angkop sa Bawat Sugpong

### 3.1 PS — *Pangunahing Sasakyan*

Diin: Kaligtasan, awtonomiya, at kritikal na subsistema

Dagdag na linya (opsiyonal):
``` sh
 Flight Mode : SAFE | MANUAL | AUTO
 Sensors     : OK | PARTIAL | FAIL
```

Tono: konserbatibo at seryoso

---

### 3.2 MK — *Malayuang Kontroler*

Diin: ugnayan at kontrol

Dagdag:
``` sh
 Link State  : DISCONNECTED | PAIRING | LINKED
 Peer        : PS-<id> | NONE
```

Tono: malinaw at komunikatibo

---

### 3.3 TD — *Takdang Daungan*

Diin: imprastraktura at lokasyon

Dagdag:
``` sh
 Bay Status  : EMPTY | DOCKED | ERROR
 Power       : MAINS | BATTERY
```

Tono: neutral at operasyonal

---

### 3.4 KL — *Kontrol sa Lupa*

Diin: pangangasiwa at pangkalahatang tanaw

Dagdag:
``` sh
 Nodes Seen  : PS MK TD
 Alerts      : 0
```

Tono: supervisory

---

## 4. Usaping Disenyo at Pasiya

ASCII Art?
- Minimal lang, pare-pareho sa lahat.
- Iwasan ang malalaking logo, sayang UART space, sayang oras.

Wika
- Filipino bilang default, English teknikal kung kailangan
- Ito ay tahimik na pahayag ng identidad ng proyekto

Machine-Readable?
- Panatilihin ang `key : value` format.
- Walang emoji sa banner (emoji sa dokumento lang 😄)

---

##5. Paunang Pasiya (Panukala)

Pasiya:
> Magpatibay ng iisang boot banner template para sa lahat ng LNDH nodes, na may limitadong node-specific extensions, at obligadong isama ang estado ng Takna bilang bahagi ng arkitektural na identidad ng sistema.