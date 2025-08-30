# 📖 `Tibok/` 
[![Release](https://img.shields.io/github/v/release/LakanHaraya/Tibok?include_prereleases)](https://github.com/LakanHaraya/Tibok/tags)
![Malapamantayan](https://img.shields.io/badge/malapamantayan-LNDH--0051-purple)
![Last Commit](https://img.shields.io/github/last-commit/LakanHaraya/Tibok?label=last%20commit&style=flat-square)
![First Commit](https://img.shields.io/badge/first%20commit-2025--04--11-FCD116)
![Language](https://img.shields.io/badge/language-Filipino%20(may%20neolohismo)-0038A8)
[![Mga Pagkilala](https://img.shields.io/badge/%F0%9F%93%9D-CHANGELOG-blue)](docs/CHANGELOG.md)

# *Tibok na Indikasyon para sa Batayang Operasyon at Kondisyon*

<div align="center">

  <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" title="Arduino" width="90" style="vertical-align:middle;" loading="lazy"/>
  <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO Logo" title="PlatformIO" width="90" style="vertical-align:middle;" loading="lazy"/>
  <img src="https://upload.wikimedia.org/wikipedia/commons/3/3e/International_Electrotechnical_Commission_Logo.svg" alt="IEC Logo" title="IEC" width="90" style="vertical-align:middle;" loading="lazy"/>
  <img src="https://upload.wikimedia.org/wikipedia/commons/0/0c/MIT_logo.svg" alt="MIT Logo" title="MIT License" width="90" style="vertical-align:middle;" loading="lazy"/>

  <p><em>Ginagamit sa proyektong ito ang mga sumusunod na teknolohiya at pamantayan.<br>Walang ipinahihiwatig na ugnayan o pag-eendorso</em></p>

</div>


---

Ang **Tibok** ay isang magaan at mumunting aklatan para sa
pagkontrol ng LED o iba pang output device bilang *status indicator* na
sumasalamin sa operational status ng sistema. Ang tibok ay maaaring magpakita ng
iba't ibang antas gaya ng `Tibok::STANDBY`, `Tibok::NORMAL`, `Tibok::WARNING`, `Tibok::CRITICAL`, o `Tibok::EMERGENCY` batay sa antas ng alerto sa pamantayang
[IEC 60073:2002](https://webstore.iec.ch/en/publication/587).


> Ang aklatang ito ay bahagi ng *Proyektong LundayHangin* ngunit
> maaaring isama sa anumang proyekto ng mikrokontroler na
> nangangailangan ng malinaw na pidbak na natatanaw, nadidinig, o
> nahahaplos.

---

## Mga Tampok

- **Limang Heartbeat Levels:** `STANDBY`, `NORMAL`, `WARNING`, `CRITICAL`, `EMERGENCY` (alinsunod sa IEC 60073:2002).  
- **Flexible Output:** Active HIGH o LOW, madaling baguhin sa runtime.  
- **Per-Instance State:** Maramihang independent LED indicators.  
- **Fluent API:** Chainable methods (`enable()`, `setActiveHigh()`, `setHeartbeat()`).  
- **Non-Blocking Timing:** Gumagamit ng `millis()`; STANDBY may burst+pause logic.  
- **Madaling Integrasyon:** Simpleng konstruktor at compatible sa Arduino microcontrollers.  
- **Status Retrieval:** `getState()`, `getLabel()`, `getLastToggle()` para sa monitoring.  
- **Magaan at Efficient:** Minimal memory footprint, hindi humaharang sa loop.

---

## Karagdagang Dokumentasyon

- [docs/INSTALLATION.md](docs/INSTALLATION.md) – Paano Mag-instal?
- [docs/API_REFERENCE.md](docs/API_REFERENCE.md) – Paano Gamitin?
- [docs/CHANGELOG.md](docs/CHANGELOG.md) – Ano ang Bago?
- [docs/ATTRIBUTIONS.md](docs/ATTRIBUTIONS.md) – Mga Pagkilala.

---

## Mga Halimbawa <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" alt="Arduino Logo" width="20" style="vertical-align:middle;"/> <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/PlatformIO_logo.svg" alt="PlatformIO Logo" width="20" style="vertical-align:middle;"/>

Tingnan ang [`examples/`](examples/) folder para sa mga sumusunod na sketch.

1. [`BasicHeartbeat.ino`](examples/BasicHeartbeat/BasicHeartbeat.ino) – Simpleng tibok
2. [`SampleHeartbeats.ino`](examples/SampleHeartbeats/SampleHeartbeats.ino) – Mga halimbawa ng pagtibok para sa bawat isang GPIO pin.
2. [`ConstructorDemo.ino`](examples/ConstructorDemo/ConstructorDemo.ino) – Iba't ibang paraan ng paggamit ng constructor gamit ang magkakaibang bilang ng argumento.
3. [`DynamicHeartbeat.ino`](examples/DynamicHeartbeat/DynamicHeartbeat.ino) – Pagpapalit ng tibok sa runtime
4. [`ActiveLowHighHeartbeat.ino`](examples/ActiveLowHighHeartbeat/ActiveLowHighHeartbeat.ino) – Aktibong LOW at aktibong HIGH na signal
5. [`WithChainedMethods.ino`](examples/WithChainedMethods/WithChainedMethods.ino) – Paggamit ng chaining method
6. [`GetStateChange.ino`](examples/GetStateChange/GetStateChange.ino) – Subaybayan ang estado ng indikador at ipakita ang mga pagbabago sa estado nito.
7. [`TibokGetters.ino`](examples/TibokGetters/TibokGetters.ino) – Kunin ang mga iba't ibang impormasyon tungkol sa status indicator
8. [`EnableDisable.ino`](examples/EnableDisable/EnableDisable.ino) – Pagtikwas ng tibok

> ### Testing
> 1. I-upload ang isa sa mga halimbawa sa iyong board.
> 2. Suriin kung gumagana ang heartbeat tulad ng inaasahan.

---

## Lisensiya <img src="https://upload.wikimedia.org/wikipedia/commons/0/0c/MIT_logo.svg" alt="Massachusetts Institute of Technology (MIT) Logo" width="40" style="vertical-align:middle;"/>
Ang **Tibok** ay inilabas sa ilalim ng [MIT License](LICENSE)

