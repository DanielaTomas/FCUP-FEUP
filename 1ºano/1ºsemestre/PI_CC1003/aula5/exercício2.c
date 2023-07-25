
#include <stdio.h>

float grau_rad(float x) {
x=(x*3.14)/180;
return x;
}

int main() {
float a;
scanf("%f",&a);
printf("%f\n",grau_rad(a));
}
