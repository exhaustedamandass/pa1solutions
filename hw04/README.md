# Task Description

The task is to develop a program to filter financial data.

We are about to analyze account balance data. There is a sequence of numbers in the input, each value represents account balance at some time instant. We need to select a contiguous subsequence of the input data into our presentation. The presentation shall prove that the management did a good job in a long term period. Thus we need to select the longest subsequence of the input data such that the account balance at the beginning of the selected subsequence is less or equal to the account balance at the end of the selected subsequence. Only the values at the beginning/end of the subsequence are relevant, we do not care about the values in the middle of the subsequence.

As an example, if the input sequence is 115 111 57 56 103 96 -1000 100 83 45, the resulting subsequence is 57 56 103 96 -1000 100 83 (it is the longest possible, 83 ≥ 57).

The input of the program is a sequence of integers, the values represent account balance over the time. The length of the sequence is limited to at most 250000 values. The sequence is terminated when the EOF (end-of-file) is reached.

The output of the program is the selected subsequence of maximal length where the last account balance is greater or equal to the first account balance. The program must display the length of the subsequence, the index of the first value, and the index of the last value (both indices are zero-based). There may exist more than one such subsequence. In such a case, the program must display all such subsequences. The input data may be special in that it does not include any subsequence with the required properties. A special message is displayed in this case (see sample runs below).

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and terminate. If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

the input values are not integers,
there were fewer than 2 input values,
there were more than 250000 input values.
