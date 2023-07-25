#include <stdio.h>
#include <string.h>
#define MAXCHAR 50

int main () {
 int i=0,k;
 char x[MAXCHAR];

 for (k=0; k<2; k++) {
  while((x[i] = getchar())!='\n') {
  i++;
  }
  x[i]='\0';
  if (strcmp(x,"aplauda suas maos")==0) {
    printf("bata palmas\n");
  }
  else if (strcmp(x,"bata palmas")==0) {
    printf("bata palmas\n");
  }
  else if (strcmp(x,"it has beaten palms")==0) {
    printf("clap your hands\n");
  }
  else if (strcmp(x,"clap your hands")==0) {
    printf("clap your hands\n");
  }
  i=0;
 }
  return 0;
}
