public class ED196 {
  public static void process(MyQueue<String> q,MyQueue<String> a,MyQueue<String> b) {
    int size = q.size();
    if(size < 2 || (size % 2) != 0) return;
    for(int i=0; i < size; i+=2) {
      String aux = q.dequeue();
      if(q.first().equals("A")|| (q.first().equals("X") && a.size() < b.size())) a.enqueue(aux);
      else if(q.first().equals("B") || (q.first().equals("X") && a.size() > b.size())) b.enqueue(aux);
      q.dequeue();
     }
  }
  public static void main(String[] args) {
    MyQueue<String> q = new LinkedListQueue<>();
    MyQueue<String> a = new LinkedListQueue<>();
    MyQueue<String> b = new LinkedListQueue<>();

    System.out.println("Teste #1");
    q.enqueue("Luis");
    q.enqueue("B");
    q.enqueue("Pedro");
    q.enqueue("A");
    q.enqueue("Luisa");
    q.enqueue("A");
    q.enqueue("Joao");
    q.enqueue("X");
    q.enqueue("Jose");
    q.enqueue("X");
    q.enqueue("Miguel");
    q.enqueue("B");

    System.out.println("q = " + q);
    System.out.println("a = " + a);
    System.out.println("b = " + b);
    process(q,a,b);
    System.out.println("q = " + q);
    System.out.println("a = " + a);
    System.out.println("b = " + b);

    MyQueue<String> q1 = new LinkedListQueue<>();
    MyQueue<String> a1 = new LinkedListQueue<>();
    MyQueue<String> b1 = new LinkedListQueue<>();

    System.out.println("Teste #2");
    q1.enqueue("Luis");
    q1.enqueue("B");
    q1.enqueue("Pedro");
    q1.enqueue("B");
    q1.enqueue("Luisa");
    q1.enqueue("X");
    q1.enqueue("Joao");
    q1.enqueue("X");

    System.out.println("q1 = " + q1);
    System.out.println("a1 = " + a1);
    System.out.println("b1 = " + b1);
    process(q1,a1,b1);
    System.out.println("q1 = " + q1);
    System.out.println("a1 = " + a1);
    System.out.println("b1 = " + b1);
  }
}
