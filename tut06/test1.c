#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
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
int dateToIndex(int day, int month, int year, int *idx) {
    if(!isValid(year, month, day)){
        return 0;
    }
    int total = 0;
    if (month > 1) {
        for (int i = 1; i < month; i++) {
            total += daysmonth(year, i);
        }
    }
    total += day;
    *idx = total;
    return 1;
}

#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;
    assert(dateToIndex( 1,  1, 2000, &idx) == 1 && idx == 1);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */

