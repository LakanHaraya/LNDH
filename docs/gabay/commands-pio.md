# Mga Komand sa PlatformIO

Mga karaniwang utos ng PlatformIO para sa LNDH v2.

## Build

Default build gamit ang `LH_TEST`:

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

Tingnan muna ang nakakabit na board:

```powershell
pio device list
```

Upload gamit ang environment:

```powershell
pio run -e LH_TEST -t upload
pio run -e LH_PS -t upload
```

Upload gamit ang tiyak na port:

```powershell
pio run -e LH_TEST -t upload --upload-port COM7
```

## Serial Monitor

Monitor gamit ang environment:

```powershell
pio device monitor -e LH_TEST
```

Monitor gamit ang tiyak na port at baud rate:

```powershell
pio device monitor -p COM7 -b 115200
```

Para sa maraming yunit, magbukas ng magkakahiwalay na terminal:

```powershell
pio device monitor -p COM3 -b 115200
pio device monitor -p COM4 -b 115200
pio device monitor -p COM5 -b 115200
pio device monitor -p COM6 -b 115200
```

## Clean

```powershell
pio run -t clean
pio run -e LH_TEST -t clean
```
