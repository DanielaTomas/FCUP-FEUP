#include <stdio.h>
#include <math.h>

int solve_eq(int a, int b, int c, double* x1, double* x2) {
  int delta = b * b - 4 * a * c;
  int sols;
  if(a == 0) sols = -1;
  else {
   if(delta < 0) sols = 0;
   else if(delta == 0) {
     sols = 1;
     *x1 = -b/(2*a);
   }
   else {
     sols = 2;
     *x1 = (-b - sqrt(delta))/(2*a);
     *x2 = (-b + sqrt(delta))/(2*a);
   }
  }
  return sols;
}

int main(void) {
  int a, b, c, sols;
  double x1, x2;

  printf("Enter values for a, b, and c: ");
  scanf("%d %d %d", &a, &b, &c);

  sols = solve_eq(a, b, c, &x1, &x2);
  switch(sols) {
    case 0: printf("No solutions!\n");
    break;
    case 1: printf("One solution: %f\n", x1);
    break;
    case 2: printf("Two solutions: %f and %f\n", x1, x2);
    break;
    default: printf("Error: a is 0!\n");
    break;
  }

  return 0;
}
