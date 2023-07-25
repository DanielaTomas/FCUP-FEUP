#include <stdio.h>
#include <string.h>
#define MAXNOME 100
#define MAX 30
#define MAXDISC 20
#define MAXALUNOS 100

  typedef struct aluno {
    char nome[MAXNOME], codigo[MAX];
    int disc[MAX], nd;
  } ALUNO;

  typedef struct disciplina {
    char nome[MAXNOME];
    int ano;
  } DISCIPLINA;

 void procura(char palavranome[], ALUNO Alunos[], int NAlunos) {
  int i,comp;
  scanf("%[^\n]s",palavranome);
  comp=strlen(palavranome);
  printf("Alunos cujo nome inclui %s\n\n",palavranome);
  for(i=0; i<NAlunos; i++) {
   if(strncmp(Alunos[i].nome,palavranome,comp)==0) {
     printf("%s %s\n",Alunos[i].codigo,Alunos[i].nome);
   }
  }
 }
int main () {
  char palavranome[MAXNOME];
  int NDisc = 9;
  DISCIPLINA Disc[MAXDISC] = {
        {"Programacao Imperativa",1},
        {"Calculo Infinitesimal I",1},
        {"Programacao Estruturada",1},
        {"Topologia",4},
        {"Geometria Computacional",4},
        {"Probabilidades e Estatistica",2},
        {"Teoria de Numeros",3},
        {"Analise Infinitesimal",3},
        {"Logica",3}
       };

  int NAlunos = 6;
  ALUNO Alunos[MAXALUNOS] = {
      {"Mariana Matias","2001018003", {2,1,9,5,3,7}, 6},
      {"Anabela Moreira", "2000020004",{6,2,3,7,8,9}, 6},
      {"Sonia Silva", "2000020005",{5,6,1,8,9},5},
      {"Joao Maria Peixoto", "2000018001",{3,4,1,5}, 4},
      {"Joao Mario Pereira","2004010005",{8,1,2,3,4,5,6},7},
      {"Maria Reis", "2000020050",{5,6,1,7,3,9},6}
    };

  procura(palavranome,Alunos, NAlunos);

  return 0;
}
