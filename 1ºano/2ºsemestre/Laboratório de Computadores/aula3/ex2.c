#include <stdio.h>
struct Frac {
  int num;
  int sinal;
  int den;
  int erro;
};
typedef struct Frac FRAC;

int euclides(int a, int b) {
 if(a < b) euclides(b,a);
 if(b == 0) return a;
 return euclides(b,a%b);
}
FRAC simp(FRAC f) {
  int mdc = euclides(f.num,f.den);
  f.num /= mdc;
  f.den /= mdc;
  return f;
}
FRAC soma(FRAC f1, FRAC f2) {
 FRAC f3;
 f3.num = (f1.num*f2.den)+(f2.num*f1.den);
 f3.den = f1.den*f2.den;
 if(f3.den == 0) f3.erro = 1;
 else f3.erro = 0;
 return f3;
}
FRAC sub(FRAC f1, FRAC f2) {
 FRAC f3;
 f3.num = (f1.num*f2.den)-(f2.num*f1.den);
 f3.den = f1.den*f2.den;
 if(f3.den == 0) f3.erro = 1;
 else f3.erro = 0;
 return f3;
}
FRAC mult(FRAC f1, FRAC f2) {
 FRAC f3;
 f3.num = f1.num*f2.num;
 f3.den = f1.den*f2.den;
 if(f3.den == 0) f3.erro = 1;
 else f3.erro = 0;
 return f3;
}
FRAC div(FRAC f1, FRAC f2) {
 FRAC f3;
 FRAC temp;
 temp.num = f2.num;
 f2.num = f2.den;
 f2.den = temp.num;
 f3 = mult(f1,f2);
 return f3;
}
int main() {
 int num,den;
 FRAC resultado;
 resultado.num = 1;
 resultado.den = 3;
 resultado.erro = 0;
 char c;
  scanf(" %c",&c);
  printf("Insira o numerador e o denominador da fracao, respetivamente:\n");
  scanf("%d %d",&num,&den);
  FRAC f1;
  f1.num = num;
  f1.den = den;
  if(f1.den == 0) f1.erro = 1;
  else f1.erro = 0;

  if(c == '+') {
   FRAC sum = soma(resultado,f1);
   simp(sum);
   printf("%d/%d\n",sum.num,sum.den);
  }
  else if(c == '-') {
   FRAC subtracao = sub(resultado,f1);
   simp(subtracao);
   printf("%d/%d\n",subtracao.num,subtracao.den);
  }
  else if(c == '*') {
   FRAC multiplicacao = mult(resultado,f1);
   simp(multiplicacao);
   printf("%d/%d\n",multiplicacao.num,multiplicacao.den);
  }
  else if(c == '/') {
   FRAC divisao = div(resultado,f1);
   simp(divisao);
   printf("%d/%d\n",divisao.num,divisao.den);
  }
  return 0;
}
