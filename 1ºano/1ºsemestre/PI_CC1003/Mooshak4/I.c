#include <stdio.h>
#define MAX 55
int main () {
int cupao,n,i,total=0,preco;
char descricao[MAX];

scanf("%d %d",&cupao,&n);

for(i=0; i<n; i++) {
 scanf("%d",&preco);
 scanf(" %[^\n]s",descricao);
 if(preco<=cupao) {
  total+=preco;
  cupao-=preco;
  printf("%s\n",descricao);
 }
}

printf("%d %d\n",total,cupao);

 return 0;
}
