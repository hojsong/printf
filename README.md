# ft_printf

[한국어 버전](README.md.kr)

## Overview
ft_printf is a reimplementation of the standard `printf` function in C. This project serves as an introduction to formatted output, variadic functions, and low-level string manipulation in C.

- **Objective:** Create a library that replicates the behavior of `printf` with a subset of its functionalities.
- **Key Features:**
  - Supports formatted output for various data types.
  - Handles variadic arguments using `stdarg.h`.

## Features
- **Supported Conversions:**
  - `%c` - Character.
  - `%s` - String.
  - `%p` - Pointer address.
  - `%d` / `%i` - Integer (signed decimal).
  - `%u` - Unsigned integer.
  - `%x` / `%X` - Hexadecimal (lowercase/uppercase).
  - `%%` - Percent sign.

- **Bonus Features:**
  - Field width, precision, and flags (`-`, `0`).

## Requirements
- **Operating System:** Linux or macOS.
- **Dependencies:** None (standard C library).

## Installation and Usage
### Clone the Repository
```bash
git clone [repository URL]
cd ft_printf
```

### Build the Library
```bash
make
```

### Use in Your Project
1. Include the library:
- Compile `libftprintf.a` with your project.
- Use `#include "ft_printf.h"` in your source files.

2. Example:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The number is %d.\n", "World", 42);
    return (0);
}
```

3. Compile:
```bash
gcc main.c libftprintf.a -o program
```

### File Structure
- `srcs/`: Source code files.
- `ft_printf.h`: Header files.
- `Makefile`: Build script.

### Testing
- Run the provided test cases to ensure your implementation matches the behavior of the standard printf.

### References
- C Variadic Functions
- Printf Manual