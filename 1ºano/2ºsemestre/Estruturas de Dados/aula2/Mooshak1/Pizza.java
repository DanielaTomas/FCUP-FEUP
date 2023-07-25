import java.util.Scanner;
public class Pizza {
  public static void main(String[] v) {
    Scanner ler = new Scanner(System.in);
    int n = ler.nextInt(); //numero ingredientes que o Mario nao gosta
    int[] v1 = new int[n];

    for (int i = 0; i < n; i++) {
      v1[i] = ler.nextInt(); //ingredientes que o Mario nao gosta
    }

    int p = ler.nextInt(); //numero de pizzas
    ler.nextLine();
    int cont = p;
    int aux = p;

    for (int i = 0; i < p; i++) {
      int k = ler.nextInt(); //numero de ingredientes da pizza
      int[] v2 = new int[k];
      for (int j = 0; j < k; j++) {
        v2[j] = ler.nextInt(); //ingredientes da pizza
      }
      for (int l = 0; l < k; l++) {
        for (int j = 0; j < n; j++) {
          if (v2[l] == v1[j]) {
            aux = cont;
            cont--;
            break;
          }
        }
        if (aux != cont) {
          aux = cont;
          break;
        }
      }
      ler.nextLine();
    }

    System.out.println(cont);
  }
}
