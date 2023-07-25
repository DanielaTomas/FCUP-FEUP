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

IMAGEM* rotate_vertical(IMAGEM *imagem1) {
    int h = imagem1->altura, w = imagem1->largura;
    IMAGEM *imagem2 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem rodada
    //ler imagem2
    imagem2->altura = h;
    imagem2->largura = w;
    imagem2->maxcor = imagem1->maxcor;
    imagem2->magicnumber[0] = imagem1->magicnumber[0];
    imagem2->magicnumber[1] = imagem1->magicnumber[1];
    imagem2->pixel = (PIXEL **) malloc(w * h * sizeof(PIXEL));
    for(int i = 0; i < h; i++) {
      imagem2->pixel[i] = (PIXEL *) malloc(w * sizeof(PIXEL));
    }
    //rodar imagem <--> ler pixeis imagem2
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        imagem2->pixel[h - i - 1][j].r = imagem1->pixel[i][j].r;
        imagem2->pixel[h - i - 1][j].g = imagem1->pixel[i][j].g;
        imagem2->pixel[h - i - 1][j].b = imagem1->pixel[i][j].b;
      }
    }
    return imagem2;
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
int main(int argc, char* argv[]) {
    FILE* f;
    FILE* output;
    IMAGEM *imagem1 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem original
    IMAGEM *imagem2 = (IMAGEM *) malloc(sizeof(IMAGEM)); //alocar memoria imagem rodada

    if(argc > 2) {
     f = fopen(argv[1],"r"); //abrir ficheiro f
     if(f == NULL) {
      fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[1]); //erro ao abrir
      exit(1);
     }
     output = fopen(argv[2],"w"); //abrir ficheiro output
     if(output == NULL) {
      fprintf(stderr,"%s ficheiro falhou a abrir ou não existe!!\n",argv[2]); //erro ao abrir
      exit(1);
     }
    }
    else if(argc > 1) {
      f = fopen(argv[1],"r"); //abrir ficheiro f
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
    else if(argc == 1){
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
    imagem2 = rotate_vertical(imagem1); //rodar vertical -> operação 2
    write(imagem2,output); //escrever no ficheiro output

    //fechar ficheiros
    fclose(f);
    fclose(output);
    //libertar memória
    free(imagem1->pixel);
    free(imagem2->pixel);
    free(imagem1);
    free(imagem2);
    return 0;
}
