import java.util.Scanner;

public class Calculadora {
  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    char[] c = ("" + n).toCharArray();

      for(int i = 0; i < 7; i++) {
          if(i == 0) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '1' || c[n] == '4')
              System.out.print("....");
             else
              System.out.print(".##.");
             if(n < c.length-1)System.out.print(" ");
            }
          }
          else if(i == 1) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '1' || c[n] == '2' || c[n] == '3')
              System.out.print("...#");
             else if(c[n] == '5' || c[n] == '6')
              System.out.print("#...");
             else
              System.out.print("#..#");
             if(n < c.length-1)System.out.print(" ");
            }
          }
          else if(i == 2) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '1' || c[n] == '2' || c[n] == '3')
              System.out.print("...#");
             else if(c[n] == '5' || c[n] == '6')
              System.out.print("#...");
             else
              System.out.print("#..#");
             if(n < c.length-1)System.out.print(" ");
            }
          }
          else if(i == 3) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '0' || c[n] == '1' || c[n] == '7')
              System.out.print("....");
             else
              System.out.print(".##.");
             if(n < c.length-1)System.out.print(" ");
            }
          }
          else if(i == 4) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '2')
              System.out.print("#...");
             else if(c[n] == '0' || c[n] == '6' || c[n] == '8')
              System.out.print("#..#");
             else
              System.out.print("...#");
             if(n < c.length-1)System.out.print(" ");
            }
          }
          else if(i == 5) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '2')
              System.out.print("#...");
             else if(c[n] == '0' || c[n] == '6' || c[n] == '8')
              System.out.print("#..#");
             else
              System.out.print("...#");
             if(n < c.length-1)System.out.print(" ");
            }
          }
          else if(i == 6) {
            for(n = 0; n < c.length; n++) {
             if(c[n] == '1' || c[n] == '4'|| c[n] == '7')
              System.out.print("....");
             else
              System.out.print(".##.");
             if(n < c.length-1)System.out.print(" ");
            }
           }
       System.out.println();
      }
    }
}
