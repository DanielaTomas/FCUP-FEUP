import java.util.Scanner;
import java.util.Arrays;
public class ED201 {
   static int max;
   static int tempo;
   // Escrever todos os subconjuntos do array v[]
   static void sets(int v[]) {
      // array de booleanos para representar o conjunto
      boolean used[] = new boolean[v.length];
      goSets(0, v, used); // chamar funcao recursiva
   }

   // Gera todos os subconjuntos a partir da posicao 'cur'
   static void goSets(int cur, int v[], boolean used[]) {
      if (cur == v.length) {  // Caso base: terminamos o conjunto
         // Escrever conjunto
         int soma = 0;
         for(int i = 0; i < v.length; i++)
          if(used[i]) soma += v[i];
         if((soma > max) && (soma <= tempo)) max = soma;
      }
      else {                  // Se nao terminamos, continuar a gerar
         used[cur] = true;      // Subconjuntos que incluem o elemento atual
         goSets(cur+1, v, used);// Chamada recursiva
         used[cur] = false;     // Subconjuntos que nao incluem o elemento atual
         goSets(cur+1, v, used);// Chamada recursiva
      }
   }

   public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      tempo = in.nextInt();
      int n = in.nextInt();
      int[] v = new int[n];
      for(int i = 0; i < n; i++)
        v[i] = in.nextInt();
      max = 0;
      sets(v);
      System.out.println(max);
   }
}
