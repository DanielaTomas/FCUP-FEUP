/*------------------------------------------------------------------------------*\
|         CC1003  - Aplicações de matrizes para estudo de relações binárias      |
|                                                                                |
|         AP Tomás,  DCC-FCUP,  2020/2021                                        |
\*------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//===========  COMPILAÇÃO CONDICIONADA ================================
// comentar uma e uma só das duas definições seguintes e recompilar o programa
#define LERMAT   // para ler conjunto de pares da relação e obter matriz
//#define CRIAMAT   // cria aleatoriamente matriz da relação

// comentar a linha seguinte se não quiser ver um contra-exemplo e
// recompilar o programa
#define EXPLICA
//=====================================================================


#define NMAX 20
#define FALSE 0
#define TRUE 1

// escrever matriz m x n
void escrMatriz(int mat[][NMAX],int m, int n);
// ler matriz m x n
void lerMatriz(int mat[][NMAX],int m, int n);
// atribuir 0 a todos os elementos de uma matriz m x n
void matrizNula(int mat[][NMAX],int m, int n);
// verificar as propriedades de uma relação definida num conjunto
int simetrica(int mat[][NMAX],int n);
int antissimetrica(int mat[][NMAX],int n);
int reflexiva(int mat[][NMAX],int n);
int transitiva(int mat[][NMAX],int n);
#ifdef CRIAMAT
int criaRelacao(int mat[][NMAX],int nmax);
#endif
#ifdef LERMAT
int lerRelacao(int mat[][NMAX]);
#endif

void copiar(int orig[][NMAX],int dest[][NMAX],int n);

// união e interseção de relações definidas em A
void uniao(int r[][NMAX],int s[][NMAX],int matuniao[][NMAX],int n);
void intersecao(int r[][NMAX],int s[][NMAX],int matinters[][NMAX],int n);

void escrRel(int mat[][NMAX],int n);
// escrever os pares que estão na relação definida por mat se A = {1,2,...,n}


//============  Propriedades ========================================
int simetrica(int mat[][NMAX],int n){
  int i,j;
  for (i=0;i<n;i++)
    for(j=0;j<i;j++)
      if (mat[i][j] != mat[j][i]) {
#ifdef EXPLICA
	if (mat[i][j] == TRUE)
	  printf("(%d,%d) pertence a R e (%d,%d) nao pertence a R\n",
		 i+1,j+1,j+1,i+1);
	else
	  printf("(%d,%d) pertence a R e (%d,%d) nao pertence a R\n",
		 j+1,i+1,i+1,j+1);
#endif
	return FALSE;
      }
  return TRUE;
}


int antissimetrica(int mat[][NMAX],int n){
  int i,j;
  for (i=0;i<n;i++)
    for(j=0;j<i;j++)
      if (mat[i][j]==TRUE && mat[j][i]==TRUE) {
#ifdef EXPLICA
	  printf("(%d,%d) e (%d,%d) pertencem a R e %d diferente de %d\n",
		 i+1,j+1,j+1,i+1,i+1,j+1);
#endif
	  return FALSE;  // notar que j<i (logo, são diferentes)
      }
  return TRUE;
}


int reflexiva(int mat[][NMAX],int n){
  int i;
  for (i=0;i<n;i++)
    if (mat[i][i]==FALSE) {
#ifdef EXPLICA
      printf("(%d,%d) nao pertence a R e %d pertence a A\n",i+1,i+1,i+1);
#endif
      return FALSE; 
    }
  return TRUE;
}

int transitiva(int mat[][NMAX],int n){
  int i,j,k;
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      for (k=0;k<n;k++)
	if (mat[i][k]==TRUE && mat[k][j]==TRUE && mat[i][j]!=TRUE) {
#ifdef EXPLICA
	  printf("(%d,%d) e (%d,%d) pertencem a R e (%d,%d) nao pertence\n",
		 i+1,k+1,k+1,j+1,i+1,j+1);
#endif
	  return FALSE;
	}
  return TRUE;
}



//=================================================================
// calcular a interseção das relações r e s definidas em A
//=================================================================
void intersecao(int r[][NMAX],int s[][NMAX],int matinters[][NMAX],int n) {
  int i, j;
  for (i=0; i < n; i++)
    for (j=0; j < n; j++)
      if (r[i][j] == TRUE && s[i][j] == TRUE) 
	matinters[i][j] = TRUE;
      else matinters[i][j] = FALSE;
}


//=================================================================
// calcular a união das relações r e s definidas em A
//=================================================================
void uniao(int r[][NMAX],int s[][NMAX],int matuniao[][NMAX],int n) {
  int i, j;
  for (i=0; i< n; i++)
    for (j=0; j< n; j++)
      if (r[i][j] == TRUE || s[i][j] == TRUE) 
	matuniao[i][j] = TRUE;
      else matuniao[i][j] = FALSE;
}


//================================================================

/*
// calcular o produto de duas matrizes de inteiros quadradas (n x n)
void produtomatrizes(int r[][NMAX],int s[][NMAX],int rs[][NMAX],int n) {
  int i, j, k, aux;
  for (i=0; i< n; i++)
    for (j=0; j< n; j++) {
      aux = 0;
      for (k=0; k < n; k++)
         aux = aux + r[i][k]*s[k][j];
      rs[i][j] = aux;
    }
}
*/


