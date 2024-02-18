# Task Description

The task is to develop a program pro evaluate simple arithmetic expressions.

The input consists of two decimals separated by an operator and terminated by the equal sign. The program computes the expression based on the operator:

+ means the sum,
- means the difference,
* means the product,
/ means the integral fraction (i.e., 3.5 / 1.5 = 2, how many times the divisor fully fits into the dividend).
Other operations are not supported, the program rejects such inputs. The output formats are clear from the examples below.

If the input is invalid, the program must reject it. Use standard output to print the error message (do not use standard error output). The following is considered an error:

the input numbers are not valid decimals,
the divisor is 0 (operation /),
the operation character is missing, or is not one of +, -, *, or /,
the equal character (=) is missing.