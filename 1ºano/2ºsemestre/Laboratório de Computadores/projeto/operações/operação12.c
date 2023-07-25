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

IMAGEM* sobrepor(IMAGEM* imagem1, IMAGEM* imagem2, char* argv[]) {
    IMAGEM *imagem3 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem rodada
    //ler imagem2
    imagem3->largura = imagem2->largura;
    imagem3->altura = imagem2->altura;
    imagem3->maxcor = imagem1->maxcor;
    imagem3->magicnumber[0] = imagem1->magicnumber[0];
    imagem3->magicnumber[1] = imagem1->magicnumber[1];
    imagem3->pixel = (PIXEL **) malloc(imagem3->largura * imagem3->altura * sizeof(PIXEL));
    for(int i = 0; i < imagem3->altura; i++) {
      imagem3->pixel[i] = (PIXEL *) malloc(imagem3->largura * sizeof(PIXEL));
    }
    // ler pixeis
    int y = 0, aux = 0;
    for(int i = 0; i < imagem3->altura; i++) {
      int x = 0;
      for(int j = 0; j < imagem3->largura; j++) {
        if((i >= atoi(argv[2]) && j >= atoi(argv[1])) && (y < imagem1->altura) && (x < imagem1->largura)) {
         aux = 1;
         imagem3->pixel[i][j].r = imagem1->pixel[y][x].r;
         imagem3->pixel[i][j].g = imagem1->pixel[y][x].g;
         imagem3->pixel[i][j].b = imagem1->pixel[y][x].b;
         x++;
        }
        else {
         imagem3->pixel[i][j].r = imagem2->pixel[i][j].r;
         imagem3->pixel[i][j].g = imagem2->pixel[i][j].g;
         imagem3->pixel[i][j].b = imagem2->pixel[i][j].b;
        }
      }
      if(aux != 0) {
       y++;
       aux = 0;
      }
    }
    return imagem3;
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
void write(IMAGEM* imagem, FILE* output) {
 fprintf(output,"%s\n%d %d\n%d\n",imagem->magicnumber,imagem->largura,imagem->altura,imagem->maxcor);
    for(int i = 0; i < imagem->altura; i++) {
      for(int j = 0; j < imagem->largura; j++) {
        fprintf(output,"%d ",imagem->pixel[i][j].r);
        fprintf(output,"%d ",imagem->pixel[i][j].g);
        fprintf(output,"%d\n",imagem->pixel[i][j].b);
      }
    }
}
int main(int argc, char* argv[]) { //função principal
    FILE* f1;
    FILE* f2;
    FILE* output;
    IMAGEM *imagem1 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem original1
    IMAGEM *imagem2 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem original2
    IMAGEM *imagem3 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem rodada
    if(argc > 5){
      f1 = fopen(argv[3],"r"); //abrir ficheiro f1
      if(f1 == NULL) {
       fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[1]);
       exit(1);
      }
      f2 = fopen(argv[4],"r");
      if(f2 == NULL) {
       fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[2]);
       exit(1);
      }
      output = fopen(argv[5],"w"); //abrir output
      if(output == NULL) {
        fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[3]);
        exit(1);
      }
    }
    else if(argc > 4) {
      f1 = fopen(argv[3],"r"); //abrir ficheiro f1
      if(f1 == NULL) {
        fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[1]);
        exit(1);
      }
      f2 = fopen(argv[4],"r"); //abrir ficheiro f2
      if(f2 == NULL) {
        fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[2]);
        exit(1);
      }
      output = stdout; //abrir output
      if(output == NULL) {
        fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n");
        exit(1);
      }
    }
    else if(argc == 4) {
      f1 = fopen(argv[3],"r"); //abrir ficheiro f1
      if(f1 == NULL) {
        fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[1]);
        exit(1);
      }
      f2 = stdin; //abrir ficheiro f2
      if(f2 == NULL) {
        fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[2]);
        exit(1);
      }
      output = stdout; //abrir output
      if(output == NULL) {
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
    imagem3 = sobrepor(imagem1,imagem2,argv); //sobrepor imagem -> operação 12
    write(imagem3,output); //escrever no ficheiro output

    //fechar ficheiros
    fclose(f1);
    fclose(f2);
    fclose(output);
    //libertar memória
    free(imagem1->pixel);
    free(imagem2->pixel);
    free(imagem3->pixel);
    free(imagem1);
    free(imagem2);
    free(imagem3);
    return 0;
}
