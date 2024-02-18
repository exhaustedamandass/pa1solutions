# Task Description

The task is to implement a function (not a whole program, just a function) to convert a date into the day-of-year index.

The required function interface is as follows:

int dateToIndex (int day, int month, int year, int * idx);
Input parameters are the day, month, and year, the parameters positively identify the date to convert,
idx is an output parameter that receives the converted day-of-year index. The day-of-year index starts from 1, i.e., Jan 1 results in idx=1. If the function succeeds, the day index will be written into the output parameter. If the function fails (the input date is invalid), the function does not modify the value of idx in any way.
function return value is a success/failure indication (1 success, 0 failure).
Function parameters are invalid if:

the year is below 2000 (we consider all dates before Jan 1 2000 invalid),
the month is not between 1 and 12,
the day is invalid (1 to 28/29/30/31 based on the month and leap/non-leap year).