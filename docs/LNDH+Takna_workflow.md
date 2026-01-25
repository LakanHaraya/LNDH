# 🧭 LNDH + Takna Quick Workflow

> Tandaan: **Magkaibang Git repo** ang LNDH at Takna kahit magkasama sila sa isang folder.

## 📁 Structure
``` sh
LNDH/lib/Takna/         git submodule)
```

## 🔁 Workflow

### Kapag may binago sa Takna:
```bash
cd LNDH/lib/Takna
git add .
git commit -m "Takna: update"
git push
```

### I-update ang LNDH Pointer
``` sh
cd ../..
git add lib/Takna
git commit -m "Update Takna submodule"
git push
```

## ⚠️ Rules

- ✔ Dalawang repo = dalawang commit  
- ✔ Takna muna, bago LNDH  
- ❌ Huwag mag-push ng LNDH na may uncommitted Takna

## 🧪 Check
``` sh
git status
```