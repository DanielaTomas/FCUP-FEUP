#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

int file_exists(char *filename) {
  struct stat buffer;
  return (stat(filename,&buffer) == 0) ? 1 : 0;
}

int main(int argc, char* argv[]) {
  
   if (file_exists(argv[1]) == 1) {
      utime(argv[1],NULL);
   }
   else {
      FILE* f = fopen(argv[1],"w");
      mode_t newperms = (mode_t)0;
      newperms |= S_IRUSR | S_IWUSR;
      newperms |= S_IRGRP;
      newperms |= S_IROTH;
      fclose(f);
   }
q return EXIT_SUCCESS;
}
