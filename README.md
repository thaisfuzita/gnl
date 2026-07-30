*This project has been created as part of the 42 curriculum by tjulya-c*

## Description

**get_next_line** is a C function that reads a file descriptor one line at a time, returning each line with successive function calls until the end of the file is reached.

The goal of this project is to deepen understanding of fundamental C programming concepts, including:
- Static variables and their behavior across multiple function calls
- File descriptors and the behavior of the read function
- Dynamic memory allocation and preventing memory leaks using malloc and free

## Bonus Feature

The bonus part of this project introduces the ability to manage **multiple file descriptors** simultaneously. 

This means you can read from multiple files at the same time, interleaving the `get_next_line` calls (e.g., reading line 1 from `fd1`, then line 1 from `fd2`, and then line 2 from `fd1`) without losing the reading thread of any file descriptor or mixing up their contents.

**Technical differences in the Bonus:**
- Instead of using a single static variable pointer like in the mandatory part, the bonus version uses an array of static pointers (`static char *remainder[FD_MAX]`). 
- `FD_MAX` is defined as `1024`, allowing the function to independently track the leftover text for up to 1024 different file descriptors at the same time.

## Instructions

### Compilation

You must define a BUFFER_SIZE at compile time to specify how many bytes the function should read at once:

**For the mandatory part:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_tester
```

**For the bonus part:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_tester_bonus
```

### Usage in your projects

Include the header in your C files:

**For the mandatory part:**
```c
#include "get_next_line.h"
```

**For the bonus part:**
```c
#include "get_next_line_bonus.h"
```

Here is a basic example using multiple file descriptors (Bonus):

```C
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1;
    char *line2;

    line1 = get_next_line(fd1);
    printf("Fd 1: %s", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("Fd 2: %s", line2);
    free(line2);

    close(fd1);
    close(fd2);
    return (0);
}
```

## Technical Choices

- **Static Variable:** A single static variable remainder is used to store the leftover bytes after a newline (\n) is extracted, ensuring the next function call picks up exactly where the previous one left off. *(In the bonus, this is an array of static variables to track multiple FDs)*
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