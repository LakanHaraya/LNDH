import os
import argparse

DEFAULT_IGNORE = {
    # ".git",
    # ".pio",
    # ".vscode",
    # "build",
    # "dist",
    # "__pycache__",
    # ".idea",
    # ".DS_Store"
}

def should_ignore(path_part, ignore_set):
    return path_part in ignore_set

def generate_tree(start_path, ignore_set):
    tree_lines = []

    def walk(dir_path, prefix=""):
        try:
            entries = sorted(os.listdir(dir_path))
        except PermissionError:
            return

        entries = [
            e for e in entries
            if not should_ignore(e, ignore_set)
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

def save_markdown(tree_lines, output_file, title):
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(f"# {title}\n\n")
        f.write("```text\n")
        f.write("\n".join(tree_lines))
        f.write("\n```\n")

def main():
    parser = argparse.ArgumentParser(description="Matalinong Panglikha ng Estruktura ng Direktoryo sa Markdown")
    parser.add_argument("-p", "--path", default=".", help="Root project path")
    parser.add_argument("-o", "--output", default="TREE.md", help="Output markdown file")
    parser.add_argument("-i", "--ignore", nargs="*", default=[], help="Extra ignore folders/files")
    parser.add_argument("-t", "--title", default="Project Structure", help="Markdown title")

    args = parser.parse_args()

    ignore_set = DEFAULT_IGNORE.union(set(args.ignore))

    tree = generate_tree(args.path, ignore_set)
    save_markdown(tree, args.output, args.title)

    print(f"✔ Tree generated: {args.output}")

if __name__ == "__main__":
    main()