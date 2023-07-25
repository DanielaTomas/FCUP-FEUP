import java.util.Scanner;
public class ED198 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] v = new int[n];
    int[] best = new int[n];
    for(int l = 0; l < n; l++)
      v[l] = in.nextInt();

    best[0] = v[0];
    int maxSoFar = v[0]; // porque é esta uma boa escolha para a melhor soma inicial?
    for(int i = 0; i < n; i++) { // Todas as posicoes iniciais possiveis
        if(i+1 != n) {
          if(best[i] >= 0) best[i+1] = best[i]+v[i+1];
          else best[i+1] = v[i+1];
          if (best[i] > maxSoFar) maxSoFar = best[i];
        }
    }
    System.out.println(maxSoFar);
  }
}
/*
 int sum = 0;
for(int j = i; j+1 < n; j++) { // Todas as posicoes finais possiveis
   //for (int k = i; k <= j; k++) // Calcular soma entre posicoes i e j
   sum += v[j];
   //System.out.println("Soma entre " + i + " e " + j + " = " + sum);*/
