#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LISTA 1000
struct pessoa{
 char* nome;
 char* telefone;
};
typedef struct pessoa PESSOA;

PESSOA lista[MAX_LISTA] = {{"rui", "226664441"},
 {"ana", "214444444"}};
int n = 2; // Número de pessoas da lista

int pesquisa(char *pal) {
  for(int i = 0; i < 2; i++) {
   if(strcmp(lista[i].nome,pal)==0) return i;
  }
  return -1;
}
int pesqui(int i, char *pal) {
  for(int k = 0; k < 2; k++) {
   if(strncmp(lista[k].nome,pal,i)==0) return k;
  }
  return -1;
}
int main () {
 char pal[MAX_LISTA];
 char c[MAX_LISTA];
 int p = pesqui(0,pal);
 //scanf("%s",pal);
 //if(pesquisa(pal) != -1) printf("existe\n");
 //else printf("nao existe\n");
 scanf(" %c",c);
 scanf(" %s",pal);
 if(*c == 'p') {
  if(p != -1) printf("%s\n",lista[p].telefone);
  else printf("não existe!\n");
 }
 else if(*c == 'i') {
   if(p != -1) {
    PESSOA *new = malloc(sizeof(struct pessoa));
    char telefone[MAX_LISTA];
    scanf(" %s",telefone);
    (*new).telefone = telefone;
    //p->a <=> (*p).a
  }
 }

 return 0;
}
