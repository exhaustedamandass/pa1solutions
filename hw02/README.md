# Task Description

The task is to develop a program to analyze messages from alien civilizations.

Radiastronomes have finally received messages from alien civilizations. Finally! The messages are broadcasted from stars that are similar to our Sun. There are no doubts!

The problem is to decode the messages. Surprisingly, all messages are apparently coded using the same code (a variant of extra-terrestrial UNICODE). Moreover, each alien star broadcasts the same message over and over. One question is: is it possible for all messages to synchronize? That is, is there an time where we receive all the messages from the beginning?

The input of the program is formed by two or more messages. Each message is passed as a single input line. The line is formed by lowercase characters, each character codes the length of a pulse: a=1, b=2, c=4, d=8, ... Next, each line contains one character |, the character denotes the beginning of the message. For example:

ea|babab
represent a message with pulses of length 16, 1, 2, 1, 2, 1, and 2. The length of the message is 16 + 1 + 2 + 1 + 2 + 1 + 2=25 time units. The current position in the message is 16+1=17 time units before the end.

The program is given the messages, message lengths and positions may vary. The program computes when the messages synchronize, i.e. when we start receiving all messages from the beginning. For instance:

ea|babab
d|abaca
will be synchronized in 42 time units:
ea|  bababea|          = 42
d|   abacad|abacad|    = 42
The input of the program consists of the messages as described above. There are at least two messages in the input. The mandatory and optional tests only pass two input messages, more than two messages are tested in the bonus tests.

The output of the program is the time when the input messages synchronize. If the input messages never synchronize, a different output is shown (see sample runs below).

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and terminate. If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

less than two messages in the input,
invalid message format (message must not be empty, it must consist of lower case characters only, there must be exactly one bar ('|') in each message).
Please strictly adhere to the format of the output. The output must exactly match the output of the reference program. The comparison is done by a machine, the machine requires an exact match. If your program provides output different from the reference, the program is considered malfunctioning. Be very careful, the machine is sensitive event to whitespace characters (spaces, newlines, tabulators). Please note that all output lines are followed by a newline character (\n). This applies even to the last line of the output, moreover, this applies even to the error message. Download the enclosed archive. The archive contains a set of testing inputs and the expected outputs. Read Progtest FAQ to learn how to use input/output redirection and how to simplify testing of your programs.