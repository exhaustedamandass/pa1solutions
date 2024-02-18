# Task Description

The New European Empire is committed to solve all serious problems that make European citizens uncomfortable. Thanks to its effort, there are no longer problems with the light bulbs, vacuum cleaners, diesel motors, electric kettles, and coins. The last problem was indeed very interesting. The citizens grumble about the weight of coins in their valets. Therefore, there was introduced a new directive that requires all amounts must be paid such that the number of coins and notes is as low as possible.

You were ordered to develop a program to achieve this, i.e., given the list of currencies and an amount, the program prints how many coins/notes must be used to pay.

The input is a list of nominal coins/notes. The values are integers separated by whitespace and terminated by a value o 0. Following the list, there are integers representing the amount to pay. The program processes each input and prints out the result (i.e., the minimum number of coins/notes required to pay the amount). The program terminates when there are no further problems to solve, i.e., when the EOF is reached in the input.

The output format is clear form the attached example runs. There may exist amounts that cannot be paid using the nominal coins/notes. The output format is different (see below), however, such amounts are not considered to be an error.

If the input is invalid, the program prints out an error message and terminates. The following is considered invalid:

invalid (not an integer, negative) nominal value,
missing 0 to terminate the list of nominal values,
an empty list of nominal coins/notes,
invalid (not an integer, negative) amount to analyze.