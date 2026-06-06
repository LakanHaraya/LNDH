# Daloy Paggawa sa Git

Mungkahing maikling daloy bago gumawa ng commit at mag-push.

## Simula

```powershell
git status --short
git branch --show-current
```

Siguraduhing nasa tamang branch bago magbago ng files.

## Habang Gumagawa

Tingnan ang hindi pa staged na pagbabago:

```powershell
git diff
```

Kung may file na hindi dapat kasama, huwag muna itong i-stage.

## Bago Mag-Commit

Build muna ang default sandbox:

```powershell
pio run
```

Kung may naapektuhang role, build din ang yunit:

```powershell
pio run -e LH_PS
```

Para sa mas malawak na check:

```powershell
pio run -e LH_PS -e LH_MK -e LH_TD -e LH_KL
```

## Commit

Stage lamang ang mga file na kasama sa layunin ng commit:

```powershell
git add <file>
git status --short
git diff --staged
```

Gumawa ng commit:

```powershell
git commit -m "Uri: maikling mensahe"
```

## Push

Unang push ng branch:

```powershell
git push -u origin LNDHv2
```

Kasunod na push:

```powershell
git push
```
