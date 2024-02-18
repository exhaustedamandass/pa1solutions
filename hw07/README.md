# Task Description

The task is to develop a program that solves logical game - "maximum token sum".

Two players A and B play the game. There is a row of tokens on the table. The length of the row is between 1 and 100 tokens. Each token holds an integer number - the value of the token. The value may be positive, zero, or negative. The players alternate, the game is started by player A. The player on move removes one or two tokens. Moreover, a player is not allowed to remove two tokens in two consecutive turns (i.e., if a player removes two tokens in a turn, then the player must remove just one token in his next turn). The player may choose the tokens, however, the tokens may only be removed from the beginning or from the end of the row. Even more, if a player decides to remove two tokens from the same end of the row, then the first/last token must be removed first and the (now unblocked) token may be removed second. The game ends when the last token is removed. The player with the greater sum of tokens wins the game.

We assume both players play the best strategy. That is, each player removes the tokens such that his sum is the highest possible. The task is to develop a program that finds the moves and decides who wins the game under these assumptions.

The input of the program is a sequence of integers. The sequence defines the row of tokens. The tokens are referred to by integer indices, index 0 represents the first token, index 1 second, ...

The output of the program is the list of moves. Each move is described on a single output line. A move starts with player id (A or B, alternating), then there is the index of the token being removed (two indices if two tokens are removed) and the value(s) of the token(s) being removed. The last output line lists the sum of tokens for both players.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below) and terminate. If displayed, the error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

the input is an empty sequence, or the sequence exceeds 100 integers,
a value in the sequence is not an integer.
Example