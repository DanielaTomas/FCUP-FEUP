#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* argv[]) {
  struct stat info;
  if (argc < 2) {
    fprintf(stderr, "usage: %s file\n", argv[0]);
    return EXIT_FAILURE;
  }
  for(int i = 1; i < argc; i++) {
    if (lstat(argv[i], &info) == -1) {
      fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
      return EXIT_FAILURE;
    }
    printf("%s size: %d bytes, disk_blocks: %d, time of last data modification: %s, user: %d\n",
    argv[i], (int)info.st_size, (int)info.st_blocks, ctime(&info.st_mtime), info.st_uid);
  }
  return EXIT_SUCCESS;
}
