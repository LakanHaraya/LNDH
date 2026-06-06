import os
import argparse
import sys

# =========================
# HELP SYSTEM
# =========================
from dirstructgen_help import print_help
from dirstructgen_version import print_version

# =========================
# DEFAULT IGNORE (SAFE)
# =========================
DEFAULT_IGNORE = set()

# =========================
# .GITIGNORE LOADER
# =========================
def load_gitignore(path="."):
    gitignore_path = os.path.join(path, ".gitignore")

    if not os.path.exists(gitignore_path):
        return set()

    ignore_set = set()

    try:
        with open(gitignore_path, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()

                # skip comments / empty lines
                if not line or line.startswith("#"):
                    continue

                # remove trailing slash
                line = line.rstrip("/")

                ignore_set.add(line)

    except Exception:
        return set()

    return ignore_set

# =========================
# IGNORE CHECK
# =========================
def should_ignore(name, ignore_set):
    return name in ignore_set

# =========================
# TREE GENERATOR
# =========================
def generate_tree(start_path, ignore_set):
    tree_lines = []

    # output_exclude = set()

    def walk(dir_path, prefix=""):
        try:
            entries = sorted(os.listdir(dir_path))
        except (PermissionError, FileNotFoundError):
            return

        entries = [
            e for e in entries
            if not should_ignore(e, ignore_set)
            # and e not in output_exclude
        ]

        for i, entry in enumerate(entries):
            full_path = os.path.join(dir_path, entry)
            is_last = (i == len(entries) - 1)

            connector = "└── " if is_last else "├── "
            tree_lines.append(prefix + connector + entry)

            if os.path.isdir(full_path):
                extension = "    " if is_last else "│   "
                walk(full_path, prefix + extension)

    tree_lines.append(os.path.basename(os.path.abspath(start_path)) + "/")
    walk(start_path)

    return tree_lines

# =========================
# OUTPUT FILE PREPARATION
# =========================
def touch_output_file(output_file):

    output_dir = os.path.dirname(output_file)

    if output_dir:
        os.makedirs(output_dir, exist_ok=True)

    if not os.path.exists(output_file):
        with open(output_file, "w", encoding="utf-8"):
            pass

# =========================
# MARKDOWN WRITER
# =========================
def save_markdown(tree_lines, output_file, title):
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(f"# {title}\n\n")
        f.write("```text\n")
        f.write("\n".join(tree_lines))
        f.write("\n```\n")

# =========================
# MAIN
# =========================
def main():

    # ? HELP TRIGGER
    if len(sys.argv) > 1 and sys.argv[1] == "?":
        print_help()
        return

    parser = argparse.ArgumentParser(
        description="Matalinong tagalatag ng estruktura ng direktoryo sa Markdown (suporta .gitignore)",
    )

    parser.add_argument("-p", "--path", default=".", help="Root folder na iguguhit (default: kasalukuyang folder)")
    parser.add_argument("-o", "--output", default="DIREKTORYO.md", help="Output markdown file (default: DIREKTORYO.md)")
    parser.add_argument("-i", "--ignore", nargs="*", default=[], help="Karagdagang folders/files na babalewalain (space-separated list)")
    parser.add_argument("-t", "--title", default="Directory Structure", help="Pamagat ng markdown file (default: \"Directory Structure\")")
    parser.add_argument(
        "--no-gitignore",
        action="store_true",
        help="Huwag paganahin ang .gitignore loading (awtomatikong ginagamit kung may .gitignore sa root)"
    )
    parser.add_argument(
        "--include-output",
        action="store_true",
        help="Isama ang generated output file sa tree (default: excluded)"
    )
    parser.add_argument(
        "-v", "--version",
        action="store_true",
        help="Ipakita ang bersyon ng DirStructGen"
    )

    args = parser.parse_args()

    if args.include_output:
        touch_output_file(args.output)

    output_name = os.path.basename(args.output)

    # =========================
    # BUILD IGNORE SET
    # =========================
    gitignore_set = set()

    if not args.no_gitignore:
        gitignore_set = load_gitignore(args.path)

    ignore_set = (
        gitignore_set |
        set(DEFAULT_IGNORE) |
        set(args.ignore or [])
    )

    if args.include_output:
        final_ignore = ignore_set
    else:
        final_ignore = ignore_set | {output_name}

    # =========================
    # GENERATE OUTPUT
    # =========================

    tree = generate_tree(args.path, final_ignore)

    save_markdown(tree, args.output, args.title)

    print(f"\n  Nalikha ang direktoryo: {args.output}")

# =========================
# ENTRY POINT
# =========================
if __name__ == "__main__":
    main()