#include <stdio.h>
int main () {

int pontos,equipa,adversario,jornadas;

scanf("%d %d %d",&equipa,&adversario,&jornadas);

pontos=3*jornadas;

  if (equipa>adversario && (adversario+pontos)<equipa) {
   printf(":-D\n"); }
  else if (equipa>adversario && (adversario+pontos)==equipa) {
   printf(":-D\n"); }
  else if (equipa>adversario && (adversario+pontos)>equipa) {
   printf(":-)\n"); }
  else if (equipa<adversario && (equipa+pontos)>adversario) {
   printf(":-|\n"); }
  else if (equipa<adversario && (equipa+pontos)<adversario) {
   printf(":-(\n"); }
  else if (equipa<adversario && (equipa+pontos)==adversario) {
   printf(":-(\n"); }
 
  return 0;
}
