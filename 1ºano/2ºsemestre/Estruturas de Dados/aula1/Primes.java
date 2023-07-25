public class Primes {
    // Verifica se o número n é primo (apenas divisível por 1 e por si próprio)
    // [função ainda por completar]
    static boolean isPrime(int n) {
     for(int i=2; i*i<=n; i++) {
      if(n%i==0 && n!=i) {
      return false;
      }
    }
     return true;
   }
    public static void main(String[] args) {

	int n=1000000; // Limite dos números

	for (int i=2; i<=n; i++)
	    if (isPrime(i))
		System.out.println(i);
    }
}

// 1. imprime os números de 2 a 1000 (999 linhas)

/* 3.
a)
real	0m0.395s
user	0m0.104s
sys	0m0.056s
b)
real	0m1.421s
user	0m1.269s
sys	0m0.096s
c)
real	1m33.375s
user	1m27.459s
sys	0m1.412s */

/* 4.
Pra n=1000,
real	0m0.085s
user	0m0.061s
sys	0m0.019s

Pra n=100000,
real	0m0.436s
user	0m0.253s
sys	0m0.153s

Para n=1000000,
real	0m1.113s
user	0m0.544s
sys	0m0.499s */
