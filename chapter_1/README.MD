Here’s a more structured and organized version of your notes, with clear sections, headings, and explanations. The content has been refactored for clarity, readability, and ease of reference:

---

# 1.1 Getting Started

To learn a new programming language, the best approach is to write programs. The first program to write in any language is typically:

### Hello World
The classic "Hello, World" program, which prints the words "Hello, World" to the screen.

- [Hello, World Program](HelloWorld/main.c)

---

## Variables and Arithmetic Expressions

In the next program, we'll use the formula:  
**C = (5/9) × (F - 32)**  
This program prints a table of Fahrenheit temperatures and their Celsius equivalents.

### Data Types

- **char**: Character (1 byte)
- **short**: Short integer (2 bytes)
- **int**: Integer (4 bytes)
- **long**: Long integer (8 bytes)
- **float**: Floating point number (8 bytes)
- **double**: Double-precision floating point number (16 bytes)

---

### The `while` Loop

The `while` loop repeatedly executes a block of code as long as a condition remains true. For example, in a temperature conversion program:

- The condition is tested before each iteration.
- The loop continues until the condition becomes false.
- When the loop ends, the program resumes after the loop.

Example:  
- [Fahrenheit to Celsius using `while`](FahrCelsiusLoop/main.c)

---

## The `for` Loop

The `for` loop is a more generalized looping construct than `while`. It consists of three parts within parentheses, separated by semicolons:

1. Initialization
2. Condition
3. Increment/Update

You can compare it to the earlier `while` loop to better understand its behavior.

- [Fahrenheit to Celsius using `for`](FahrToCelsius/main.c)

---

## Symbolic Constants

You can define symbolic constants using `#define`. This line associates a name with a specific value or replacement text. For example:

```c
#define PI 3.14159
```

---

## Character Input and Output

The C standard library provides basic functions for reading and writing characters:

- `getchar()`: Reads the next input character from a stream.
  ```c
  char c = getchar();
  ```
- `putchar()`: Writes a character to the output stream.
  ```c
  putchar(c);
  ```

---

## File Copying

Using `getchar` and `putchar`, you can write a simple program to copy input to output one character at a time. This demonstrates the simplicity and power of basic I/O operations in C.

- [File Copying Program](EchoInput/main.c)

---

## Word Counting

This program counts lines, words, and characters. A "word" is defined as any sequence of characters that doesn’t contain a blank, tab, or newline. This is similar to the UNIX `wc` command.

- [Word Line Char Counting Program](WordLineCharCounuter/main.c)
- [New Line Word Printer](NewLineWordPrinter/main.c)

### Code Snippet:
To initialize multiple variables in one line, you can use this syntax:
```c
nl = nw = nc = 0;
```

This is equivalent to:
```c
nl = (nw = (nc = 0));
```

### The `||` Operator (Logical OR)
In this program, you’ll encounter the logical OR operator:
```c
if (c == ' ' || c == '\n' || c == '\t')
```
This condition checks if `c` is a space, newline, or tab.

### The `if else` Statement
The `if else` statement lets you specify alternative actions based on whether a condition is true or false:
```c
if (expression) statement1;
else statement2;
```

---

## Arrays

Arrays in C are used to store multiple values of the same type. For example, a program might count occurrences of digits using an array instead of individual variables.

- [Digit Counter Program](DigitCounter/main.c)

### Array Declaration
```c
int ndigit[10];
```
This declares an array `ndigit` with 10 elements, where `ndigit[0]` to `ndigit[9]` represent the digits 0 through 9.

### Character-to-Integer Conversion
To determine if a character represents a digit:
```c
if (c >= '0' && c <= '9')
```

You can convert the character to its corresponding integer value using:
```c
int digit_value = c - '0';
```
This works because characters like `'0'`, `'1'`, etc., have consecutive values in most character sets.

- [Character Frequency Histogram](CharFreqHistogram/main.c)


