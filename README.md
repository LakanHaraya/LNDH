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
|— .vscode/         # Mga kagamitang pantulong sa VSCode
|— include/         # Mga pangkalahatang header files
|— lib/             # Mga sariling likhang aklatan (libraries)
|   |— konstant/        # Mga pangkalahatang konstant
|   |— tibok/           # Mga panghudyat sa sistema
|— src/             # Kodigo mulaan ng bawat yunit
|   |— LH_PS/           # Pangunahing Sasakyan  (Main Drone)
|   |— LH_MK/           # Malayuang Kontroler   (Remote Controller)
|   |— LH_TD/           # Takad Daungan         (Docking Base)
|   |— LH_KL/           # Kontrol sa Lupa       (Ground Control Station)
|— test/            # Lugar ng eksperimento at pagsubok
|   |— subukin.cpp
|— platformio.ini   # Kumpigurasyon ng buong proyekto
```

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