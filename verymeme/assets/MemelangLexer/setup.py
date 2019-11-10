from setuptools import setup, find_packages

setup(
    name='memelanglexer',
    packages=find_packages(),
    entry_points=
    """
    [pygments.lexers]
    memelanglexer = memelanglexer.lexer:MemelangLexer
    """,
)
