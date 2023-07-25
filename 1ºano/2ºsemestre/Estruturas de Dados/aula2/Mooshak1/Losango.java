import java.util.Scanner;
public class Losango {
 static void losango(int n) {
  int i,espacos,cardinais;
  cardinais=1;
  if(n%2!=0) { //impar
   n-=1;
   //parte de cima losango
   for(espacos=n/2; espacos>0; espacos--) {
    //espacos antes
    for(i=1; i<=espacos; i++) {
     System.out.print(".");
    }
    //cardinais
    for(i=1; i<=cardinais; i++) {
     System.out.print("#");
    }
   cardinais+=2;
   //espacos depois
   for(i=1; i<=espacos; i++) {
    System.out.print(".");
   }
   System.out.print("\n");
  }
  //parte de baixo losango
   for( ; cardinais>0; cardinais-=2) {
    //espacos antes
    for(i=1; i<=espacos; i++) {
     System.out.print(".");
    }
   //cardinais
   for(i=1; i<=cardinais; i++) {
    System.out.print("#");
   }
   //espacos depois
   for(i=1; i<=espacos; i++) {
    System.out.print(".");
   }
   espacos++;
   System.out.print("\n");
  }
 }
}
 public static void main(String[] args) {
    Scanner ler = new Scanner(System.in); //Inicializas o scanner ( System.in basicamente serve para dizer de onde é suposto ele ler o input )
    int n = ler.nextInt();  // sc.nextLine() lê caracteres da consola, e poe-nos na variavel palavra
    losango(n);
 }
}
