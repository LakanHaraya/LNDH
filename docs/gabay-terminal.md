# Gabay sa Terminal ng LNDH

Maikling gabay sa karaniwang command na ginagamit sa pagbuo, pag-upload,
pagbantay, at pagsasaayos ng LNDH v2 gamit ang PowerShell o CMD.

## Pumunta sa Proyekto

```powershell
cd D:\Users\Documents\PlatformIO\Projects\LNDH
```

## Tingnan ang Kalagayan

```powershell
git status
git status --short
git branch --show-current
```

Gamitin ito bago at pagkatapos gumawa ng pagbabago upang makita ang sangay at
mga file na nabago.

## Build

Ang default environment ay `LH_TEST`.

```powershell
pio run
```

Build ng bawat yunit:

```powershell
pio run -e LH_PS
pio run -e LH_MK
pio run -e LH_TD
pio run -e LH_KL
```

Build ng lahat ng pangunahing yunit:

```powershell
pio run -e LH_PS -e LH_MK -e LH_TD -e LH_KL
```

## Upload

Ikabit muna ang tamang board bago mag-upload.

```powershell
pio run -e LH_TEST -t upload
pio run -e LH_PS -t upload
pio run -e LH_MK -t upload
pio run -e LH_TD -t upload
pio run -e LH_KL -t upload
```

Kung kailangan tukuyin ang port, gamitin ang `--upload-port`:

```powershell
pio device list
pio run -e LH_TEST -t upload --upload-port COM7
```

## Serial Monitor

Ang serial monitor ay nakakabit sa `COM` port ng board. Maaari itong gumamit ng
environment kung may `monitor_port` sa `platformio.ini`, pero isang monitor
session lamang ang karaniwang para sa isang board.

```powershell
pio device monitor
```

May tiyak na environment:

```powershell
pio device monitor -e LH_TEST
pio device monitor -e LH_PS
```

May tiyak na port at baud rate:

```powershell
pio device list
pio device monitor -p COM7 -b 115200
```

Para sa maraming yunit, magbukas ng magkakahiwalay na terminal:

```powershell
pio device monitor -e LH_PS
pio device monitor -e LH_MK
pio device monitor -e LH_TD
pio device monitor -e LH_KL
```

Kung walang `monitor_port` bawat environment, gamitin ang kani-kaniyang port:

```powershell
pio device monitor -p COM3 -b 115200
pio device monitor -p COM4 -b 115200
pio device monitor -p COM5 -b 115200
pio device monitor -p COM6 -b 115200
```

## Linisin ang Build Output

```powershell
pio run -t clean
pio run -e LH_TEST -t clean
```

Gamitin kapag may kakaibang build error o nais magsimula sa malinis na output.

## Tingnan ang Pagbabago

```powershell
git diff
git diff --staged
```

Ang `git diff` ay para sa hindi pa staged na pagbabago. Ang `git diff --staged`
ay para sa mga nakahanda nang isama sa commit.

## Maghanda ng Commit

```powershell
git add platformio.ini
git add test/test.cpp
git add docs/gabay-terminal.md
git commit -m "Idagdag: gabay sa terminal"
```

## Karaniwang Daloy

Simula ng trabaho:

```powershell
cd D:\Users\Documents\PlatformIO\Projects\LNDH
git status --short
git branch --show-current
```

Mabilisang pagsubok sa sandbox:

```powershell
pio run
```

Suriin ang yunit na binabago:

```powershell
pio run -e LH_PS
```

I-upload at bantayan ang output:

```powershell
pio run -e LH_TEST -t upload
pio device monitor -e LH_TEST
```

Suriin ang lahat ng pangunahing yunit bago mag-commit:

```powershell
pio run -e LH_PS -e LH_MK -e LH_TD -e LH_KL
```

Tingnan at ihanda ang commit:

```powershell
git diff
git status --short
git add <file1> <file2> <file3> <...>
git status --short
git commit -m "Uri: maikling mensahe"
```
