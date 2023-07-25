#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024
int next_block_size(int count, int buffer_size) {
  return (count >= buffer_size)? buffer_size: count % buffer_size;
}
int main(int argc, char* argv[]) {
/* check if exactly one argument is present */
  if (argc < 2) {
    printf("usage: cat filename\n");
    return EXIT_FAILURE;
  }
/* check if file can be opened and is readable */
  for(int i = 1; i < argc; i++) {
    int fd = open(argv[i], O_RDONLY);
    if (fd == -1) {
      printf("error: cannot open %s\n", argv[i]);
      return EXIT_FAILURE;
    }
  /* get the file size */
    struct stat info;
    int ret = lstat(argv[i], &info);
    if (ret == -1) {
      printf("error: cannot stat %s\n", argv[i]);
      return EXIT_FAILURE;
    }
  /* print the contents in blocks */
    int count = info.st_size;
    char buffer[BUFFER_SIZE];
    while (count != 0) {
      int bytesin = read(fd, buffer, next_block_size(count, BUFFER_SIZE));
      count -= bytesin;
      write(STDOUT_FILENO, buffer, bytesin);
    }
  /* close file */
    close(fd);
  }
  return EXIT_SUCCESS;
}
