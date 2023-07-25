import java.util.Scanner;
​
public class Primos {
​
    public static int Crivo (int a,int b) {
​
        int contador = 0;
        int check[] = new int [b+1];
​
        for (int i = 0; i <= b; i++) {
            check[i] = 1;
        }
​
        for ( int x = 2; x*x <= b; x++) {
            if (check[x] == 1) {
                for ( int z = x*x; z <= b; z +=x) {
                    check[z] = 0;
                }
            }
        }
​
        for (int v = a; v <= b; v++) {
            if( check[v] == 1)
            contador ++;
        }
    return contador;
    }
​
    public static void main (String[] args) {
​
        Scanner stdin = new Scanner (System.in);

        int min = stdin.nextInt();
        int max = stdin.nextInt();
​
        System.out.println(Crivo(min,max));
    }
 }
