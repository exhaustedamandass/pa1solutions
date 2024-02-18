#ifndef __PROGTEST__
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#endif /* __PROGTEST__ */

long long avg3 ( long long a, long long b, long long c )
{
  double res1 = a;
  res1 /= 3;
  double res2 = b;
  res2 /= 3;
  double res3 = c;
  res3 /= 3;
  long long int res = (res1 + res2 + res3);
  return res;
}

#ifndef __PROGTEST__
int main (int argc, char * argv [])
{
  assert ( avg3 ( 1, 2, 3 ) == 2 );
  assert ( avg3 ( -100, 100, 30 ) == 10 );
  assert ( avg3 ( 1, 2, 2 ) == 1 );
  assert ( avg3 ( -1, -2, -2 ) == -1 );
  assert ( avg3 ( LLONG_MAX, LLONG_MAX, LLONG_MAX ) == LLONG_MAX );
  return 0;
}
#endif /* __PROGTEST__ */

