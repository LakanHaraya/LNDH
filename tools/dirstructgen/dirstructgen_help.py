# dirstructgen_help.py

import sys


def _build_context_summary(argv=None):
    argv = argv or sys.argv
    tokens = argv[1:] if len(argv) > 1 else []

    target = "."
    output = "DIREKTORYO.md"
    ignore_patterns = []
    title = "Directory Structure"
    include_output = False
    use_gitignore = True

    index = 0
    while index < len(tokens):
        token = tokens[index]

        if token in {"-p", "--path"} and index + 1 < len(tokens):
            target = tokens[index + 1]
            index += 2
            continue
        if token in {"-o", "--output"} and index + 1 < len(tokens):
            output = tokens[index + 1]
            index += 2
            continue
        if token in {"-i", "--ignore"}:
            collected = []
            index += 1
            while index < len(tokens) and not tokens[index].startswith("-"):
                collected.append(tokens[index])
                index += 1
            ignore_patterns = collected
            continue
        if token in {"-t", "--title"} and index + 1 < len(tokens):
            title = tokens[index + 1]
            index += 2
            continue
        if token == "--no-gitignore":
            use_gitignore = False
            index += 1
            continue
        if token == "--include-output":
            include_output = True
            index += 1
            continue

        index += 1

    return {
        "target": target,
        "output": output,
        "ignore_patterns": ignore_patterns,
        "title": title,
        "include_output": include_output,
        "use_gitignore": use_gitignore,
    }


def print_quick_help():
    print("""
    ╔════════════════════════════════════════════╗
    ║   DirStructGen - Quick Help                ║
    ║   Simple directory tree generator          ║
    ╚════════════════════════════════════════════╝

Pangunahing paggamit:
    dirstructgen
    dirstructgen -p src/
    dirstructgen -o docs/STRUCTURE.md
    dirstructgen -i build node_modules
    dirstructgen --no-gitignore

Karaniwang pag-unawa:
    - -p / --path      Piliin ang root folder
    - -o / --output    I-save ang output sa file
    - -i / --ignore    Idagdag ang mga folder/file na hindi isasama
    - -t / --title     Baguhin ang pamagat ng markdown

Karagdagang tulong:
    dirstructgen --help
    dirstructgen --help path
    dirstructgen -v
    """)


def print_detailed_help():
    print("""
    ╔════════════════════════════════════════════╗
    ║   DirStructGen - Detailed Help             ║
    ╚════════════════════════════════════════════╝

Deskripsyon:
    Gumagawa ng Markdown tree structure para sa isang proyekto.
    Maaaring gumamit ng .gitignore at custom ignore patterns.

Mga option:
    -p, --path DIR        Root folder na iguguhit
    -o, --output FILE     Output markdown file
    -i, --ignore LIST     Extra patterns na hindi isasama
    -t, --title TEXT      Pamagat ng output markdown
    --no-gitignore        Huwag basahin ang .gitignore
    --include-output      Isama ang output file sa tree
    -v, --version         Ipakita ang bersyon
    ?, --help             Ipakita ang help message

Pag-unawa sa resulta:
    Ang tool ay bubuo ng directory tree at isusulat ito sa markdown file.
    Ang output ay may malinaw na hierarchy at maaaring i-customize gamit ang flags.

Prinsipyo ng ignore:
    1. .gitignore (kung hindi pinigilan)
    2. Custom --ignore values
    3. Built-in safe defaults

Halimbawa:
    dirstructgen -p src/ -o docs/STRUCTURE.md -i build
    dirstructgen --no-gitignore -o FULL_TREE.md
    """)


