# Task Description

The task is to develop a program to display a multiplication table.

The input of the program is an integer - the upper limit of the table.

The output of the program is a multiplication table for products 1 x 1 to n x n. The table is displayed without the symmetric duplicates, i.e., it is of a triangular shape. All columns in the table have equal widths, the width is determined by the number of digits in the highest product (plus 1 digit). The newline directly follows the last number on the line, there are not any extra whitespace characters at the end of the output lines.

If the input is invalid, the program must reject it. Use standard output to print the error message (do not use standard error output). The following is considered an error:

the input does not contain an integer,
the input integer is negative or zero.