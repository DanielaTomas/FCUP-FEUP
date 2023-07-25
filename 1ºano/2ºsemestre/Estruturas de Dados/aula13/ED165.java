import java.util.Scanner;
public class ED165 {
  public static void main(String[] args) {
   Scanner in = new Scanner(System.in);
   int n = in.nextInt();

   int[] v = new int[n];
   for(int i = 0; i < n; i++)
     v[i] = in.nextInt();

   BSTree<Integer> t = new BSTree<>();
   for(int i = 0; i < n; i++) {
     for(int j = 0; j < n; j++) {
       int soma = v[i]+v[j];
       t.insert(soma);
     }
   }
   n = in.nextInt();
   for(int i = 0; i < n; i++) {
     int val = in.nextInt();
     if(t.contains(val))
       System.out.println(val + ": sim");
     else System.out.println(val + ": nao");
   }
  }
}
