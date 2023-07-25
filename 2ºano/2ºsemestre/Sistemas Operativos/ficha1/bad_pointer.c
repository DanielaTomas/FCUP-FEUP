#include <stdio.h>

int* get_int() {
  int i = 2;
  return &i;
}
int main() {
  int* p = get_int();
  printf("integer = %d\n", *p); //o erro ocorre aqui
  return 0;
}

//O i é uma variável local, ou seja, deixa de existir depois do retorno da função get_init
//Não é possível imprimir o valor de *p porque este aponta para uma posição de memória que não existe
//Logo, o erro ocorre no printf.

//Se i fosse uma variável global/estática já funcionaria
//Alocar memória diretamente no array também é uma opção (good_pointer.c)
