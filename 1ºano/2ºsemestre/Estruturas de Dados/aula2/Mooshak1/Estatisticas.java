import java.util.Scanner;

public class Estatisticas {
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
  static double media(int v[]) {
   double media=0;
   double cont=0;
   for(int i=0; i<v.length; i++) {
    cont+=v[i];
   }
   media=cont/v.length;
   return media;
  }
  public static void main(String[] args) {

    Scanner stdin = new Scanner(System.in);
    int n = stdin.nextInt();
    int v[] = new int[n];

    for (int i = 0; i < n; i++)
     v[i] = stdin.nextInt();

    double media=media(v);
     System.out.printf("%.2f\n",media);

    int amp=amplitude(v);
     System.out.println(amp);
  }
}
