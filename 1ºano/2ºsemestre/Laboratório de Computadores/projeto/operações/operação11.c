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

void recorte(IMAGEM* imagem1, FILE* output, char* argv[]) {
  int x1 = atoi(argv[1]),y1 = atoi(argv[2]),x2 = atoi(argv[3]),y2 = atoi(argv[4]);
    if(x2 >= imagem1->largura) {
     x2 = imagem1->largura-1;
    }
    if(y2 >= imagem1->altura){
     y2 = imagem1->altura-1;
    }
    if(x1 >= imagem1->largura) {
     x1 = 0;
    }
    if(y1 >= imagem1->altura) {
     y1 = 0;
    }
    int w = x2-x1+1, h = y2-y1+1;
    fprintf(output,"%s\n%d %d\n%d\n",imagem1->magicnumber,w,h,imagem1->maxcor);
    for(int i = y1; i <= y2; i++) {
      for(int j = x1; j <= x2; j++) {
         fprintf(output,"%d ",imagem1->pixel[i][j].r);
         fprintf(output,"%d ",imagem1->pixel[i][j].g);
         fprintf(output,"%d\n",imagem1->pixel[i][j].b);
      }
   }
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
int main(int argc, char* argv[]) {
    FILE* f;
    FILE* output;
    IMAGEM *imagem1 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem original

    if(argc == 7) {
     f = fopen(argv[5],"r"); //abrir ficheiro f
     if(f == NULL) {
      fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[1]); //erro ao abrir
      exit(1);
     }
     output = fopen(argv[6],"w"); //abrir ficheiro output
     if(output == NULL) {
      fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[2]); //erro ao abrir
      exit(1);
     }
    }
    else if(argc == 6) {
      f = fopen(argv[5],"r"); //abrir ficheiro f
      if(f == NULL) {
       fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[1]); //erro ao abrir
       exit(1);
      }
      output = stdout; //abrir ficheiro output
      if(output == NULL) {
       fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n"); //erro ao abrir
       exit(1);
      }
    }
    else if(argc == 5){
     f = stdin; //abrir ficheiro input
     if(f == NULL) {
      fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n"); //erro ao abrir
      exit(1);
     }
     output = stdout; //abrir ficheiro output
     if(output == NULL) {
      fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n"); //erro ao abrir
      exit(1);
     }
    }
    else {
     fprintf(stderr,"ficheiro falhou a abrir ou não existe!!\n"); //erro ao abrir
     exit(1);
    }
    read(imagem1,f); //ler imagem1
    recorte(imagem1,output,argv); //recortar imagem-> operação 11

    //fechar ficheiros
    fclose(f);
    fclose(output);
    //libertar memória
    free(imagem1->pixel);
    free(imagem1);
    return 0;
}
