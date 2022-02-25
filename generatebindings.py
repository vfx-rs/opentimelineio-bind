"""
Run this in either Python 2 or Python 3 to automatically build the sys bindings.

You'll need:

- bindgen (see https://rust-lang.github.io/rust-bindgen/command-line-usage.html)
- Python 2 or 3

"""

import subprocess
import os

ROOT_DIR = os.path.join(os.path.dirname(__file__), "src")


def main():
    rs_path = os.path.join(ROOT_DIR, "lib.rs")
    header_path = os.path.join(ROOT_DIR, "lib.h")
    # This runs bindgen -o lib.rs lib.h -- -I/path/to/src
    subprocess.check_call(["bindgen", "-o", rs_path, header_path, "--", "-I{}".format(ROOT_DIR)], cwd=ROOT_DIR)


if __name__ == "__main__":
    main()