def print_option_help(option):
    option = option.lower()
    mapping = {
        "path": """
    ╔════════════════════════════════════════════╗
    ║   Help: --path / -p                        ║
    ╚════════════════════════════════════════════╝

Tumutukoy sa root directory na i-generate bilang tree.

Halimbawa:
    dirstructgen -p src/
    dirstructgen -p .

Paano ito iintindihin:
    - Kung walang -p, gagamitin ang kasalukuyang folder.
    - Kung invalid ang path, hindi magagawa ang tree.
        """,
        "output": """
    ╔════════════════════════════════════════════╗
    ║   Help: --output / -o                      ║
    ╚════════════════════════════════════════════╝

Tinutukoy kung saan isusulat ang markdown file.

Halimbawa:
    dirstructgen -o docs/STRUCTURE.md

Paano ito iintindihin:
    - Kung wala ang output path, gagamitin ang DIREKTORYO.md.
    - Awtomatikong nililikha ang folder kung hindi pa umiiral.
        """,
        "ignore": """
    ╔════════════════════════════════════════════╗
    ║   Help: --ignore / -i                      ║
    ╚════════════════════════════════════════════╝

Nagdadagdag ng extra patterns na hindi isasama sa tree.

Halimbawa:
    dirstructgen -i build node_modules

Paano ito iintindihin:
    - Ang bawat value ay parang separate filter.
    - Mas mababa ang chance na lumabas ang mga hindi gusto sa output.
        """,
        "title": """
    ╔════════════════════════════════════════════╗
    ║   Help: --title / -t                       ║
    ╚════════════════════════════════════════════╝

Binabago ang pamagat sa generated markdown.

Halimbawa:
    dirstructgen -t "LNDH Project Layout"

Paano ito iintindihin:
    - Ang title ay magiging heading sa output file.
    - Kapag may spaces, ilagay sa quotes.
        """,
        "gitignore": """
    ╔════════════════════════════════════════════╗
    ║   Help: --no-gitignore                     ║
    ╚════════════════════════════════════════════╝

Hindi gagamitin ang .gitignore sa pag-filter ng tree.

Halimbawa:
    dirstructgen --no-gitignore

Paano ito iintindihin:
    - Mas marami ang lalabas na entries sa tree.
    - Kapaki-pakinabang kapag gusto mong makita ang buong structure.
        """
    }

    if option in mapping:
        print(mapping[option])
    else:
        print(f"""
    Hindi kilalang option: {option}

Subukan ang:
    dirstructgen --help
    dirstructgen --help path
    dirstructgen --help output
        """)


def print_context_help(argv=None, option=None):
    if option:
        print_option_help(option)
        return

    summary = _build_context_summary(argv)
    command = "dirstructgen"
    if argv and len(argv) > 1:
        command = "dirstructgen " + " ".join(argv[1:])

    ignore_text = ", ".join(summary["ignore_patterns"]) if summary["ignore_patterns"] else "(none)"
    gitignore_text = "disabled" if not summary["use_gitignore"] else "enabled"

    print(f"""
    ╔════════════════════════════════════════════╗
    ║   DirStructGen - Context Help              ║
    ╚════════════════════════════════════════════╝

Input na natanggap:
    {command}

Mga flag na ginamit:
    - Path: {summary['target']}
    - Output: {summary['output']}
    - Ignore patterns: {ignore_text}
    - Title: {summary['title']}
    - .gitignore: {gitignore_text}
    - Include output in tree: {'yes' if summary['include_output'] else 'no'}

Ano ang ibig sabihin nito:
    - Bubuuin ang tree para sa '{summary['target']}'.
    - Isusulat ang resulta sa '{summary['output']}'.
    - Ang mga hindi gustong entries ay i-filter ayon sa mga flag.

Paano ito basahin:
    1. Tingnan ang target folder.
    2. Tingnan ang output file.
    3. Tingnan kung may ignore rules o .gitignore.
    4. Kung gusto mo ang mas malinaw na help, subukan ang:
       dirstructgen --help
       dirstructgen --help path
    """)


def print_help(option=None, argv=None):
    if option:
        print_option_help(option)
    else:
        print_context_help(argv or sys.argv)