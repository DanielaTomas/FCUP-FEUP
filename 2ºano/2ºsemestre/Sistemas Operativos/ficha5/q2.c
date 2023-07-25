#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
  for (int i = 0; i < 4; i++)
   fork();

  printf("Pid: %d\n", getpid());
  //16 processos (2^4)
  return EXIT_SUCCESS;
}
