This project has been created as a part of the 42 curriculum by Khzernou.

# Description

The ft_printf project is a custom implementation of the standard C library printf function. The primary goal of this project is to learn how to handle variadic functions in C and to understand the workings of formatted output.

I explored how data is parsed from a format string and how different data types (integers, strings, hexadecimals, etc.) are converted into characters for display.

Key Features
Variadic Arguments: Efficiently handles a variable number of arguments using the stdarg.h library.

Format Specifiers: Supports the following standard conversions:
%c - Prints a single character.
%s - Prints a string.
%p - Prints a void * pointer in hexadecimal format.
%d / %i - Prints a decimal (base 10) number.
%u - Prints an unsigned decimal (base 10) number.
%x / %X - Prints a number in hexadecimal (base 16) lowercase or uppercase format.
%% - Prints a percent sign.

# Instructions

Compilation
The project includes a Makefile that compiles the source files into a library named libftprintf.a. 
To compile, run the following command in your terminal:
make
Add this to the makefile to have a executable file. 
test: $(NAME)
	cc -Wall -Wextra -Werror main.c $(NAME)
Cleaning Up
make clean: Removes object files.
make fclean: Removes object files and the compiled library.
make re: Recompiles the entire project.

# Resources
man 3 printf: The primary reference for behavior and return values.
Variadic Functions: GNU C Library Documentation on stdarg.h.
Logic Brainstorming: I used ai to clarify the behavior of edge cases (e.g., how printf handles NULL strings or the minimum value of an integer).