//===============================================================================
// a matriz da composta de relações é um produto mas numa algebra booleana
// aux = aux  \/   (r[i][k] /\ s[k][j]);    para   k=0,1,..., n-1 
//  (com aux = FALSE inicialmente)
//==========================================================================
void composta(int r[][NMAX],int s[][NMAX],int rs[][NMAX],int n) {
  int i, j, k, aux;

  for (i=0; i< n; i++)
    for (j=0; j< n; j++) {
      for (k=0; k < n && (r[i][k] == FALSE || s[k][j] == FALSE); k++) ;
      // o ciclo k pára também se concluirmos que rs[i][j] deve ser TRUE
      // o que acontece se r[i][k] == TRUE && s[k][j] == TRUE para algum k

      if (k < n) rs[i][j] = TRUE;  // k < n significa que parou pela segunda condição
      else rs[i][j] = FALSE;       
       
    }
}





//===================================================================
// Cálculo do fecho transitivo de R usando diretamente o facto de
//  R+  =  R  U  RR  U (RR)R  U  (RRR)R  U ..... U  R^n
//  se A tiver n elementos
//=====================================================================

void fechotransitivo(int r[][NMAX],int fecho[][NMAX],int n) {
  int aux[NMAX][NMAX], aux2[NMAX][NMAX];

  copiar(r,fecho,n);    // todos os elementos de R estão em R+
  copiar(r,aux,n);

  for (int t = 2; t <= n; t++) {
    composta(aux,r,aux2,n);      // aux2  terá  R^t
    uniao(aux2,fecho,fecho,n);
    copiar(aux2,aux,n);          // fica com aux igual a R^t  para preparar a iteração seguinte
  }
}


void fechoreflexivo(int r[][NMAX],int fecho[][NMAX],int n) {
  copiar(r,fecho,n);    // todos os elementos de R estão no fecho
  for(int i=0; i<n ; i++)
    fecho[i][i] = TRUE;
}


void fechosimetrico(int r[][NMAX],int fecho[][NMAX],int n) {
  int i, j;
  copiar(r,fecho,n);    // todos os elementos de R estão no fecho
  for(i=0; i<n ; i++)
    for(j=0; j<i ; j++) {   // garantir que fecho fica simetrica
      if (fecho[i][j] == TRUE) fecho[j][i] = TRUE;
      else if (fecho[j][i] == TRUE) fecho[i][j] = TRUE;
    }
}


//===================================================================
// Cálculo do fecho transitivo pelo Algoritmo de Warshall 
// Não foi dado na aula de 11 de Dezembro
// 

/*

void warshall(int r[][NMAX],int fechotrans[][NMAX],int n) {
  int t, i, j;
  copiar(r,fechotrans,n);
  for (t=0; t<n; t++) 
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	if (fechotrans[i][t] == TRUE && fechotrans[t][j] == TRUE)
	  fechotrans[i][j] = TRUE;
}

*/
//==================================================================


//===================================================================
void classes_de_equiv(int r[][NMAX],int n) {
  // assumindo que r é de equivalencia
  int classes[n], naux = 0, i, j, nclasses = 0;    //auxiliar

  for(int i=0; i<n; i++) classes[i] = FALSE;   // indica se já está em classe

  for(i=0; i<n && naux < n; i++) {
    if (classes[i] == FALSE) {
      nclasses++; 
      // vai escrever a classe de i de A
      printf("{%d",i+1);
      classes[i] = TRUE;
      naux++;   // quantos já estão em classes
      for(j=i+1; j < n; j++)
	if (r[i][j] == TRUE) {
	  printf(", %d",j+1);
	  classes[j] = TRUE;
	  naux++;   // quantos já estão em classes
	}
      printf("}\n");
    }
  }

  printf("\nPortanto, tem %d classe(s) de equivalencia\n",nclasses);
}



//===================================================================

