# Task Description

our task is to develop a program to decide the options to change train in a station.

We assume a station where there are only three trains arriving every day - trains A, B, and C. The trains operate daily, their arrival and departure times are fixed. We know arrival and departure time (hour and minute) for each train. The problem is to decide which train changes are possible. We assume a change from X to Y is possible if the departure time for Y is at least 5 minutes (inclusive) after the arrival time of X. Moreover, the change is possible only if train Y is already in the station or it arrives at most 3 hours after the arrival time of X. (If Y arrived more than the 3 hours after X, we would have to wait more than 3 hours in the station and we would be expelled as a homeless.) Both limits (5 min, 3 hrs) are considered inclusive, this is demonstrated in the example runs below.

The input of your program is 6 timestamps describing train arrival and departure times. Each timestamp is provided in the form of hour and minute, delimited by a colon.

The output of the program is a decision which train changes are possible. The answers are listed for all trains A, B, and C in that order, each answer on a separate line. The format of the output is shown in the example runs below. If there are two trains that can be changed to, the trains are listed in alphabetical order. That is, the following is correct:

Can change to both A and C from B.
whereas the following is incorrect:
Can change to both C and A from B.
Do not forget the newlines after each output line (even after the last one).
If the input is invalid (e.g. input values are not decimal numbers, are negative, or inconsistent), the program detects the problem and prints an error message. The format of the error message is again shown below. The following is considered invalid input:

non-numeric value,
separator (colon) missing, or
invalid time (hour and minute outside the range 0-23 and 0-59, respectively).
If the program detects an error, it immediately stops asking for further input data, it prints out the error message and terminates. Thus, the program must validate input data as it reads them. Do not postpone the checks until the entire input is read. The error message shall be printed on the standard output (do not send it to the standard error output).

Please strictly adhere the format of the output. The output must exactly match the output of the reference program. The comparison is done by a machine, the machine requires an exact match. If your program provides output different from the reference, the program is considered malfunctioning. Be very careful, the machine is sensitive event to whitespace characters (spaces, newlines, tabulators). Please note that all output lines are followed by a newline character (\n). This applies even to the last line of the output, moreover, this applies even to the error message. Download the enclosed archive. The archive contains a set of testing inputs and the expected outputs. Use the attached files to simplify the testing of your program.

Your program will be tested in a restricted environment. The testing environment limits running time and available memory. The exact time and memory limits are shown in the reference solution testing log. However, neither time nor memory limit could cause a problem in this simple program.