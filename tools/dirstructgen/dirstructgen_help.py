# dirstructgen_help.py

def print_help():
    print("""
    ╔════════════════════════════════════════════╗
    ║   TAGALATAG NG ESTRTUKTURA NG DIREKTORYO   ║
    ║            Lakan Haraya Dima               ║
    ╚════════════════════════════════════════════╝

DESKRIPSYON:
    Gumagawa ng Markdown tree structure ng project folders.
    Suportado ang .gitignore auto-import.
    Ginagamit ito para sa mabilis na dokumentasyon
    ng kahit anong software project structure.

GAMIT:

   dirstructgen                 → karaniwang paggana (may .gitignore)
   dirstructgen -p LNDH         → tukuyin ang folder na iguguhit (default sa LNDH)
   dirstructgen -o docs/OUT.md  → pasadyang output file
   dirstructgen -i temp cache   → dagdagan ang babalewalaing folders/files
   dirstructgen --no-gitignore  → huwag basahin ang .gitignore
   dirstructgen -t "Project"    → pasadyang pamagat sa markdown
   dirstructgen ?               → ipakita ang tulong na ito

OPSIYON:

   -p, --path
       Root folder na iguguhit (default: kasalukuyang folder)
   -o, --output
       Output markdown file (default: DIREKTORYO.md)
   -i, --ignore
       Karagdagang folders/files na babalewalain(space-separated list)
   -t, --title
       Pamagat ng markdown file (default: "Directory Structure")
   --no-gitignore
       Huwag paganahin ang .gitignore loading
       (awtomatikong ginagamit kung may .gitignore sa root)

SUNURAN NG PRIYORIDAD NG PAGBALEWALA:
   1. .gitignore (kung hindi pinigilan)
   2. DEFAULT_IGNORE
   3. CLI --ignore 

    ════════════════════════════════════════════
""")