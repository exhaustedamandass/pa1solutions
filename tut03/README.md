# Task Description

The task is to develop a program that computes the duration of a time interval.

The input consists of two times - the start time t1 and end time t2. Both times are given in the format h:m:s,ms where h, m, s, and ms stands for hours, minutes, seconds, and milliseconds, respectively. The program reads the input and computes the time elapsed between t1 and t2. The result is printed, the output format is again h:m:s,ms, see sample program runs below.

The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output). The input is considered invalid, if:

the values are not numerical,
out-of-bounds values (max. 23 hours, max. 59 minutes, max. 59 seconds, max. 999 milliseconds),
a colon or comma is missing,
start time is greater than the end time.