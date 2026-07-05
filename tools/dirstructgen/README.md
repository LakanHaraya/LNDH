# DirStructGen

![Version](https://img.shields.io/badge/version-0.1.0-blue)
![Python](https://img.shields.io/badge/python-3.8+-green)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-blue)

Matalinong tagalatag ng directory structure sa Markdown format. Perpekto para sa project documentation, team collaboration, at code repository organization.

## Mabilis na Simula

```bash
# Windows
dirstructgen.cmd

# Linux / macOS
python tools/dirstructgen/dirstructgen.py
```

Awtomatikong lilikha ng `DIREKTORYO.md` sa current directory.

---

## Tungkol sa Kasangkapang Ito

Ang **DirStructGen** ay lightweight command-line utility na lumilikha ng hierarchical directory structure sa Markdown. Idinisenyo para maging:

- **Simple** - Zero dependencies, walang kinakailangang configuration
- **Mabilis** - Mabilis na tree generation kahit sa malalaking projects
- **Matalino** - Awtomatikong nirerespeto ang `.gitignore` patterns
- **Fleksibol** - Sapat na command-line options para sa pagpapasadya

### Gumagamit ng

```
Python 3.8+  |  Walang external libraries
```

---

## Mga Katangian

| Feature | Status | Notes |
|---------|--------|-------|
| Recursive tree generation | ✓ | Suportado ang buong lalim |
| Markdown output | ✓ | HTML-compatible format |
| `.gitignore` support | ✓ | Auto-loaded from project root |
| Custom ignore rules | ✓ | Via command-line flags |
| Output filtering | ✓ | Mag-exclude o mag-include ng generated file |
| Auto directory creation | ✓ | Lumilikha ng output folders kung needed |
| Windows batch wrapper | ✓ | `dirstructgen.cmd` para sa convenience |
| Help system | ✓ | `dirstructgen ?` o `--help` |

---

## Installation & Setup

### Walang setup na required!

Patakbuhin lang nang direkta:

```bash
# Opsiyon 1: Direktang Python (lahat ng platforms)
python tools/dirstructgen/dirstructgen.py

# Opsiyon 2: Windows batch (mas convenient)
dirstructgen.cmd

# Opsiyon 3: Idagdag sa PATH para sa global access
# (opsiyonal lamang)
```

---

## Paggamit

### Pangunahing Command Structure

```bash
dirstructgen [OPTIONS]
```
o kaya
```bash
python tools\dirstructgen\dirstructgen.py [OPTIONS]
```

### Available Options

```
POSITIONAL / FLAGS:

  ?                    Ipakita ang help message

OPTIONS:

  -p, --path DIR       Target directory na susuriin (default: .)
  -o, --output FILE    Output markdown file (default: DIREKTORYO.md)
  -i, --ignore LIST    Additional ignore patterns (space-separated)
  -t, --title TEXT     Custom title para sa markdown
  --no-gitignore       Huwag basahin ang .gitignore
  --include-output     Isama ang output file sa generated tree
  -v, --version        Show version information
```

---

## Mga Halimbawa

### 1. Default - Simple Generate

```bash
python tools/dirstructgen/dirstructgen.py
```

**Resulta:** `DIREKTORYO.md` sa kasalukuyang folder

---

### 2. Target Specific Directory

```bash
python tools/dirstructgen/dirstructgen.py -p src/
```

**Resulta:** Tree ng `src/` directory

---

### 3. Custom Output File

```bash
python tools/dirstructgen/dirstructgen.py -o docs/PROJECT_STRUCTURE.md
```

**Resulta:** Output sa `docs/PROJECT_STRUCTURE.md`

---

### 4. Custom Title

```bash
python tools/dirstructgen/dirstructgen.py -t "LNDH Project Layout"
```

**Resulta:** Markdown file na may custom title

---

### 5. Additional Ignore Patterns

```bash
python tools/dirstructgen/dirstructgen.py -i __pycache__ .venv build dist
```

**Resulta:** Excluded ang specified folders

---

### 6. Ignore .gitignore

```bash
python tools/dirstructgen/dirstructgen.py --no-gitignore
```

**Resulta:** Walang .gitignore rules, lahat ng nilalaman sa direktoryo ay ini-scan

---

### 7. Include Output File sa Tree

```bash
python tools/dirstructgen/dirstructgen.py -o docs/TREE.md --include-output
```

**Resulta:** 
```
docs/
├── TREE.md
└── other_files/
```

---

### 8. Get Help

```bash
python tools/dirstructgen/dirstructgen.py ?

python tools/dirstructgen/dirstructgen.py --help
```

---

### 9. Show Version

```bash
python tools/dirstructgen/dirstructgen.py -v

python tools/dirstructgen/dirstructgen.py --version
```


---

## Arkitektura

### Project Structure

```
tools/dirstructgen/
├── dirstructgen.py          Main script - tree generation logic
├── dirstructgen_help.py     Help system module
├── dirstructgen_version.py  Version information
├── dirstructgen.cmd         Windows batch wrapper
└── README                   This file
```

### Code Organization

| File | Purpose |
|------|---------|
| **dirstructgen.py** | Core application - argument parsing, ignore logic, tree walker |
| **dirstructgen_help.py** | Help text formatting at display |
| **dirstructgen_version.py** | Version metadata |
| **dirstructgen.cmd** | Windows convenience wrapper |

### Execution Flow

```
User Input
    ↓
Parse Arguments (argparse)
    ↓
Load .gitignore (if enabled)
    ↓
Build Ignore Set (union of sources)
    ↓
Walk Directory Tree (recursive)
    ↓
Filter Entries (check ignore set)
    ↓
Generate Tree Lines
    ↓
Write Markdown File
    ↓
Done ✓
```

---

## Priyoridad sa Ignore Rules

Kapag bumubuo ng tree, ang tool ay sumusunod sa priority order:

### Priority Levels

```
1. .gitignore         (Highest priority - project level)
2. DEFAULT_IGNORE     (Built-in safe defaults)
3. --ignore CLI flag  (User-specified via command line)
4. Output filename    (Automatically excluded unless --include-output)
```

### Halimbawa

Kung mayroon:
- `.gitignore` na may `node_modules`
- `DEFAULT_IGNORE` na may `.git`
- CLI flag: `-i build dist`

**Resulta:** Lahat ng tatlong sets ay isasama sa final ignore set.

---

## Output Format

### Nalikhang Estruktura sa Markdown

```markdown
# Directory Structure

\`\`\`text
ProjectRoot/
├── docs/
│   ├── README.md
│   └── guides/
├── include/
│   ├── header1.h
│   └── header2.h
├── src/
│   ├── main.cpp
│   └── utils.cpp
├── test/
│   └── test.cpp
├── platformio.ini
└── .gitignore
\`\`\`
```

### Mga Sagisag sa Talatagan

```
├──  Regular branch connector
└──  Last item connector
│    Vertical line continuation
     Indent (4 spaces)
```

---

## Mga Karaniwang Kaso ng Paggamit

### 1. Dokumentasyon ng Proyekto

```bash
python dirstructgen.py -p . -o docs/STRUCTURE.md -t "Project Organization"
```
* Susuriin magmula sa kasalukuyang direktoryo `.`  
* Lilikha ng output file sa direktoryong `docs/STRUCTURE.md`  
* Papamagatan ang loob ng nilalaman ng file sa `"Project Organization"`

---

### 2. Konteksto sa Pagribyu ng Kodigo

```bash
python dirstructgen.py -p src/ -o REVIEW_CONTEXT.md
```
* Susuriin magmula sa direktoryo ng `src/`  
* Lilikha sa kasalukuyang folder ng output file na `REVIEW_CONTEXT.md`  

---

### 3. Pagsusuri sa Repositoryo

```bash
python dirstructgen.py --no-gitignore -o FULL_TREE.md
```

Makikita lahat ng files kahit ignore sila normally.  
* Susuriin magmula sa kasalukuyang direktoryo `.` at babasahin ang lahat ng files nang hindi ikinokonsidera ang nilalaman ng `.gitignore` 
* Lilikha sa kasalukuyang direktoryo ng output file na `FULL_TREE.md`  

---

### 4. Maramihang Proyekto
```bash
python dirstructgen.py -p ../project_a -o docs/project_a_structure.md
```
* Susuriin magmula sa direktoryong `../project_a`
* Lilikha ng output file sa direktoryong `docs/project_a_structure.md`  

```bash
python dirstructgen.py -p ../project_b -o docs/project_b_structure.md
```
* Susuriin magmula sa direktoryong `../project_b`
* Lilikha ng output file sa direktoryong `docs/project_b_structure.md`  

---

## Mga Limitasyong Nalalaman

### Kasalukuyang Bersiyon (0.1.x)

#### Gitignore Parser

**Suportado:**
- Simpleng filename/directory names: `node_modules`, `build`, `.env`
- Magkahalong patterns: `.pio`, `cache`, `temp`

**Hindi pa Suportado:**
- Wildcard patterns: `*.log`, `*.tmp`
- Glob patterns: `**/node_modules`, `src/**/*.test.js`
- Negation patterns: `!important.log`
- Advanced rules: `*.txt | !keep.txt`

#### Iba pang Limitasyon

- Walang sorting by file type
- Walang file size statistics
- Simpleng level title lamang
- Walang pasadyang styling/colors
- Tanging markdown output lamang (v0.1.x)

---

## Mapa ng Pauswagan

### v0.2.0 (Pinaplano - Susunod na Yugto)

- [ ] Paglilimita ng lalim gamit ang `--max-depth N`
- [ ] Estadistika sa dami ng files
- [ ] JSON output format
- [ ] TXT output format
- [ ] Batayang suporta sa wildcard sa `.gitignore`
- [ ] Configuration file (`.dirstructgenrc`)
- [ ] File size display
- [ ] Kinulayang output (opsiyonal)

### v0.X.0+ (Ideya sa Hinaharap)

- [ ] Interactive selection ng mga direktoryo
- [ ] Web UI preview
- [ ] Performance: parallel scanning
- [ ] Template system
- [ ] Integration with CI/CD pipelines
- [ ] API/Library mode

---

## Paglutas ng Problema

### Isyu: "Python not found"

**Solusyon:** Tiyakin na ang Python 3.8+ ay nakainstal at nasa PATH

```bash
python --version
```

### Isyu: Permission denied

**Solusyon:** Itsek ang file permissions sa output directory

```bash
# Linux/macOS
chmod +x dirstructgen.py
```

### Isyu: Ang `.gitignore` ay hindi ikinonsidera

**Solusyon:** Beripikahin ang lokasyon ng `.gitignore` (dapat nasa target directory root)

```bash
python dirstructgen.py --no-gitignore  # Subukin nang walang .gitignore
```

### Isyu: Ang output file ay HINDI lumitaw sa talatagan

**Solusyon:** Gumamit ng `--include-output` flag kung gusto mong isama, o wala kung exclude

```bash
python dirstructgen.py --include-output
```

---

## Lisensiya

**Open Source** - Libreng gamitin, baguhin, at ipamahagi para sa:
- Personal na proyekto
- Gawaing akademiko
- Komersiyal na aplikasyon
- Layuning pang-edukasyon

Walang paghihigpit sa paggamit.

---

## May-akda

**Lakan Haraya Dima**

---

## Pag-aambag

Ang mga mungkahi, bug reports, at pagpapahusay ay hinihikayat! Malayang kayong:

1. Subukin ang tool sa iba't ibang proyekto
2. Magsumbong ng mga isyu o edge cases
3. Magmungkahi ng mga bagong katangian
4. Mag-ambag sa pagpapahusay

---

## Kasaysayan ng Bersiyon

### v0.1.0 (Kasalukuyan)

- Inisyal na nilantad
- Puso ng paglikha ng talatagan
- Suporta sa `.gitignore`
- Mga opsiyon sa CLI
- Sistema ng tulong
- Windows batch wrapper

---

## Suporta

Para sa katanungan o pidbak, makipag-ugnayan sa may-akda o mag-file ng isyu sa project repository.