This project has been created as part of the 42 curriculum by ahrahmou

# get_next_line

This project implements the `get_next_line` function, which reads a line from a file descriptor.

## Description

The `get_next_line` function reads and returns a line from a file descriptor, including the newline character at the end (if present). It handles multiple file descriptors and uses a static variable to maintain the reading state between calls.

## Files

- `get_next_line.c` - Main implementation of the get_next_line function
- `get_next_line.h` - Header file with function prototypes and definitions
- `get_next_line_utils.c` - Utility functions used by get_next_line

## Usage

Include the header file in your project:

```c
#include "get_next_line.h"
```

Compile with a defined BUFFER_SIZE:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## Function Prototype

```c
char *get_next_line(int fd);
```

Returns a line read from the file descriptor, or NULL if there's nothing more to read or an error occurred.
