# Task Description

The task is to develop a program which prints out quotations.

The input of the program is an integer. The integer is in range 0 to 8 (inclusive). The value is an identifier of the quotation to print out.

The output of the program is a quotation. There is a total of 9 different quotations, the input value identifies the particular quotation to print out. The quotations are listed in the sample runs below. Please note the quotation is printed with a newline character (\n) at the end.

The program must validate input data. If the input is invalid, the program detects it, outputs an error message and terminates. If displayed, the error message must be displayed on the standard output (do not send it to the standard error output) and the error message must be terminated by a newline (\n). The input is considered invalid, if:

the program cannot read an integer from the input or
the integer read from the input is outside of interval [0 to 8].
Please note the program outputs various error messages. There is an error message if the program is unable to read the input integer and a different error message if the input integer is outside of the valid range (see example runs below).

Please strictly adhere to the format of the output. The output must exactly match the output of the reference program. The comparison is done by a machine, the machine requires an exact match. If your program provides output different from the reference, the program is considered malfunctioning. Be very careful, the machine is sensitive even to whitespace characters (spaces, newlines, tabulators). Please note that all output lines are followed by a newline character (\n). This applies even to the last line of the output, moreover, this applies even to the error message. Download the enclosed archive. The archive contains a set of testing inputs and the expected outputs. Read Progtest FAQ to learn how to use input/output redirection and how to simplify testing of your programs.

Your program will be tested in a restricted environment. The testing environment limits running time and available memory. The exact time and memory limits are shown in the reference solution testing log. However, neither time nor memory limit could cause a problem in this simple program. Next, the testing environment prohibits the use of functions which are considered "dangerous" (functions to execute other processes, functions to access the network, ... ). If your program uses such functions, the testing environment refuses to execute the program. For example, if your code would be similar to the following:

int main ( int argc, char * argv [] )
{
 
  ...
     
  system ( "pause" ); /* prevent program window from closing */
  return 0;
}
This will not work properly in the testing environment - it is prohibited to execute other programs. (Even if the function were allowed, this would not work properly. The program would infinitely wait for a key to be pressed, however, no one will press any key in the automated testing environment. Thus, the program would be terminated on exceeded time limit.) If you want to keep the pause for your debugging and you want the program to be accepted by the Progtest, use the following trick:

int main ( int argc, char * argv [] )
{
 
  ...

#ifndef __PROGTEST__
  system ( "pause" ); /* this is ignored by Progtest */
#endif /* __PROGTEST__ */
  return 0;
} 