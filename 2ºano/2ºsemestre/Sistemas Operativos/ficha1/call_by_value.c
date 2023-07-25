#include <stdio.h>

//as variáveis n1 e n2 são locais à função, por isso, os valores não são preservados depois do retorno da função e a troca não tem efeito
void swap(int n1, int n2) {
int temp = n1;
  n1 = n2;
  n2 = temp;
}
int main() {
  int n1 = 1;
  int n2 = 2;
  swap(n1, n2);
  printf("n1: %d n2: %d\n", n1, n2);
  return 0;
}

/*

                  Memória
------------------------------------------------
   Endereço    |  Variável |      Conteúdo
------------------------------------------------
0x7fffbb41abf8 |     n2    |         1
------------------------------------------------
0x7fffbb41abfc |     n1    |         2
------------------------------------------------
0x7fffbb41ac04 |   temp    |         2
------------------------------------------------
0x7fffe6a9ef70 |     n1    |         1
------------------------------------------------
0x7fffe6a9ef74 |     n2    |         2
------------------------------------------------

*/
