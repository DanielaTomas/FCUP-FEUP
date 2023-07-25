#include <stdio.h>
#include <string.h>
#define MAX 2005
int main () {
int amplitude;
char posicao[MAX],sentido[MAX],estado[MAX];

strcpy(posicao,"S");
strcpy(sentido,"CCW");

scanf("%d",&amplitude);
while(amplitude!=-1) {
 strcpy(estado,"normal");
 if((amplitude%45)==0) {
  if(amplitude>720) {
   strcpy(estado,"tonto");
   if(strcmp(sentido,"CCW")==0) {
    strcpy(sentido,"CW");
   }
   else strcpy(sentido,"CCW");
  }
  if((strcmp(posicao,"S")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"E")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"SE");
  else if((strcmp(posicao,"SE")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"NE")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"E");
  else if((strcmp(posicao,"E")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"N")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"NE");
  else if((strcmp(posicao,"NE")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"NW")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"N");
  else if((strcmp(posicao,"N")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"W")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"NW");
  else if((strcmp(posicao,"NW")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"SW")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"W");
  else if((strcmp(posicao,"W")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"S")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"SW");
  else if((strcmp(posicao,"SW")==0 && strcmp(sentido,"CCW")==0) || (strcmp(posicao,"SE")==0 && strcmp(sentido,"CW")==0)) strcpy(posicao,"S");
 }
 scanf("%d",&amplitude);
}
printf("(%s, %s, %s)\n",posicao,sentido,estado);


  return 0;
}
