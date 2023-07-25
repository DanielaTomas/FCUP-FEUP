/*
2.1
d); f); i)
2.2
a); c); d); e); f); i)
*/
#include <stdio.h>
int main (){
 char c,*cptr;
 int i, *iptr;
 float f, *fptr;

 c='a';
 cptr=&c;
 i=0;
 iptr=&i;
 f=0;
 fptr=&f;

 printf("tamanho de um char: %lu\n",sizeof(c));
 printf("tamanho do endereço de um char: %lu\n",sizeof(&c));
 printf("tamanho de um apontador para um char: %lu\n", sizeof(cptr));
 printf("tamanho do conteúdo apontado por um apontador para um char: %lu\n", sizeof(*cptr));
 printf("Os valores apontados pelos endereços ’%p’ e ’%p’ são ’%c’ e ’%c’\n", &c, cptr, c, *cptr);

 printf("tamanho de um int: %lu\n",sizeof(i));
 printf("tamanho do endereço de um int: %lu\n",sizeof(&i));
 printf("tamanho de um apontador para um int: %lu\n",sizeof(iptr));
 printf("tamanho do conteúdo apontado por um apontador para um int: %lu\n", sizeof(*iptr));
 printf("Os valores apontados pelos endereços ’%p’ e ’%p’ são ’%d’ e ’%d’\n", &i, iptr, i, *iptr);

 printf("tamanho de um float: %lu\n",sizeof(f));
 printf("tamanho do endereço de um float: %lu\n",sizeof(&f));
 printf("tamanho de um apontador para um float: %lu\n", sizeof(fptr));
 printf("tamanho do conteúdo apontado por um apontador para um float: %lu\n", sizeof(*fptr));
 printf("Os valores apontados pelos endereços ’%p’ e ’%p’ são ’%f’ e ’%f’\n", &f, fptr, f, *fptr);


return 0;
}
