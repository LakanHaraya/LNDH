# 🌬️ LNDH — <span style="font-family:Pabs Pinagandang Sulat; font-size:30px;">*LundayHangin*</span>

Ang **LNDH (*<span style="font-family:Pabs Pinagandang Sulat; font-size:18px;">*LundayHangin*</span>*)** ay isang **maramihang-yunit na proyektong panghimpapawid** na layong bumuo ng isang *airship drone system*.  
Bawat yunit ay may kani-kaniyang tungkulin ngunit nakikipag-ugnayan sa isa’t isa bilang iisang buo.

---

## 🎯 Layunin

- Magkaroon ng **Pangunahing Sasakyan** na kayang lumipad at magsagawa ng misyon.  
- Magkaroon ng **Malayuang Kontroler** para sa manwal at malaawtonomong pagkontrol.  
- Magkaroon ng **Takad Daungan** para sa ligtas na paglapag at pagkarga.  
- Magkaroon ng **Kontrol sa Lupa** bilang estasyon ng pagmamanman at pagpaplano ng misyon.  
- Magkaroon ng **lugar pansubok (TEST)** para sa mabilis na pag-eeksperimento ng mga algoritmo at aklatan.  

Sa kabuoan, layunin nitong magbigay ng **isang malinaw, modular, at madaling paunlarin** na sistemang pangdron.

---

## 📂 Estruktura ng Folder

``` txt
LNDH/
 ├─ .pio/
 ├─ .vscode/
 ├─ docs/
 ├─ include/
 ├─ lib/
 ├─ src/
 ├─ test/
 ├─ .gitignore
 ├─ platform.ini
 └─ README.md
```

- `LNDH/` – Ang pangunahing lalagyan ng buong proyekto ng *LundayHangin*, kung saan nagkakatipon ang firmware, dokumentasyon, kumpigurasyon, at kasaysayan ng pag-unlad ng sistema sa isang maayos at masusubaybayang estruktura.

    - `.pio/` – Awtomatikong nililikha ng PlatformIO at naglalaman ng mga build artifact, dependency cache, at environment-specific outputs.
    - `.vscode/` – Lokal na kumpigurasyon ng Visual Studio Code at PlatformIO extension (tasks, settings, at workspace metadata).
    - `docs/` – Pormal na dokumetasyon ng proyekto, kabilang ang mLNDH references, disenyo, at tala ng desisyon.
    - `include/` – Pampublikong header files na bumubuo sa opisyal na Application Programming Interface (API) ng LNDH firmware.
    - `lib/` – Mga third-party o internal libraries na hiwalay ang lifecycle at maaaring i-reuse sa ibang proyekto.
    - `src/` – Pangunahing source code ng firmware, hinati ayon sa common modules at role-specific implementations.
    - `test/` – Kaligirang pansubok para sa sandbox code, eksperimento, at unit o integration tests.
    - `.gitignore` – Talaan ng mga file at folder na hindi isinasama sa version control.
    - `platform.ini` – Sentral na kumpigurasyon ng build, environment, at role mapping ng PlatformIO.
    - `README.md` – Pambungad at mataas-na-antas na paliwanag ng proyekto para sa mga bagong mambabasa at kontribyutor.

---

## ⚙️ Mga Yunit at Gampanin

- **PS (Pangunahing Sasakyan)** – Ang mismong lumilipad na sasakyang panghimpapawid.  
- **MK (Malayuang Kontroler)** – Hawak ng tao; nagsisilbing *remote control*.  
- **TD (Takad Daungan)** – Lugar ng pagdaong (*docking*) para sa recharging, paglipat ng datos, o seguridad.  
- **KL (Kontrol sa Lupa)** – Ang *ground control station* para sa mas kompletong kontrol at pagmamanman.  
- **TEST** – Espesyal na kaligiran para mag-eksperimento at subukan ang mga bagong bahagi ng kodigo.
---

## 🚀 Paggamit

1. I-install ang [PlatformIO](https://platformio.org/install) sa iyong VSCode.  
2. Piliin ang yunit na nais i-build at i-upload:  
    ```bash
        pio run -e LH_PS -t upload
        pio device monitor -e LH_PS
    ```
3. Para sa testing mode:
    ``` bash
        pio run -e LH_TEST -t upload
        pio device monitor -e LH_TEST
    ```

## 📚 Mga Pasadyang Aklatan

* `tibok/` - Naglalaman ng mga pangkontrol sa indikador para magpakita ng istatus ng sistema.

* `konstant/` – Naglalaman ng mga pangkalahatang konstant (halimbawa: BAUD_RATE = 115200).

---

## 🔮 Inaasahang Target na Paggana

- Ang **PS** ay makakalipad nang matatag at makakaugnay sa iba pang yunit.

- Ang **MK** ay magsisilbing pangunahing *manual override* at pangunang kontrol.

- Ang **TD** ay magiging matatag na base ng paglapag at recharging.

- Ang **KL** ay magiging sentro ng awtonomiya at pagpaplano ng misyon.

- Ang **TEST** ay magbibigay ng ligtas na kaligiran para sa pagsubok ng mga bagong ideya nang hindi nakakaapekto sa pangunahing sistema.

---

## ✨ Pangkalahatang Diwa

Ang **LNDH** ay hindi lamang isang drone project — ito’y isang **modular na sistemang maaaring palawakin at paunlarin**,
upang balang araw ay magamit sa mas malalaking proyekto sa agham, teknolohiya, at inobasyon.