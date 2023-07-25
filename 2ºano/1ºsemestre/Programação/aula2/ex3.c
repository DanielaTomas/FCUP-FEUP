#include <stdio.h>

int hexstr_convert(const char h[]) {
  int r = 0;
  int pos = 0;
  while(h[pos] != '\0') {
    int v;
    if(h[pos] >= '0' && h[pos] <= '9') {
      v = h[pos] - '0';
    }
    else if(h[pos] >= 'A' && h[pos] <= 'F') {
      v = h[pos] - 'A' + 10;
    }
    else {
      v = h[pos] - 'a' + 10;
    }
    r = r*16 + v;
    pos++;
  }
  return r;
}

void test(const char h[]) {
  int v = hexstr_convert(h);
  printf("\"%s\" -> %d (%X)\n", h, v, v);
}

int main(void) {
  test("A");
  test("0a");
  test("a0");
  test("18");
  test("1f");
  test("fF");
  test("ffff");
  test("AbCdEf");
  test("7fffffff");
  return 0;
}
