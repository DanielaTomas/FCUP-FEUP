import java.util.Scanner;

public class ReadNumbers {

  // Escrever os numeros guardados num array no stdout
  static void writeArray(int v[]) {
    for (int i = 0; i < v.length; i++)
      System.out.println("v[" + i + "] = " + v[i]);
  }
  static int amplitude(int v[]) {
    int amp;
    int max=v[0];
    int min=v[0];
     for(int i=1; i<v.length; i++) {
      if(v[i]<min) {
       min=v[i];
      }
      else if(v[i]>max){
       max=v[i];
      }
     }
     amp=max-min;
     return amp;
  }

  public static void main(String[] args) {

    Scanner stdin = new Scanner(System.in);
    int n = stdin.nextInt(); // Ler a quantidade de numeros que se seguem
    int v[] = new int[n]; // Cria um novo array com espaço para n (10) inteiros

    for (int i = 0; i < n; i++) // Ler os numeros a partir do stdin
      v[i] = stdin.nextInt();

    writeArray(v); // Chamar procedimento que escreve
    int amp=amplitude(v);
      System.out.println(amp);
  }
}
/* 2.
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 5
	at ReadNumbers.main(ReadNumbers.java:19)
*/
/* 3.
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 10
	at ReadNumbers.main(ReadNumbers.java:19)
*/
