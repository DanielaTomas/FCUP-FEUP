#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void phrases(int argc, FILE* f) {
    char c = 'a';
    int count = 1, flag = 0, space = 0;
    if(argc == 3){
        printf("[%d] ", count);
    }
    while(c != EOF){
        c = fgetc(f);
        if(c == EOF){
            break;
        }
        else if(c == '\n' || c == '\r' || c == '\v' || c == '\t' || c == '\f'){
            if(argc == 3 && space == 0){
                printf(" ");
                space = 1;
            }

        }
        else if(c == '.' || c == '!' || c == '?'){
            space = 0;
            if(argc == 3){
                printf("%c", c);
            }
            count++;
            flag = 1;
        }
        else{
            space = 0;
            if(flag == 1 && c != ' '){
                if(argc == 3){
                    printf("\n[%d] ", count);
                }
                flag = 0;
            }
            if(argc == 3){
                printf("%c", c);
            }
        }
    }
    if(argc < 3){
        printf("%d", count);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    
    if(argc < 2 || (argc == 3 && strcmp(argv[1],"-l") != 0)) {
         fprintf(stderr,"usage: phrases [-l] file\n");
         exit(EXIT_FAILURE);
    }

    FILE *f;
    f = argc == 3 ? fopen(argv[2],"r") : fopen(argv[1],"r");

    if(f == NULL){
         fprintf(stderr,"Could not open the file or the file does not exist\n");
         exit(EXIT_FAILURE);
    }
    else {
         phrases(argc,f);
    }
    fclose(f);
    exit(EXIT_SUCCESS);

}