from typing import Annotated

import typer

from scripts.constants import BUILD_DIRECTORY
from scripts.utils import remove_path


def run(
    args: Annotated[
        list[str] | None,
        typer.Argument(help="Files or directories to format."),
    ] = None,
):
    remove_path(BUILD_DIRECTORY)
