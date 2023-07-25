
#include "funcs.h"

int hexstr_convert(const char h[]) {
  int r = 0;
  int pos = 0;
  while (h[pos] != '\0') {
    char c = h[pos];
    int v;
    if (c >= '0'      // c1
    && c <= '9') {    // c2
      v = c - '0';
    }
    else if (c >= 'A'     // c2 
          && c <= 'F') {  // c3
      v = c + 10 - 'A';
    }
    else {
      v = c + 10 - 'a';
    }
    r = r * 16 + v; 
    pos++;
  }
  return r;
}


int days_in_month(int m, int y) {
  int r;
  switch (m) {
    case FEBRUARY:
      if ( y % 4 == 0 &&
             ( y % 100 != 0 
            || y % 400 == 0)) {
        r = 29;
      } else {
        r = 28;
      }
      break;
    case JANUARY: case MARCH: case MAY: 
    case JULY: case AUGUST: case OCTOBER: 
    case DECEMBER:
      r = 31;
      break;
    default:
      r = 30; 
      break;
  }
  return r;
}

double factorial(int j) {
    double f = 1;
    while(j > 0) {
        f *= j--;
    }
    return f;
}

double exp_taylor(double x, int n) {
    double e = 1.0;
    if(n >= 1) e += x;
    if(n >= 2) {
      double p = x;
      for (int j = 2; j <= n; j++) {
        p *= x;
        e += (p / factorial(j));
      }
    }
    return e;
}

