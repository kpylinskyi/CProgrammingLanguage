# Chapter 2 - Types, Operators and Expressions

# 2.2 Data Types and Sizes

- `char`    :   a single byte, capable of holding one character in the local character set
- `int`     :   an integer, typically reflecting the natural size of integers on the host machine
- `flaot`   :   single-precision floating point
- `double`  :   double-precision floating point

In addition, there are a number of qualifiers that can be applied to these basic types. `short`
and `long` apply to integers: 
```c
short int sh;
long int counter;
```
The word int can be omitted in such declarations, and typically it is.


The intent is that short and long should provide different lengths of integers where practical; int will normally be the natural size for a particular machine. short is often 16 bits long, and int either 16 or 32 bits. Each compiler is free to choose appropriate sizes for its own hardware, subject only to the the restriction that shorts and ints are at least 16 bits, longs are at least 32 bits, and short is no longer than int, which is no longer than long.

There is one other kind of constant, the enumeration constant. An enumeration is a list of constant integer values, as in
`enum boolean { NO, YES };`
The first name in an enum has value 0, the next 1, and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the progression from the last specified value, as the second of these examples:
```c
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; /* FEB = 2, MAR = 3, etc. */
```

• If either operand is long double, convert the other to long double.
• Otherwise, if either operand is double, convert the other to double.
• Otherwise, if either operand is float, convert the other to float.
• Otherwise, convert char and short to int.
• Then, if either operand is long, convert the other to long.
