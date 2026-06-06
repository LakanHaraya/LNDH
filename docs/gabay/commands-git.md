# Mga Komand sa Git

Mga karaniwang utos ng Git para sa LNDH v2.

## Kalagayan

```powershell
git status
git status --short
git branch --show-current
```

## Pagbabago

Hindi pa staged:

```powershell
git diff
```

Naka-stage na:

```powershell
git diff --staged
```

## Stage at Commit

Mag-stage ng tiyak na file:

```powershell
git add platformio.ini
git add docs/gabay/terminal.md
```

Commit:

```powershell
git commit -m "Uri: maikling mensahe"
```

## Branch at Remote

```powershell
git branch
git remote -v
```

Gumawa at lumipat sa bagong sangay:

```powershell
git switch -c bagong-sangay
```

Lumipat sa dati nang sangay:

```powershell
git switch LNDHv2
```

Push ng kasalukuyang sangay sa unang pagkakataon:

```powershell
git push -u origin LNDHv2
```

Kasunod na push:

```powershell
git push
```

## Kasaysayan

Maikling tala ng commits:

```powershell
git log --oneline
git log --oneline --decorate -10
```

Tingnan ang laman ng isang commit:

```powershell
git show <commit>
```

Tingnan ang pagkakaiba ng dalawang commit o branch:

```powershell
git diff <commit1>..<commit2>
git diff matatag..LNDHv2
```

## Pagbalik sa Tiyak na Commit

Tingnan muna ang commit hash:

```powershell
git log --oneline
```

Silipin ang lumang commit nang hindi binabago ang kasalukuyang branch:

```powershell
git switch --detach <commit>
```

Bumalik sa branch pagkatapos magsilip:

```powershell
git switch LNDHv2
```

Gumawa ng bagong branch mula sa lumang commit:

```powershell
git switch -c balik-aral <commit>
```

## Pag-urong ng Pagbabago

Alisin sa staging area, pero panatilihin ang pagbabago sa file:

```powershell
git restore --staged <file>
```

Ibalik ang isang file sa huling commit:

```powershell
git restore <file>
```

Ibalik ang isang file mula sa tiyak na commit:

```powershell
git restore --source <commit> -- <file>
```

Gumawa ng bagong commit na bumabawi sa lumang commit:

```powershell
git revert <commit>
```

## Reset

Gamitin lamang kapag malinaw kung ano ang mababago. Mas ligtas ang `git revert`
kapag na-push na ang commit.

Iurong ang branch sa nakaraang commit pero panatilihin ang pagbabago sa files:

```powershell
git reset --soft HEAD~1
```

Iurong ang branch at alisin sa staging area ang pagbabago:

```powershell
git reset --mixed HEAD~1
```

Iwasang gamitin ang hard reset maliban kung sadyang itatapon ang pagbabago:

```powershell
git reset --hard <commit>
```

## Pansamantalang Itabi

Itabi muna ang kasalukuyang pagbabago:

```powershell
git stash push -m "maikling tala"
```

Tingnan ang mga nakatabing pagbabago:

```powershell
git stash list
```

Ibalik ang pinakahuling stash:

```powershell
git stash pop
```
