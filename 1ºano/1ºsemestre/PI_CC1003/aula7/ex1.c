#include <stdio.h>
#include <string.h>
#define MAXCHAR 30
int divisivel_pot10(char x[], int p);
int par(char x[]);
int divisivel_9(char x[]);

int main () {
 int p;
 char seq[MAXCHAR];

 scanf("%s %d",seq,&p);

 if(divisivel_pot10(seq,p)==1) {
  printf("%s é divisível por 10^(%d)\n",seq,p);
 }
 else {
  printf("%s não é divisível por 10^(%d)\n",seq,p);
 }
 if(par(seq)) {
  printf("%s é par\n",seq);
 }
 else {
   printf("%s não é par\n",seq);
 }
 if(divisivel_9(seq)) {
  printf("é divisivel por 9\n");
 }
 else {
  printf("não é divisivel por 9\n");
 }

  return 0;
}

//a)
int divisivel_pot10(char x[], int p) {
  int n=strlen(x);

  if(x[0]=='0') return 1;

  if(n<=p) return 0;

  for(int i=n-1; i>=n-p; i--) {
   if(x[i]!='0') return 0;
  }
  return 1;
}

//b)
int par(char x[]) {
 int n=strlen(x);
 int c=x[n-1];

 if(c=='0' || c=='2' || c=='4' || c=='6' || c=='8') return 1;

 return 0;
}

//c)
int divisivel_9(char x[]) {
 int soma=0;

 for(int i=0; x[i]!='\0'; i++) {
  soma+=(x[i]-'0');
 }
 if(soma%9==0) return 1;

 return 0;
}
