*This project has been created as part of the 42 curriculum by ahrahmou*

# get_next_line

A C function that reads a line from a file descriptor, one line at a time.

## Description

`get_next_line` is a function that returns a line read from a file descriptor. It handles multiple file descriptors and manages memory efficiently using a static variable to store leftover data between function calls.

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

- `fd`: The file descriptor to read from

### Return Value

- Returns the line read, including the terminating newline character `\n` (if present)
- Returns `NULL` when there is nothing more to read or if an error occurred

## Features

- Reads from any valid file descriptor (files, stdin, etc.)
- Handles multiple consecutive calls to read an entire file line by line
- Uses a configurable buffer size via `BUFFER_SIZE` macro
- Efficient memory management with static variable for leftover data
- Handles edge cases like empty lines, files without trailing newlines, etc.

## Compilation

### Basic Compilation

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line.h
```

### With Custom Buffer Size

You can define a custom `BUFFER_SIZE` during compilation:

```bash
cc -Wall -Wextra -Werror -DBUFFER_SIZE=42 get_next_line.c get_next_line_utils.c get_next_line.h
```

The default `BUFFER_SIZE` is set to 10 in the header file if not specified.

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Open a file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // Read and print each line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## Project Structure

```
.
├── get_next_line.c         # Main function implementation
├── get_next_line.h         # Header file with prototypes and definitions
└── get_next_line_utils.c   # Utility functions
```

### Files Description

- **get_next_line.c**: Contains the main `get_next_line` function and helper functions for line extraction and buffer management
- **get_next_line.h**: Header file with function prototypes, includes, and buffer size definition
- **get_next_line_utils.c**: Contains utility functions (`ft_strdup`, `ft_strjoin`, `ft_substr`, `ft_strlcat`, `ft_strchr`)

## Implementation Details

The function uses the following approach:

1. **Static Variable**: Maintains a static `leftover` variable to store data that hasn't been returned yet
2. **Buffer Reading**: Reads from the file descriptor in chunks of `BUFFER_SIZE` bytes
3. **Line Extraction**: Searches for newline characters and extracts complete lines
4. **Memory Management**: Properly allocates and frees memory to avoid leaks

### Utility Functions

- `ft_strlen`: Calculates string length
- `ft_strdup`: Duplicates a string
- `ft_strjoin`: Concatenates two strings
- `ft_substr`: Extracts a substring
- `ft_strlcat`: Concatenates strings with size limit
- `ft_strchr`: Finds first occurrence of a character

## Notes

- The function reads one line at a time, making it memory efficient
- Works with standard input, files, and other file descriptors
- Handles binary files and various line ending formats
- Properly manages memory to prevent leaks

## Author

ahrahmou (ahrahmou@student.42.fr)

## License

This project is part of the 42 School curriculum.
