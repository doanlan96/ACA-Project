def count_lines(pathname):
    """
    Counts significant lines of code in a C program without multiline comment
    """
    import re
    with open(pathname, "r") as f:
        source = f.read()
    source = source.split("\n")
    source = [line for line in source if len(line.strip()) > 0 ]
    source = [re.sub("\\s+", "", line) for line in source]
    source = [line for line in source if line[:2] != '//' ]
    return len(source)