#include <stdio.h>
#include <math.h> //faltava a biblioteca math.h
#define START 0
#define ONE_TURN 360
double cos_table[ONE_TURN];
double sin_table[ONE_TURN];

void build_tables() {
  int i;
  for (i = START; i < ONE_TURN; i++) {
    sin_table[i] = sin(M_PI * i / 180.0);
    cos_table[i] = cos(M_PI * i / 180.0);
  }
}
double sin_degrees(int angle) {
  return sin_table[angle % ONE_TURN];
}
double cos_degrees(int angle) {
  return cos_table[angle % ONE_TURN];
}
int main() {
  build_tables();
  printf("sin(20) = %f\n", sin_degrees(20));
  printf("cos(80) = %f\n", cos_degrees(425));
  printf("tan(60) = %f\n", sin_degrees(60) / cos_degrees(60));
  return 0;
}
//gcc -Wall -o trig trig.c -lm
