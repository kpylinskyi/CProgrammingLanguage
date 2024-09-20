# 1.1 Getting Started
The only way to learn a new programming language is by writing programs in it. The first
program to write is the same for all languages:
Print the words

## Hello world
[`hello, world`](hello_world/main.c)

## Variables and Arithmetic Expressions
The next program uses the formula C=(5/9)(F-32) to print the table of Fahrenheit
temperatures and their centigrade or Celsius equivalents.

#### Data types
- char     character                          - a single byte
- short    short integer                      - 2 bytes
- int      integer                            - 4 bytes
- long     long integer                       - 8 bytes
- float    floating point                     - 8 bytes
- double   double-precision floating point    - 16 bytes

#### while loop
The while loop operates as follows: The condition in parentheses is tested. If it is true (fahr
is less than or equal to upper), the body of the loop (the three statements enclosed in braces)
is executed. Then the condition is re-tested, and if true, the body is executed again. When the
test becomes false (fahr exceeds upper) the loop ends, and execution continues at the
statement that follows the loop. There are no further statements in this program, so it
terminates.

[fahrenheit to celsius with while loop](while_statement/main.c)

## The for statement
The for statement is a loop, a generalization of the while. If you compare it to the earlier
while, its operation should be clear. Within the parentheses, there are three parts, separated
by semicolons. The first part, the initialization

## Symbolic Constants
A `#define` line
defines a symbolic name or symbolic constant to be a particular string of characters:
`#define name replacement list`

[fahrenheit to celsius with for loop](for_statement/main.c)

## Character Input and Output
The standard library provides several functions for reading or writing one character at a time,
of which getchar and putchar are the simplest. Each time it is called, getchar reads the
next input character from a text stream and returns that as its value. That is, after
`c = getchar();`
the variable c contains the next character of input.

The function putchar prints a character each time it is called:
`putchar(c);`