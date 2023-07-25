// Uma classe muito simples que usa um ciclo para imprimir numeros entre 1 e n

// O ficheiro tem de ter o mesmo nome da classe + a extensão '.java'

// 4. e 5.
public class Numbers {
    public static void main(String[] args) {
	int n = 10, soma=0; // limite dos numeros, variável para ir contendo a soma
	System.out.print("Numeros de 1 a " + n + ": "); // + é o operador de concatenação de strings
	for (int i=1; i<=n; i++) {
    soma+=i;
    if(i<n) {
     System.out.print(i + ",");
    }
    else
    System.out.println(n);
  }
    System.out.println("Soma = " + soma);
  }
}

/* 1.
a) O ficheiro deve-se chamar: Numbers.java
Caso tenha outro nome, por exemplo, exercicio2.java, o compilador diz:

exercicio2.java:4: error: class Numbers is public, should be declared in a file named Numbers.java
public class Numbers {
       ^
1 error
*/

// b) Numbers.class

/* c)
Numeros de 1 a 10:
1
2
3
4
5
6
7
8
9
10
*/

/* 2. Dá erro de compilação porque a linguagem java é case sensitive, ou seja,
o programa tem comportamentos diferentes em função do uso de maiúsculas e
minusculas */

// 3. Erro de compilação
