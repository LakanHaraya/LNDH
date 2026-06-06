# Daloy Paggawa sa Terminal

Maikling daloy ng karaniwang trabaho sa LNDH v2 gamit ang terminal.

Para sa detalyadong utos, tingnan din:

- [PlatformIO](pio.md)
- [Git](git.md)

## Pumunta sa Proyekto

```powershell
cd D:\Users\Documents\PlatformIO\Projects\LNDH
```

## Simula ng Trabaho

```powershell
git status --short
git branch --show-current
```

## Mabilisang Pagsubok

```powershell
pio run
```

Ang default environment ay `LH_TEST`.

## Suriin ang Yunit

```powershell
pio run -e LH_PS
```

Palitan ang env ayon sa yunit na binabago: `LH_PS`, `LH_MK`, `LH_TD`, o `LH_KL`.

## Upload at Monitor

```powershell
pio device list
pio run -e LH_TEST -t upload --upload-port COM7
pio device monitor -p COM7 -b 115200
```

## Full Check Bago Commit

```powershell
pio run -e LH_PS -e LH_MK -e LH_TD -e LH_KL
```

## Ihanda ang Commit

```powershell
git diff
git status --short
git add <file>
git status --short
git commit -m "Uri: maikling mensahe"
```
