#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 9999

void erase(char str[100]){
    for(int i = 0; i < 100; i++){
        str[i] = '\0';
    }
}

void changewords(char bufferchild[BUFSIZE], char bufferfinal[BUFSIZE], char cypherwords[100][100]){
    int count = 0, count2 = 0, flag = 0, turn = 0;
        char c2 = 'a', bufferaux[100] = "", bufferaux2[100] = "";
        for(size_t i = 0; i < strlen(bufferchild); i++){
            turn = 1;
            c2 = bufferchild[i];
            if((c2 >= 'A' && c2 <= 'Z') || (c2 >= 'a' && c2 <= 'z')){
                strcat(bufferfinal, bufferaux2);
                count2 = 0;
                erase(bufferaux2);
                bufferaux[count] = c2;
                count++;
            }
            else{
                turn = 2;
                for(int j = 0; j < 100; j++){
                    if(strcmp(bufferaux, cypherwords[j]) == 0){
                        flag = 1;
                        if(j % 2 == 0){
                            strcat(bufferfinal, cypherwords[j+1]);
                        }
                        else{
                            strcat(bufferfinal, cypherwords[j-1]);
                        }
                    }
                }
                if(flag == 0){
                    strcat(bufferfinal, bufferaux);
                }
                count = 0;
                erase(bufferaux);
                flag = 0;
                bufferaux2[count2] = c2;
                count2++;
            }
        }
        if(turn == 1){
            strcat(bufferfinal, bufferaux);
        }
        else if(turn == 2){
            strcat(bufferfinal, bufferaux2);
        }
        strcat(bufferfinal, "\n");
}

void cypher(char buffer[BUFSIZE], char cypherwords[100][100]){
    int fd1[2], fd2[2];
    char bufferfinal[BUFSIZE] = "", bufferchild[BUFSIZE] = "", bufferparent[BUFSIZE] ="";
    
    if(pipe(fd1) == -1 || pipe(fd2) == -1){
        fprintf(stderr,"Could not open at least one of the pipes\n");
        exit(EXIT_FAILURE);
    }

    pid_t id = fork();
    if(id == -1){
        fprintf(stderr,"Could not create the child process\n");
        exit(EXIT_FAILURE);
    }
    else if(id > 0){
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], buffer, strlen(buffer)+1);     
        close(fd1[1]);
        int status = 0;
        while (wait(&status) > 0);
        read(fd2[0], bufferparent, BUFSIZE);
        close(fd2[0]);
        write(STDOUT_FILENO, bufferparent, strlen(bufferparent)+1);
    }
    else{
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], bufferchild, BUFSIZE);
        close(fd1[0]);
        changewords(bufferchild, bufferfinal, cypherwords);
        write(fd2[1], bufferfinal, strlen(bufferfinal)+1);
        close(fd2[1]);
    }
}

int main(){
    int count = 0;
    char c ='a', cypherwords[100][100], buffer[BUFSIZE];
    FILE *f;
    f = fopen("cypher.txt", "r");
    if(f == NULL){
         fprintf(stderr,"Could not open the file cypher.txt\n");
         exit(EXIT_FAILURE);
    }
    for(int i = 0; c != EOF; i++){
        c = fgetc(f);
        if(c == ' ' || c == '\n'){
            cypherwords[count][i] = '\0';
            count++;
            i = -1;
        }
        else if(c == EOF){
            cypherwords[count][i] = '\0';
            break;
        }
        else{
            cypherwords[count][i] = c;
        }
    }

    int bytes = read(STDIN_FILENO, buffer, BUFSIZE);
    buffer[bytes]='\0';
    cypher(buffer, cypherwords);

    exit(EXIT_SUCCESS);
}