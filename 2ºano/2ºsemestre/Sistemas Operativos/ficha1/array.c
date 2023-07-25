#include <stdio.h>
int main() {
  int i;

  //char_array
  char msg[] = "Hello World"; //char *msg
  for (i = 0; i < sizeof(msg); i++) {
    printf("%c <--> %c\n", msg[i], *(msg + i));
  }

  //int_array
  int primes[] = {2, 3, 5, 7, 11}; //int *primes
  for (i = 0; i < sizeof(primes)/sizeof(int); i++) {
    printf("%d <--> %d\n", primes[i], *(primes + i));
  }
  return 0;
}

//cada incremento de i corresponde a 4 bytes acho
