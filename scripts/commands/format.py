from pathlib import Path

import typer

from scripts.utils import run_command


def run(
    args: list[str] | None = typer.Argument(
        None,
        help="Files, directories, or globs to format. Defaults to scanning current directory.",
    ),
):
    targets = args or ["./src", "./lib", "./include"]
    files_to_format: list[str] = []

    CPP_EXTENSIONS = {".cpp", ".hpp", ".h", ".cc", ".cxx", ".hxx"}

    for target in targets:
        path = Path(target)
        if path.is_file() and path.suffix in CPP_EXTENSIONS:
            files_to_format.append(str(path))
        elif path.is_dir():
            for file in path.rglob("*"):
                if file.is_file() and file.suffix in CPP_EXTENSIONS:
                    files_to_format.append(str(file))

    if not files_to_format:
        typer.echo("No C++ files found to format.")
        raise typer.Exit()

    typer.echo(f"Formatting {len(files_to_format)} file(s) with clang-format...")

    run_command(["clang-format", "-i", *files_to_format])
    typer.secho("Formatting complete!", fg=typer.colors.GREEN)
