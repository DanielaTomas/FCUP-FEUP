import java.util.Scanner;
public class ED235 {
  static void write(int t) {
    for(int j = t; j > 0; j--) {
      int i = 0;
      for( ; i < j; i++)
       System.out.print("#");
      while(i < t) {
        System.out.print(".");
        i++;
      }
      System.out.println();
    }
  }
  public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
     int n = in.nextInt();

     for(int i = 0; i < n; i++) {
       int t = in.nextInt();
       write(t);
     }
  }
}
