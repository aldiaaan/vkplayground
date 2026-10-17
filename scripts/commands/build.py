from typing import Annotated

import typer

from scripts.constants import BUILD_DIRECTORY
from scripts.utils import run_command


def run(
    args: Annotated[
        list[str] | None,
        typer.Argument(help="Files or directories to format."),
    ] = None,
):
    command = ["cmake", "--build", BUILD_DIRECTORY]

    run_command(command)
