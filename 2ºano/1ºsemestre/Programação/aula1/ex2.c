#include <stdio.h>

int main() {
/* (a)
  int a = 3;
  int b = 2;
  int c = (a + b) * b;
  int d = a + b * b;
  int e = c / d + c % d;
*/

/* (b)
  int a = 1;
  int b = a++;
  int c = ++a;
  int d = --a;
  int e = a--;
*/

/* (c)
  int a = 10, b = -20, c = 0x1E, d = -40, e = 50;
  b += a;
  c -= a;
  d *= a;
  e /= a;
*/

/* (d)
  int a = 1;
  int b = a % 2 == 1;
  int c = a > 0 && b < 0;
  int d = c == 1 || b > 0;
  int e = !d ? 0 : 1;
*/

  printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);

  return 0;
}
/*
2.
(a) a=3 b=2 c=10 d=7 e=4
(b) a=1 b=1 c=3 d=2 e=2
(c) a=10 b=-10 c=20 d=-400 e=5
(d) a=1 b=1 c=0 d=1 e=1

*/
