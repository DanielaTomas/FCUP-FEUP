#include <stdio.h>

int main () {
 int n,i,rebucados,pessoas,resto,quociente;
 char letra1[30],letra2[30];

 scanf("%d",&n);

 for(i=0; i<n; i++) {
   scanf("%d %d",&rebucados,&pessoas);
   scanf("%s %s",&letra1[i],&letra2[i+1]);
   if(letra1[i]=='R' && letra2[i+1]=='Q') {
    resto=(rebucados%pessoas);
    quociente=(rebucados/pessoas);
    printf("R: %d Q: %d\n",resto,quociente);
   }
   else if(letra1[i]=='Q' && letra2[i+1]=='R') {
    resto=(rebucados%pessoas);
    quociente=(rebucados/pessoas);
    printf("Q: %d R: %d\n",quociente,resto);
   }
  }



  return 0;
}
