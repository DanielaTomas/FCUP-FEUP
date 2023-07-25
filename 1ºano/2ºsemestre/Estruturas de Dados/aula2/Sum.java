// Importa a classe Scanner, que será usada para leitura de dados
import java.util.Scanner;

public class Sum {
   public static void main(String[] args) {

      // Cria um objecto Scanner para ler da entrada padrão ("standard input")
      Scanner stdin = new Scanner(System.in);

      // Chama o método nextInt() para ir buscar o próximo inteiro
      int a = stdin.nextInt();
      int b = stdin.nextInt();

      // Imprime a soma dos dois números
      System.out.println(a+b);
   }

}

/* 2. Dá erro de compilação
/* 3.
------------------------------------------------------------
Exception in thread "main" java.util.InputMismatchException
	at java.util.Scanner.throwFor(Scanner.java:864)
	at java.util.Scanner.next(Scanner.java:1485)
	at java.util.Scanner.nextInt(Scanner.java:2117)
	at java.util.Scanner.nextInt(Scanner.java:2076)
	at Sum.main(Sum.java:11)
------------------------------------------------------------
Isto acontece porque houve um erro no tipo de dados (int / double)
*/
/* 4. double a = stdin.nextDouble();
double b = stdin.nextDouble();
*/
