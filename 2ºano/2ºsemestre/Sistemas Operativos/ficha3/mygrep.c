#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 999

int main(int argc, char *argv[]) {;

	FILE* f = fopen(argv[2],"r");
	int size = strlen(argv[1]); //length of the given string
  char* buff = (char*) malloc(sizeof(char) * SIZE);

  for(int curLine = 0; fgets(buff,SIZE,f) != NULL; curLine++) { //buff store each line
		for(int i = 0; buff[i] != '\0'; i++) {
			int j = 0;
			while(buff[i] != '\0' && argv[1][j] != '\0' && buff[i] == argv[1][j]) { //check if buff == argv
				i++; j++;
      }
			if((buff[i] == '\0' || buff[i] == ' ' || buff[i] == '\n') && j == size) {
				printf("[%d:%d]\n",curLine+1,i-size+1);
        continue;
      }
		}
	}
  free(buff);
	fclose(f);
}
