Here's an optimized and expanded version of your notes, structured for clarity and comprehensiveness:

---

# 1.1 Getting Started

To effectively learn a new programming language, the most effective method is through hands-on programming. One of the first programs to write in any language is typically:

## Hello World

The classic "Hello, World!" program, which outputs the phrase "Hello, World!" to the screen.

- **Example Code**: [Hello, World Program](HelloWorld/main.c)

---

## Variables and Arithmetic Expressions

In subsequent programs, we can utilize formulas for conversions. For instance, to convert Fahrenheit to Celsius, we use the formula:  
**C = (5/9) × (F - 32)**  
This program will generate a table that displays Fahrenheit temperatures alongside their Celsius equivalents.

### Data Types

Understanding data types is crucial for variable declaration and memory allocation. Here are the basic data types in C:

- **char**: Represents a character (1 byte)
- **short**: Represents a short integer (2 bytes)
- **int**: Represents a standard integer (4 bytes)
- **long**: Represents a long integer (8 bytes)
- **float**: Represents a single-precision floating point number (4 bytes)
- **double**: Represents a double-precision floating point number (8 bytes)

---

## Control Structures

### The `while` Loop

The `while` loop continuously executes a block of code as long as a specified condition is true. For example, in a temperature conversion program:

- The condition is evaluated before each iteration.
- The loop continues until the condition evaluates to false.
- Upon exiting the loop, the program continues execution with the subsequent code.

**Example Code**:  
- [Fahrenheit to Celsius using `while`](FahrCelsiusLoop/main.c)

---

### The `for` Loop

The `for` loop is a more structured looping construct that consists of three main parts, making it versatile for different scenarios:

1. **Initialization**: Setting up a counter variable.
2. **Condition**: The loop continues while this condition is true.
3. **Increment/Update**: Adjusting the counter variable.

Comparing it to the `while` loop can help in understanding its usage.

**Example Code**:  
- [Fahrenheit to Celsius using `for`](FahrToCelsius/main.c)

---

## Symbolic Constants

Symbolic constants can be defined using the `#define` directive, allowing for more readable code by associating a name with a specific value:

```c
#define PI 3.14159
```

---

## Character Input and Output

The C standard library provides functions for reading and writing characters:

- **Input**: `getchar()` reads the next character from the input stream.
  ```c
  char c = getchar();
  ```
- **Output**: `putchar()` writes a character to the output stream.
  ```c
  putchar(c);
  ```

---

## File Copying

By leveraging `getchar()` and `putchar()`, you can create a simple program that copies input to output character by character, illustrating the basic I/O operations in C.

**Example Code**:  
- [File Copying Program](EchoInput/main.c)

---

## Word Counting

This program counts lines, words, and characters, defining a "word" as any sequence of characters that excludes blanks, tabs, or newlines—similar to the UNIX `wc` command.

**Example Code**:  
- [Word Line Char Counting Program](WordLineCharCounter/main.c)  
- [New Line Word Printer](NewLineWordPrinter/main.c)

### Code Snippet for Initialization

To initialize multiple variables simultaneously, use:
```c
nl = nw = nc = 0;
```

### Logical Operators

In this program, you will encounter the logical OR operator:
```c
if (c == ' ' || c == '\n' || c == '\t')
```
This checks if `c` is a space, newline, or tab.

### Conditional Statements

The `if else` statement allows for alternative actions based on the truth of a condition:
```c
if (expression) statement1;
else statement2;
```

---

## Arrays

Arrays in C are used to store multiple values of the same type. For instance, a program might count the occurrences of digits using an array rather than individual variables.

**Example Code**:  
- [Digit Counter Program](DigitCounter/main.c)

### Array Declaration

To declare an array of integers:
```c
int ndigit[10];
```
This creates an array `ndigit` with 10 elements, representing digits 0 through 9.

### Character-to-Integer Conversion

To check if a character represents a digit:
```c
if (c >= '0' && c <= '9')
```
You can convert the character to its integer value with:
```c
int digit_value = c - '0';
```

**Example Code**:  
- [Character Frequency Histogram](CharFreqHistogram/main.c)

---

## Functions

In C, functions serve as a means to encapsulate computations, making code modular and reusable. Here’s an overview:

### Function Definition

A function definition has the following structure:
```c
return-type function-name(parameter-declarations) {
    // declarations
    // statements
}
```

**Example**: A power function
**Example Code**:  
- [Power function](Power/main.c)

### Function Prototypes

The function prototype declares the function's name, return type, and parameters:
```c
int power(int base, int n);
```
This informs the compiler about the function's usage.

### Call by Value

In C, function arguments are passed by value, meaning that the function operates on copies of the original variables. Changes made to parameters within the function do not affect the arguments in the caller.

**Example Code**:
```c
int power(int base, int n) {
    int p;
    for (p = 1; n > 0; --n) {
        p = p * base;
    }
    return p;
}
```

---

## Character Arrays

Character arrays (strings) are a fundamental type in C. To illustrate their usage, let's create a program that reads multiple lines of text and prints the longest line.

### Program Outline

1. **Input**: Continuously read lines until EOF.
2. **Comparison**: Check if the current line is longer than the previously longest line.
3. **Storage**: Save the longest line and its length.
4. **Output**: Print the longest line.

**Example Code**:  
- [Longest Line Printer](LongestLinePrinter/main.c)

### Function Communication

The `getline` function returns the length of the read line and signals EOF when necessary. It operates on the principle of passing arguments and receiving values.

The `copy` function does not return a value, using `void` as its return type.

### String Termination

The `\0` (null character) marks the end of strings in C, crucial for functions like `printf` which expect null-terminated strings.

### Reversing Strings

Write a function that reverses a string, demonstrating string manipulation in C.

**Example Code**:  
- [String Reverser](Reverser/main.c)

## External Variables and Scope

In C, **local (automatic) variables** are declared within functions and exist only during the function’s execution. They are recreated each time the function is called, and their values do not persist between calls. These variables disappear when the function exits.

**External (global) variables**, on the other hand, are declared outside any function and can be accessed by any function within the program. Unlike local variables, external variables retain their values throughout the program’s runtime, making them useful for sharing data between functions without needing to pass arguments.

To use an external variable in a function, you can declare it using the `extern` keyword. This tells the compiler that the variable exists elsewhere. However, if the external variable is defined before the function using it, the `extern` declaration is optional.

While external variables offer convenience, they can make programs harder to maintain, as any function can change them, leading to unintended side effects. It's generally better to use local variables and pass them through function arguments to improve code clarity and reduce dependency.

In large programs, external variable declarations are often placed in **header files** (with a `.h` extension), which can be shared across multiple source files using the `#include` directive. This helps keep the code organized and modular.

#### Exercise 1-20. 
Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?

[Detab](Detab/main.c)

#### Exercise 1-21. 
Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

[Entab](Entab/main.c)

#### Exercise 1-22. 
Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.

[Fold](Fold/main.c)

#### Exercise 1-23. 
Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.

[Remove Comments](RemoveComments/main.c)

#### Exercise 1-24. 
Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)