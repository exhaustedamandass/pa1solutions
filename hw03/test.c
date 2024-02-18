#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct
{
  int m_TotalDays;
  int m_WorkDays;
} TResult;
#endif /* __PROGTEST__ */

int isleapyear(int year){
  if((year % 4==0 && year%100 !=0) || (year%400==0 && year%4000!=0)){
    return 1;    
  }else{
    return 0;
  }
}
int is31days(int m){
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 1;
        return 0;
}
int isValid(int year, int month, int day){
  if(year < 2000 || month < 1 || month > 12 || day < 1|| (is31days(month) && day > 31 && month != 2) || (isleapyear(year) && month == 2 && day > 29) || (!isleapyear(year) && month == 2 && day > 28) || (!is31days(month) && day > 30 && month != 2)){
    return 0;
  }
  return 1;
}
int weekday(int year, int month, int day){
    int wday = 0;
    wday=((day + 
        ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
        + (365 * (year + 4800 - ((14 - month) / 12)))
        + ((year + 4800 - ((14 - month) / 12)) / 4)
        - ((year + 4800 - ((14 - month) / 12)) / 100)
        + ((year + 4800 - ((14 - month) / 12)) / 400)
        - 32045)
        +1) % 7;
    return wday;
}

int daysmonth( int y, int m){
  switch (m)
  {
  case 2:
    return 28 + isleapyear(y);
    break;
  default:
    return 30 + is31days(m);
    break;
  }
}


bool isWorkDay ( int y, int m, int d )
{
  if((m == 1 && d == 1) || (m == 5 && (d == 1 || d == 8)) || (m == 7 && (d == 5 || d == 6)) || (d == 28 && (m == 9 || m == 10)) || (m == 11 && d == 17) || (m == 12 && (d>= 24 && d<=26)) || !isValid(y, m, d)){
    return false;
  }
  int result = weekday(y, m , d);
  if(result >= 1 && result <= 5){
    return true;
  }else{
    return false;
  }
}
int daysfromjan1(int y, int m, int d){
  int total = 0;
  if (m > 1) {
      for (int i = 1; i < m; i++) {
          total += daysmonth(y, i);
      }
  }
  total += d;
  return total;
}
int freedaysmonth(int year, int month){
  int total = 0;
  for (int i = 1; i <= daysmonth(year, month); i++)
  {
    if(!isWorkDay(year, month, i)) total++;
  }
  return total;
}
int freedaysfromjan1(int y, int m, int d){
  int total = 0;
  if (m > 1) {
      for (int i = 1; i < m; i++) {
          total += freedaysmonth(y, i);
      }
  }
  for (int i = 1; i <= d; i++)
  {
    if(!isWorkDay(y, m, i)){
      total++;
    }
  }
  return total;
}

int diffdays ( int y1, int m1, int d1, int y2, int m2, int d2 ){
    int days = 0;
    for (int i = y1; i < y2; i++)
    {
      days += daysfromjan1(i, 12, 31);
    }
    days += daysfromjan1(y2, m2, d2);
    days -= daysfromjan1(y1, m1, d1);
    days++;
    return days;
}

int freediffdays(int y1, int m1, int d1, int y2, int m2, int d2 ){
  int days = 0;
  for (int i = y1; i < y2; i++)
  {
      days += freedaysfromjan1(i, 12, 31);
  }
  days += freedaysfromjan1(y2, m2, d2);
  days -= freedaysfromjan1(y1, m1, d1);
  if(!isWorkDay(y1, m1, d1)){
    days++;
  }
  return days;
}


TResult countDays ( int y1, int m1, int d1,
                    int y2, int m2, int d2 )
{
  TResult result; 
  result.m_WorkDays = 0;
  if(y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2) || !isValid(y1, m1, d1) || !isValid(y2, m2, d2)){
    result.m_TotalDays = -1;
    result.m_WorkDays = -1;
    return result;
  }
  result.m_TotalDays = diffdays(y1, m1, d1, y2, m2, d2);
  if(result.m_TotalDays < 0){
    result.m_TotalDays = -1;
    result.m_WorkDays = -1;
    return result;
  }
  result.m_WorkDays = result.m_TotalDays - freediffdays(y1, m1, d1, y2, m2, d2);
  return result;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TResult r;

  //printf("%d\n", weekday(2023, 10, 28));
  
  assert ( isWorkDay ( 2023, 10, 10 ) );

  assert ( ! isWorkDay ( 2023, 11, 11 ) );

  assert ( ! isWorkDay ( 2023, 11, 17 ) );

  assert ( ! isWorkDay ( 2023, 11, 31 ) );

  assert ( ! isWorkDay ( 2023,  2, 29 ) );

  assert ( ! isWorkDay ( 2004,  2, 29 ) );

  assert ( isWorkDay ( 2008,  2, 29 ) );

  assert ( ! isWorkDay ( 2001,  2, 29 ) );

  assert ( ! isWorkDay ( 1996,  1,  2 ) );
  
  
  r = countDays ( 2023, 11,  1,
                  2023, 11, 30 );
  //printf("%d 21\n", r.m_WorkDays);
  assert ( r . m_TotalDays == 30 );
  assert ( r . m_WorkDays == 21 );

  r = countDays ( 2023, 11,  1,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 17 );
  assert ( r . m_WorkDays == 12 );
  
  r = countDays ( 2023, 11,  1,
                  2023, 11,  1 );
  
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 1 );

  r = countDays ( 2023, 11, 17,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 0 );

  r = countDays ( 2023,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 365 );
  assert ( r . m_WorkDays == 252 );

  r = countDays ( 2024,  1,  1,
                  2024, 12, 31 );
  assert ( r . m_TotalDays == 366 );
  assert ( r . m_WorkDays == 254 );

  r = countDays ( 2000,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 8766 );
  assert ( r . m_WorkDays == 6072 );

  r = countDays ( 2001,  2,  3,
                  2023,  7, 18 );
  assert ( r . m_TotalDays == 8201 );
  assert ( r . m_WorkDays == 5682 );

  r = countDays ( 2021,  3, 31,
                  2023, 11, 12 );
  assert ( r . m_TotalDays == 957 );
  assert ( r . m_WorkDays == 666 );

  r = countDays ( 2001,  1,  1,
                  2000,  1,  1 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );//

  r = countDays ( 2001,  1,  1,
                  2023,  2, 29 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );
  
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
