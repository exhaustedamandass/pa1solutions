# Task Description

The task is to develop a program to check palindromes.

The input of the program is a list of strings. Each string is placed on a separate input line and is terminated by a newline character. The processing of input strings terminates when all input lines are read, i.e., when the program reaches EOF.

The output of the program is a decision whether the input string is a palindrome, or not. The palindrome testing routine ignores all whitespace characters. There are three possible answers:

the string is a palindrome, moreover, the upper/lower case matches for all symmetric characters,
the string is a palindrome, however, the upper/lower case does not always match,
the string is not a palindrome.
If the input is invalid, the program reports an error message and terminates. The error message is printed to the standard output (do not send it to the standard error output). The following is considered an error:

an empty input line (just a newline),
a line is not terminated by a newline (\n),
the input string consists only of whitespace characters.
