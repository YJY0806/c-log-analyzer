# C Log Analyzer

A small command-line log analyzer written in C.

The program reads a log file, counts different log levels, and stores all `ERROR` messages using dynamic memory allocation.

## Features

- Read a log file from the command line
- Count total log lines
- Count `INFO`, `WARNING`, and `ERROR` entries
- Store complete `ERROR` messages dynamically
- Print all detected `ERROR` messages
- Support compilation with Makefile
- Release dynamically allocated memory after use

## Project Structure

```text
c-log-analyzer/
├── main.c
├── analyzer.c
├── analyzer.h
├── sample.log
├── Makefile
└── README.md
```

`main.c` handles command-line arguments, prints the analysis result, and releases allocated memory.

`analyzer.c` contains the main log analysis logic, including file reading, log-level detection, and dynamic storage of error messages.

`analyzer.h` contains the `LogResult` structure and the analyzer function declaration.

`sample.log` is included as a simple test file.

## Build

Compile the project with:

```bash
make
```

This generates the executable:

```text
analyzer
```

You can also compile it manually with GCC:

```bash
gcc main.c analyzer.c -o analyzer
```

## Usage

Run the analyzer and provide a log file:

```bash
./analyzer sample.log
```

Example output:

```text
File name: sample.log
Total lines: 20
Error lines: 5
Warning lines: 5
Info lines: 10
Full error message: ERROR Failed to connect to authentication service
Full error message: ERROR Permission denied when accessing /etc/shadow
Full error message: ERROR Database query failed
Full error message: ERROR Unable to write report file
Full error message: ERROR Authentication failed for user admin
```

If the filename argument is missing, the program prints the expected usage:

```text
Usage: ./analyzer <filename>
```

## Clean Build Files

Run:

```bash
make clean
```

to remove generated object files and the executable.

## C Concepts Used

This project uses several core C concepts:

- Structs
- Pointers
- File I/O
- Command-line arguments with `argc` and `argv`
- String handling
- Dynamic memory allocation
- `malloc()`, `realloc()`, and `free()`
- Multiple source and header files
- Makefile-based compilation

## Requirements

- GCC
- Make
- Linux or WSL