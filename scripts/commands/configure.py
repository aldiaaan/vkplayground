from typing import Annotated

import typer

from scripts.constants import BUILD_DIRECTORY, C_COMPILER, CXX_COMPILER
from scripts.utils import run_command


def run(
    include_tests: Annotated[
        bool,
        typer.Option(
            "--include-tests/--no-include-tests",
            help="Build and run tests alongside the project.",
        ),
    ] = False,
):
    command = [
        "cmake",
        "-B",
        BUILD_DIRECTORY,
        "-G",
        "Ninja",
        f"-DCMAKE_CXX_COMPILER={CXX_COMPILER}",
        f"-DCMAKE_C_COMPILER={C_COMPILER}",
        "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON",
        # "-DVCPKG_INSTALL_OPTIONS=--disable-metrics",
    ]

    if include_tests:
        command.append("-DVK_PLAYGROUND_BUILD_UNIT_TESTS=ON")

    run_command(command)
