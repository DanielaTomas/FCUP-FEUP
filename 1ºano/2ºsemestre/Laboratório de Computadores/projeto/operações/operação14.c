#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 6

typedef struct PIXEL {
    int r, g, b;
} PIXEL;

typedef struct IMAGEM {
    int largura;
    int altura;
    int maxcor;
    char magicnumber[3];
    PIXEL **pixel;
} IMAGEM;

void search(IMAGEM* imagem1, IMAGEM* imagem2, char* argv[]) {
    // ler pixeis
    int delta = atoi(argv[1]);
    int y = 0, aux = 0,primeira = 0,segunda = 0;
    for(int i = 0; i < imagem2->altura; i++) {
      int x = 0;
      for(int j = 0; j < imagem2->largura; j++) {
        if(aux != 2 && (imagem1->pixel[y][x].r - delta) == (imagem2->pixel[i][j].r + delta) && (imagem1->pixel[y][x].g - delta) == (imagem2->pixel[i][j].g + delta) && (imagem1->pixel[y][x].b - delta) == (imagem2->pixel[i][j].b + delta)) {
         aux = 2;
         primeira = y;
         segunda = x;
         x++;
        }
        else if(aux == 2){
         aux = 1;
         x++;
        }
      }
      if(aux != 0) {
       y++;
       aux = 0;
      }
    }
    printf("(%d,%d)\n", primeira,segunda);
}
IMAGEM* read(IMAGEM* imagem, FILE* f) {
    char magicnumber[MAX];
    int largura,altura,maxcor;
    // ler magicnumber
    fgets(magicnumber,MAX,f);
    if(strcmp(magicnumber,"P3\n") != 0) {
      fprintf(stderr,"Formato inválido!!\n");
      exit(1);
    }
    imagem->magicnumber[0] = magicnumber[0];
    imagem->magicnumber[1] = magicnumber[1];
    //ler largura e altura
    fscanf(f,"%d %d\n",&largura,&altura);
    imagem->largura = largura;
    imagem->altura = altura;
    //ler maxcor
    fscanf(f,"%d\n",&maxcor);
    imagem->maxcor = maxcor;
    //printf("Debugging: %s\nDebugging: %d %d\nDebugging: %d\n",imagem->magicnumber,(imagem->largura),(imagem->altura),(imagem->maxcor));
    //alocar memória
    imagem->pixel = (PIXEL **) malloc(largura * altura * sizeof(PIXEL));
    for(int i = 0; i < altura; i++) {
      imagem->pixel[i] = (PIXEL *)malloc(largura * sizeof(PIXEL));
    }
    //ler pixeis
    for(int i = 0; i < altura; i++) {
      for(int j = 0; j < largura; j++) {
        fscanf(f,"%d",&imagem->pixel[i][j].r);
        fscanf(f,"%d",&imagem->pixel[i][j].g);
        fscanf(f,"%d",&imagem->pixel[i][j].b);
        //printf("Debugging: %d %d %d\n",imagem->pixel[i][j].r,imagem->pixel[i][j].g,imagem->pixel[i][j].b);
      }
     }
  return imagem;
}
int main(int argc, char* argv[]) { //função principal
    FILE* f1;
    FILE* f2;
    IMAGEM *imagem1 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem original1
    IMAGEM *imagem2 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem original2
    if(argc > 4){
      f1 = fopen(argv[2],"r"); //abrir ficheiro f1
      if(f1 == NULL) {
       fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
       exit(1);
      }
      f2 = fopen(argv[3],"r");
      if(f2 == NULL) {
       fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
       exit(1);
      }
    }
    else if(argc > 3) {
      f1 = fopen(argv[2],"r"); //abrir ficheiro f1
      if(f1 == NULL) {
        fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
        exit(1);
      }
      f2 = fopen(argv[3],"r"); //abrir ficheiro f2
      if(f2 == NULL) {
        fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
        exit(1);
      }
    }
    else if(argc == 3) {
      f1 = fopen(argv[2],"r"); //abrir ficheiro f1
      if(f1 == NULL) {
        fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
        exit(1);
      }
      f2 = stdin; //abrir ficheiro f2
      if(f2 == NULL) {
        fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
        exit(1);
      }
    }
    else{
      fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
      exit(1);
    }
    read(imagem1,f1); //ler imagem1
    read(imagem2,f2); //ler imagem2
    search(imagem1,imagem2,argv);
    //fechar ficheiros
    fclose(f1);
    fclose(f2);
    //libertar memória
    free(imagem1->pixel);
    free(imagem2->pixel);
    free(imagem1);
    free(imagem2);
    return 0;
}
