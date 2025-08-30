# `Tibok/` – *Installation, Verification, and Uninstallation*

Ang dokumentong ito ay naglalaman ng kompletong 
gabay para sa **Installation**, **Verification**,
at **Uninstallation** ng `Tibok/` library, gamit ang
alinman sa **Arduino IDE** o **PlatformIO**

---

- [Arduino IDE (Manual)](#arduino-ide-manual-library-manager)
   - [Installation](#installation)
   - [Verification](#verification)
   - [Uninstallation](#uninstallation)
- [PlatformIO](#platformio)
   - [Installation](#installation-1)
   - [Verification](#verification-1)
   - [Uninstallation](#uninstallation-1)

---

## <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" width="50" style="vertical-align:middle;"/> Arduino IDE (Manual) (~~Library Manager~~)

### Installation <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" width="20" style="vertical-align:middle;"/>

1.  Bisitahin ang [Tibok Github repository](https://github.com/LakanHaraya/Tibok.git)
2. I-click ang **Code** > **Download ZIP** upang i-download ang `.zip` file ng library
3. Buksan ang **Arduino IDE**
4. Pumunta sa `Sketch` > `Include Library` > `Add .ZIP Library...`
5. Piliin ang na-download na `.zip` file mula sa iyong file explorer
6. Kapag matagumpay, makikita ang `Tibok` sa `Sketch` > `Include Library`

### Verification <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" width="20" style="vertical-align:middle;"/>

1. Sa Arduino IDE, pumunta sa `File` > `Examples` > `Tibok`
2. Piliin ang isa sa mga halimbawa at i-upload ito sa iyong board
3. Kung gumagana ang sketch, matagumpay ang pag-install

### Uninstallation <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" width="20" style="vertical-align:middle;"/>

1. Hanapin ang lokasyon ng Library  
   - Default folder:
      - **Windows:** `Documents/Arduino/libraries/`
      - **macOS:** `~/Documents/Arduino/libraries/`
      - **Linux:** `~/Arduino/libraries/`
2. Hanapin ang `Tibok` folder at **i-delete** ito mula sa `libraries/`
3. I-restart ang IDE upang ma-refresh ang listahan ng libraries
4. Tingnan ang `Sketch` > `Include Library` — dapat wala na ang `Tibok`

---

## <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO" width="40" style="vertical-align:middle;"/> PlatformIO


### Installation <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO" width="20" style="vertical-align:middle;"/>

1. I-clone ang repositoryo
   ``` bash
   git clone https://github.com/LakanHaraya/Tibok.git
   ``` 
2. Kopyahin ang `Tibok/` folder papunta sa `lib/` directory ng iyong PlatformIO project
3. I-include sa iyong code
   ``` cpp
   #include <Tibok.h>
   ```
4. I-compile at i-upload ang proyekto gamit ang PlatformIO

### Verification <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO" width="20" style="vertical-align:middle;"/>
1. Buksan ang isang halimbawa mula sa `examples/` folder ng `Tibok` repository
2. Ilagay ito sa `src/` ng iyong PlatformIO project
3. I-build at i-upload ito sa iyong board
4. Kung walang error at gumagana ang sketch, matagumpay ang pag-install

### Uninstallation <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO" width="20" style="vertical-align:middle;"/>
1. Burahin ang `Tibok/` folder mula sa `lib/` directory ng iyong PlatformIO project
2. Hindi kailangang i-restart ang VSCode o PlatformIO; matatanggal na ito agad sa build system

---