int main() {
  int matrizR[NMAX][NMAX]={{FALSE}}, n;
  int equivalencia=TRUE, ordemParcial=TRUE;

#ifdef LERMAT
  n = lerRelacao(matrizR);
#else
  n = criaRelacao(matrizR,NMAX);
#endif

  // printf("%d\n",n);
  escrMatriz(matrizR,n,n);
  printf("\n");

  int relSimetrica = simetrica(matrizR,n);
  if (relSimetrica ==TRUE)
    printf("Simetrica\n\n");
  else {
    equivalencia = FALSE;
    printf("Nao Simetrica\n\n");
  }

  int relReflexiva = reflexiva(matrizR,n);
  if (relReflexiva == TRUE)
    printf("Reflexiva\n\n");
  else {
    equivalencia = ordemParcial = FALSE;
    printf("Nao reflexiva\n\n");
  }

  int relTransitiva = transitiva(matrizR,n);
  if (relTransitiva == TRUE) 
    printf("Transitiva\n\n");
  else {
    equivalencia = ordemParcial = FALSE;
    printf("Nao transitiva\n\n");
  }

  if (antissimetrica(matrizR,n)==TRUE)
    printf("Antissimetrica\n");
  else {
    ordemParcial = FALSE;
    printf("Nao antissimetrica\n");
  }

  if (ordemParcial == TRUE) printf("\nRelacao de ordem parcial\n");
  if (equivalencia == TRUE) {
    printf("\nRelacao de equivalencia\n");
    printf("As classes de equivalencia sao:\n");
    classes_de_equiv(matrizR,n);
  }


  // ============

  printf("\n====================\n\n Fechos \n==================\n");
  
  int Fecho[NMAX][NMAX];

  if (relReflexiva == TRUE) 
    printf("\nO fecho reflexivo coincide com a relacao dada\n");
  else {
    fechoreflexivo(matrizR, Fecho, n);
    printf("\n\n Fecho Reflexivo\n");
    escrMatriz(Fecho,n,n);
    printf("\n\n Pares no fecho reflexivo:\n");
    escrRel(Fecho,n);
  }

  if (relSimetrica == TRUE) 
    printf("\nO fecho simetrico coincide com a relacao dada\n");
  else {
    fechosimetrico(matrizR, Fecho, n);
    printf("\n\n Fecho simetrico\n");
    escrMatriz(Fecho,n,n);
    printf("\n\n Pares no fecho simetrico:\n");
    escrRel(Fecho,n);
  }

  if (relTransitiva == TRUE) 
    printf("\nO fecho transitivo coincide com a relacao dada\n");
  else {
    fechotransitivo(matrizR, Fecho, n);
    printf("\n\n Fecho Transitivo\n");
    escrMatriz(Fecho,n,n);
    printf("\n\n Pares no fecho transitivo:\n");
    escrRel(Fecho,n);
  }

  return 0;
}
  

#ifdef LERMAT
/*-----------------------------------------------------
  Ler n (dimensão do conjunto A) e o conjunto de pares (i,j) 
  que constituem uma relação binária dada em A={1,...,n}
  e determinar a matriz dessa relação 
  NB: mat[i-1][j-1] por TRUE sse (i,j) pertencer à relação
      usa i-1 e j-1 em vez de i de j (da definição) por 
      os indices variarem em 0..(n-1)
*/
int lerRelacao(int mat[][NMAX]) {
  int npares, i, j, p, n;
  scanf("%d %d",&n,&npares);

  // inicializar mat com todas os elementos a FALSE
  for(i=0;i<n;i++) 
    for(j=0; j<n; j++)
      mat[i][j] = FALSE;
  // ler os pares e inicializar as entradas correspondentes em mat
  for(p=0;p<npares;p++) {
    scanf("%d %d",&i,&j);
    mat[i-1][j-1] = TRUE;  
  }
  return n;
}
#endif

#ifdef CRIAMAT
//========  Criar Aleatoriamente Matriz n x n (retorna n <= nmax) ====
int criaRelacao(int mat[][NMAX],int nmax){
  int i, j, n;

  srand((unsigned int)time(NULL));

  n=1+rand()%nmax;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      mat[i][j] = rand()%2;
  //  mat[i][j] = ((rand()%2 == 0)? FALSE : TRUE);
  return n;
}
#endif


//=========== Escrever a relação ===============================
void escrRel(int mat[][NMAX],int n) {
  // supor que está definida no conjunto A = {1,2,....,n}
  int i, j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if (mat[i][j] == TRUE) 
	printf("(%d,%d)\n",i+1,j+1);
}



//============  Escrever Matriz m x n ==============================
void escrMatriz(int mat[][NMAX],int m, int n) {
  int i, j;
 
  for (i=0;i<m;i++) {
    printf("%d",mat[i][0]);  // supondo que n >= 1
    for (j=1;j<n;j++)
      printf(" %d",mat[i][j]);
    printf("\n");
  }
}

//============  Ler Matriz m x n ====================================
void lerMatriz(int mat[][NMAX],int m, int n) {
  int i, j;
 
  for (i=0;i<m;i++) 
    for (j=0;j<n;j++)
      scanf("%d",&mat[i][j]);
}

//============  Inicializar Matriz Nula m x n =======================
void matrizNula(int mat[][NMAX],int m, int n) {
  int i, j;
 
  for (i=0;i<m;i++) 
    for (j=0;j<n;j++)
      mat[i][j] = 0;
}


//===== função auxiliar 
void copiar(int orig[][NMAX],int dest[][NMAX],int n) {
  int i, j;
  for (i=0; i< n; i++)
    for (j=0; j< n; j++)
      dest[i][j] = orig[i][j];
}
