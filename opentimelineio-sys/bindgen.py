import os
import subprocess
import sys
from pathlib import Path

_SYS_SRC_PATH = Path(os.path.dirname(__file__)) / "src"


def main(include_dir: Path):
    rust_path = _SYS_SRC_PATH / "lib.rs"
    header_path = _SYS_SRC_PATH / "lib.h"

    subprocess.check_call(
        [
            "bindgen",
            "-o",
            str(rust_path),
            str(header_path),
            "--",
            f"-I{str(include_dir)}",
        ],
        cwd=_SYS_SRC_PATH,
    )


if __name__ == "__main__":
    main(Path(sys.argv[1]))
