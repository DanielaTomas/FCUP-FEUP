#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {
  pid_t pid;
  /* fork a child process */
  if ((pid = fork()) == -1) {
    perror("fork");
    return EXIT_FAILURE;
  }
  else if (pid == 0) {
    /* child process */
    if (execlp(argv[1],argv[1],NULL) == -1) {
      perror("execlp");
      return EXIT_FAILURE;
    }
  }
  else {
    /* parent process */
    if (waitpid(pid, NULL, 0) == -1) {
      perror("waitpid");
      return EXIT_FAILURE;
    }
    printf("child exited\n");
  }
  return EXIT_SUCCESS;
}
