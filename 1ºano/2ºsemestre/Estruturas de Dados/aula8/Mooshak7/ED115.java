import java.util.Scanner;
class Cliente {
  String nome;
  int chegada;
  int produtos;
  Cliente(String n, int c, int p) {
    nome = n;
    chegada = c;
    produtos = p;
  }
}
class Fila { 
  public MyQueue<Cliente> fila;

  Fila() {
   fila = new LinkedListQueue<Cliente>();
  }
}
class ED115 {

  private static Fila caixas[];
  private static Fila clientes;
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int flag = in.nextInt();
    int n = in.nextInt();

    clientes = new Fila();
    caixas = new Fila[n];

    int k[] = new int[n];
    for(int i = 0; i < n; i++) {
      k[i] = in.nextInt();
      caixas[i] = new Fila();
    }
    int n1 = in.nextInt();
    in.nextLine();
    for(int i = 0; i < n1; i++) {
      String s = in.next();
      int c = in.nextInt();
      int p = in.nextInt();
      Cliente cl = new Cliente(s,c,p);
      clientes.fila.enqueue(cl);
      in.nextLine();
    }
    if(flag == 1) {
      int atendimento = 0;
     for(int i = 0; i < n1; i++) {
      Cliente cliente = clientes.fila.dequeue();
      if(i == 0) atendimento = 10 + cliente.produtos * k[0] + cliente.chegada;
      else {
       int a = cliente.chegada;
       while(a < atendimento) a++;
        atendimento = 10 + cliente.produtos * k[0] + a;
      }
      System.out.println(cliente.nome + " " + cliente.chegada + " " + atendimento);
     }
    }
    //else if(flag == 2)
  }
}
