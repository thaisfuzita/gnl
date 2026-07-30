*This project has been created as part of the 42 curriculum by tjulya-c*

## Description

**get_next_line** is a C function that reads a file descriptor one line at a time, returning each line with successive function calls until the end of the file is reached.

The goal of this project is to deepen understanding of fundamental C programming concepts, including:
- Static variables and their behavior across multiple function calls
- File descriptors and the behavior of the read function
- Dynamic memory allocation and preventing memory leaks using malloc and free

## Instructions

### Compilation

You must define a BUFFER_SIZE at compile time to specify how many bytes the function should read at once:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_tester
```

### Usage in your projects

Include the header in your C files:

```c
#include "get_next_line.h"
```

Here is a basic example:

```C
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd1);
    printf("Fd 1: %s", line);
    free(line);

    close(fd1);
    return (0);
}
```

## Technical Choices

- **Static Variable:** A single static variable remainder is used to store the leftover bytes after a newline (\n) is extracted, ensuring the next function call picks up exactly where the previous one left off.
- **Memory Management:** The function handles memory safely by utilizing ft_calloc and cleanly freeing intermediate buffers (reading, temp, etc.) to prevent leaks while reading and updating the remainder.
- **String Manipulation:** The logic is modularized using custom helper functions like ft_strjoin, ft_strchr, and ft_substr to separate responsibilities such as concatenating buffers, searching for newlines, and extracting the next line.

## Resources

### Documentation
- [man 2 read](https://man7.org/linux/man-pages/man2/read.2.html)
- [man 3 malloc](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [42 Norminette Documentation](https://github.com/42School/norminette)

### AI Usage

For this project, AI was used in the following ways:
- Code review to identify edge cases and potential memory leaks
- Clarifications on static variable lifespans
- Assistance with README structure

## Author

Thaís Fuzita - tjulya-c