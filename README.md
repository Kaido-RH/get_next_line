# README.md

*This project has been created as part of the 42 curriculum by <login1>.*

---

## Description
**get_next_line** is a function that reads a file descriptor and returns one line at a time each time it is called.

It demonstrates the use of static variables, buffers, dynamic memory allocation, and handling partial reads from files or standard input.

Prototype:
```c
char *get_next_line(int fd);
```

---

## Instructions

Compile with your program:
```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

Example use:
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## Algorithm Explanation
The function uses a **static buffer** to store leftover data between calls.

Steps:
1. Read `BUFFER_SIZE` bytes
2. Append to stored data
3. Stop when `\n` is found
4. Return the extracted line
5. Keep the remaining characters for the next call

This avoids losing data and ensures each character is processed only once (O(n)).

---

## Resources
- `man read`
- `man open`
- C dynamic memory documentation

### AI Usage
Used only for explanations and README writing, not for the implementation logic.

