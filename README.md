# wycat

wycat is a utility program that mimics the Linux cat utility. It is designed to concatenate files and print on standard output. This is a project for Linux Programming (COSC 3750).

## Prerequisites

GNU make is required.

## Installation

Use the GNU make utility to compile.

```bash
make
```

## Synopsis

```bash
./wycat [FILE]...
```

## Description

Concatenate FILE(s) to standard output.
With no FILE, or when FILE is -, read standard input.

## Examples
```bash
./wycat 
    # read from standard input, write to standard output

./wycat f - g 
    # Output f's contents, then standard input, then g's contents.
```

## Author

Jared Spaulding