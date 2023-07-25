import java.util.Scanner;
public class ED231 {
  static void novos_casos(int[] c, int n) {
    int max = c[1]-c[0];
    int min = max;
   for(int i = 1; i < n; i++) {
    if(!(i+1 == n)) {
     if(max < (c[i+1]-c[i])) max = c[i+1]-c[i];
     if(min > (c[i+1]-c[i])) min = c[i+1]-c[i];
    }
   }
   System.out.println(min + " " + max);
  }
  static void propagação(int[] c, int n) {
    int cont = 0;
    int periodo = 0;
    int max = 0;
    for(int i = 1; i < n; i++) {
      double d = (c[i]-c[i-1]);
      if((d/(c[i-1])*100) <= 5) {
       cont++;
       if(max < cont) max = cont;
      }
      else if((d/(c[i-1])*100) > 5 && cont != 0){
        cont = 0;
        periodo++;
      }
      if(i == n-1 && cont != 0) periodo++;
    }
    System.out.println(periodo + " " + max);
  }
  static void grafico(int[] c, int n) {
    int max = c[n-1]/100;
    char[][] matrix = new char[1000][1000];
    int aux = max;
    for(int i = 0; i < max; i++) {
      for(int j = 0; j < n; j++) {
        if((c[j]/100) < aux) {
          matrix[i][j] = '.';
        }
        else matrix[i][j] = '#';
      }
      aux--;
    }
    for(int i = 0; i < max; i++) {
      for(int j = 0; j < n; j++) {
        System.out.print(matrix[i][j]);
      }
      System.out.println();
    }
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();

    int[] c = new int[1000];
    for(int i = 0; i < n; i++)
      c[i] = in.nextInt();

    int flag = in.nextInt();
    if(flag == 1) novos_casos(c,n);
    else if(flag == 2) propagação(c,n);
    else if(flag == 3) grafico(c,n);
  }
}
