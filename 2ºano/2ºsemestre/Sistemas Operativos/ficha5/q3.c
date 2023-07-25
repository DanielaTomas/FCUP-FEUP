#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {
  pid_t pid;
  int value = 0;
  if ((pid = fork()) == -1) {
    perror("fork");
    return EXIT_FAILURE;
  }
  else if (pid == 0) {
    /* child process */
    value = 1;
    printf("CHILD: value = %d, addr = %p\n", value, &value);
    return EXIT_SUCCESS;
  }
  else {
    /* parent process */
    if (waitpid(pid, NULL, 0) == -1) {
      perror("wait");
      return EXIT_FAILURE;
    }
    printf("PARENT: value = %d, addr = %p\n", value, &value);
    return EXIT_SUCCESS;
  }
}
