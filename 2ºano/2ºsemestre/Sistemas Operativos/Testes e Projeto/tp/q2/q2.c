#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

void addmx(FILE *f1, FILE *f2){
    int l1, c1, l2, c2;
    fscanf(f1, "%dx%d\n", &l1, &c1);
    fscanf(f2, "%dx%d\n", &l2, &c2);
    if(l1 != l2 && c1 != c2){
        fprintf(stderr,"Both matrix must have the same dimensions\n");
        exit(EXIT_FAILURE);
    }
    else{
        int *sharedmemory1 = mmap(NULL, l1*c1*sizeof(int), PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, 0, 0);
        int *sharedmemory2 = mmap(NULL, l1*c1*sizeof(int), PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, 0, 0);
        int *sharedmemory3 = mmap(NULL, l1*c1*sizeof(int), PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, 0, 0);
        for(int i = 0; i < l1; i++){
            for(int j = 0; j < c1; j++){
                int aux;
                if(j != c1 - 1){
                    fscanf(f1, "%d\n", &aux);
                }
                else{
                    fscanf(f1, "%d ", &aux);
                }
                sharedmemory1[i*c1+j] = aux;
            }
        }

        for(int i = 0; i < l1; i++){
            for(int j = 0; j < c1; j++){
                int aux;
                if(j != c1 - 1){
                    fscanf(f2, "%d\n", &aux);
                }
                else{
                    fscanf(f2, "%d ", &aux);
                }
                sharedmemory2[i*c1+j] = aux;
            }
        }

        int status = 0;
        for(int i = 0; i < c1; i++){
            if(fork() == 0){
                for(int j = 0; j < l1; j++){
                    sharedmemory3[j*c1+i] = sharedmemory1[j*c1+i] + sharedmemory2[j*c1+i];
                }
                exit(0);
            } 
        }

        
        while (wait(&status) > 0);
        printf("%dx%d\n", l1, c1);
        for(int i = 0; i < l1; i++){
            for(int j = 0; j < c1; j++){
                if(j == c1 -1){
                    printf("%d\n", sharedmemory3[i*c1+j]);
                }
                else{
                    printf("%d ", sharedmemory3[i*c1+j]);
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    
    if(argc < 3) {
         fprintf(stderr,"usage: addmx file1 file2\n");
         exit(EXIT_FAILURE);
    }

    FILE *f1, *f2;
    f1 = fopen(argv[1],"r");
    f2 = fopen(argv[2],"r");
    
    if(f1 == NULL || f2 == NULL){
         fprintf(stderr,"Could not open one or more files or at least one of them does not exist\n");
         exit(EXIT_FAILURE);
    }
    else {
        addmx(f1, f2);
    }

    fclose(f1);
    fclose(f2);
    exit(EXIT_SUCCESS);
}