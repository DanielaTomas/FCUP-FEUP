import java.util.Scanner;
import java.util.LinkedList;
class Bombeiro {
  public String nome;
  public int eventos;
  public int minutos;

  Bombeiro(String n) {
    nome = n;
    eventos = 0;
    minutos = 0;
  }
}
class Evento {
  int bombeiros;
  int inicio;

  Evento(int b, int i) {
    bombeiros = b;
    inicio = i;
  }
}

public class ED095 {
  public static void flag1(Scanner in, int n) {
     MyQueue<Bombeiro> fila = new LinkedListQueue<>();
     for(int i = 0; i < n; i++) {
       String nome = in.nextLine();
       Bombeiro b = new Bombeiro(nome);
       fila.enqueue(b);
     }
     Evento e[] = new Evento[501];
     int cont = 0;
     String tipo = in.nextLine();
     while(!tipo.equals("FIM")) {
      if(tipo.equals("PARTIDA")) {
        int ev = nextInt();
        int b = in.nextInt();
        int i = in.nextInt();
        cont++;
      }
      else if(tipo.equals("CHEGADA")) {
       int ev = in.nextInt();
       int fim = in.nextInt();
      }
      tipo = in.nextLine();
    }
  }
  public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
     int flag = in.nextInt();
     int n = in.nextInt();
     in.nextLine();
     if(flag == 1) flag1(in,n);
     //else if(flaf == 2) flag2(in,n);
     //else if(flaf == 3) flag3(in,n);
 }
}
