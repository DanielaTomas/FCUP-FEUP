import java.util.Scanner;
class Process {
  String name;
  int time;

  Process(String n, int t) {
    name = n;
    time = t;
  }
}
public class ED237 {
  static void iterar(MyQueue<Process> fila, int maxtime) {
    int total = 0;
    int cont = 0;
    while(!fila.isEmpty()) {
      Process p = fila.first();
     if((p.time - maxtime) > 0) {
      cont++;
      total += maxtime;
      p.time = p.time - maxtime;
      fila.enqueue(p);
      fila.dequeue();
     }
     else {
      cont++;
      total += p.time;
      System.out.println(p.name + " " + total + " " + cont);
      fila.dequeue();
     }
   }
 }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int maxtime = in.nextInt();
    int k = in.nextInt();
    in.nextLine();

    MyQueue<Process> fila = new LinkedListQueue<>();
    for(int i = 0; i < k; i++) {
      String n = in.next();
      int t = in.nextInt();
      in.nextLine();
      Process p = new Process(n,t);
      fila.enqueue(p);
    }
    iterar(fila,maxtime);
  }
}
