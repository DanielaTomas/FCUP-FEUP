#include <stdio.h>
#include <string.h>
#define MAX 20
void procurar_palavra(int m, int n, int k, char sopa[][MAX], char letra[], int resultado[]) {
 int i,j,l=0,p,h,comp;
 scanf(" %s",letra);
 comp=strlen(letra);
//direita para esquerda
 for(i=0; i<m; i++) {
  for(j=0; j<n; j++) {
   if(sopa[i][j]==letra[0]) {
    resultado[0]=i+1;
    resultado[1]=j+1;
    p=j-1;
    for(l=1; l<comp; l++) {
     if(sopa[i][p]==letra[l]) {
      resultado[2]=i+1;
      resultado[3]=p+1;
      p--;
     }
     else {
      l=comp;
      resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
     }
    }
   }
   if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
    i=m;
    j=n;
     printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
     resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
   }
  }
 }
//esquerda para a direita
 for(i=0; i<m; i++) {
  for(j=0; j<n; j++) {
   if(sopa[i][j]==letra[0]) {
    resultado[0]=i+1;
    resultado[1]=j+1;
    p=j+1;
    for(l=1; l<comp; l++) {
     if(sopa[i][p]==letra[l]) {
      resultado[2]=i+1;
      resultado[3]=p+1;
      p++;
     }
     else {
      l=comp;
      resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
     }
    }
   }
   if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
    i=m;
    j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
   }
  }
 }
//baixo para cima
 for(i=0; i<m; i++) {
  for(j=0; j<n; j++) {
   if(sopa[i][j]==letra[0]) {
    resultado[0]=i+1;
    resultado[1]=j+1;
    p=i-1;
    for(l=1; l<comp; l++) {
     if(sopa[p][j]==letra[l]) {
      resultado[2]=p+1;
      resultado[3]=j+1;
      p--;
     }
     else {
      l=comp;
      resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
     }
    }
   }
   if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
    i=m;
    j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
   }
  }
 }
//cima para baixo
 for(i=0; i<m; i++) {
  for(j=0; j<n; j++) {
   if(sopa[i][j]==letra[0]) {
    resultado[0]=i+1;
    resultado[1]=j+1;
    p=i+1;
    for(l=1; l<comp; l++) {
     if(sopa[p][j]==letra[l]) {
      resultado[2]=p+1;
      resultado[3]=j+1;
      p++;
     }
     else {
      l=comp;
      resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
     }
    }
   }
   if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
    i=m;
    j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
   }
  }
 }
//diagonal (NO-SE)
for(i=0; i<m; i++) {
 for(j=0; j<n; j++) {
  if(sopa[i][j]==letra[0]) {
   resultado[0]=i+1;
   resultado[1]=j+1;
   p=i+1;
   h=j+1;
   for(l=1; l<comp; l++) {
    if(sopa[p][h]==letra[l]) {
     resultado[2]=p+1;
     resultado[3]=h+1;
     p++;
     h++;
    }
    else {
     l=comp;
     resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
    }
   }
  }
  if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
   i=m;
   j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
  }
 }
}
//diagonal (SE-NO)
for(i=0; i<m; i++) {
 for(j=0; j<n; j++) {
  if(sopa[i][j]==letra[0]) {
   resultado[0]=i+1;
   resultado[1]=j+1;
   p=i-1;
   h=j-1;
   for(l=1; l<comp; l++) {
    if(sopa[p][h]==letra[l]) {
     resultado[2]=p+1;
     resultado[3]=h+1;
     p--;
     h--;
    }
    else {
     l=comp;
     resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
    }
   }
  }
  if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
   i=m;
   j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
  }
 }
}
//diagonal (NE-SO)
for(i=0; i<m; i++) {
 for(j=0; j<n; j++) {
  if(sopa[i][j]==letra[0]) {
   resultado[0]=i+1;
   resultado[1]=j+1;
   p=i+1;
   h=j-1;
   for(l=1; l<comp; l++) {
    if(sopa[p][h]==letra[l]) {
     resultado[2]=p+1;
     resultado[3]=h+1;
     p++;
     h--;
    }
    else {
     l=comp;
     resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
    }
   }
  }
  if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
   i=m;
   j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
  }
 }
}
//diagonal (SO-NE)
for(i=0; i<m; i++) {
 for(j=0; j<n; j++) {
  if(sopa[i][j]==letra[0]) {
   resultado[0]=i+1;
   resultado[1]=j+1;
   p=i-1;
   h=j+1;
   for(l=1; l<comp; l++) {
    if(sopa[p][h]==letra[l]) {
     resultado[2]=p+1;
     resultado[3]=h+1;
     p--;
     h++;
    }
    else {
     l=comp;
     resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
    }
   }
  }
  if(resultado[0]!=0 && resultado[1]!=0 && resultado[2]!=0 && resultado[3]!=0) {
   i=m;
   j=n;
    printf("%d %d %d %d\n",resultado[0],resultado[1],resultado[2],resultado[3]);
    resultado[0]=0; resultado[1]=0; resultado[2]=0; resultado[3]=0;
  }
 }
}
}
int main () {
 int i=0,j=0,n,m,k;
 int resultado[4]={ 0 };
 char letra[MAX];
 char sopa[MAX][MAX];
 scanf("%d %d ",&m,&n); //ler matriz
 for(i=0; i<m; i++) {
  for(j=0; j<n; j++) {
   scanf(" %c",&letra[j]);
   sopa[i][j]=letra[j];
  }
 }
 scanf("%d",&k); //ler e procurar palavras
 for(i=0; i<k; i++) {
   procurar_palavra(m,n,k,sopa,letra,resultado);
 }
  return 0;
}
