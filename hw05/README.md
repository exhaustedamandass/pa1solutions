# Task Description

The task is to develop a program that generates strong magic spells.

The input of the program is a list of words. A word is formed by any number of non-whitespace characters, whitespace characters are word delimiters. The reading of input words terminates when there is EOF active in the input.

The task is to use the input words, rearrange them and form a magic spell. Moreover, the generated spell must be as strong as possible. The strength of a spell is determined as follows: the words are converted to lowercase and spaces are removed. The greater the resulting string is, the more powerful the spell is (we are using lexicographical ordering for the comparison). For instance, words Lorem ipSum dolOR may be arranged in 6 possible ways:

Lorem ipSum dolOR  => loremipsumdolor
Lorem dolOR ipSum  => loremdoloripsum
ipSum dolOR Lorem  => ipsumdolorlorem
ipSum Lorem dolOR  => ipsumloremdolor
dolOR Lorem ipSum  => dolorloremipsum
dolOR ipSum Lorem  => doloripsumlorem
of them, the lexicographically greatest is loremipsumdolor, thus the correct answer is Lorem ipSum dolOR.

The output of the program is the list of the input words that forms the strongest spell. If there are two or more such lists that form equally strong spell, output the combination that places longer words first. This is demonstrated in the example run #3. Moreover, format the output nicely:

words are separated by a single space,
there are no extra spaces before the first/after the last word on a line,
the output line is as long as possible, but the length will not exceed 80 characters (the 80 char limits includes spaces),
if there is an extra long word (more than 80 characters), then place such word on a separate line.
The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. The error message must be displayed to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

the input does not contain any word,
there is the same word twice (or more times) in the input. We do not distinguish upper and lower case letters when comparing the words (case insensitive comparison).