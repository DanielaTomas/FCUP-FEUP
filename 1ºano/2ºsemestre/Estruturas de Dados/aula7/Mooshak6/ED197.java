public class ED197 {
  public static MyQueue<Integer> merge(MyQueue<Integer> a,MyQueue<Integer> b) {
    MyQueue<Integer> fila = new LinkedListQueue<>();
    while(!(a.isEmpty()) || !(b.isEmpty())) {
      if(a.isEmpty())
       fila.enqueue(b.dequeue());
      else if(b.isEmpty())
       fila.enqueue(a.dequeue());
      else if(a.first() == b.first()) {
       fila.enqueue(a.dequeue());
       fila.enqueue(b.dequeue());
      }
      else if(a.first() < b.first())
       fila.enqueue(a.dequeue());
      else
       fila.enqueue(b.dequeue());
    }
    return fila;
  }
  public static void main(String[] args) {
    MyQueue<Integer> q = new LinkedListQueue<>();
    MyQueue<Integer> a = new LinkedListQueue<>();
    MyQueue<Integer> b = new LinkedListQueue<>();

    System.out.println("Teste #1");
    a.enqueue(2);
    a.enqueue(4);
    a.enqueue(8);
    a.enqueue(10);
    b.enqueue(1);
    b.enqueue(4);
    b.enqueue(9);
    System.out.println("a = " + a);
    System.out.println("b = " + b);
    q = merge(a,b);
    System.out.println("\ta = " + a);
    System.out.println("\tb = " + b);
    System.out.println("\tq = " + q);

    MyQueue<Integer> q1 = new LinkedListQueue<>();
    MyQueue<Integer> a1 = new LinkedListQueue<>();
    MyQueue<Integer> b1 = new LinkedListQueue<>();

    System.out.println("\nTeste #2");
    a1.enqueue(1);
    a1.enqueue(2);
    a1.enqueue(4);
    a1.enqueue(5);
    b1.enqueue(2);
    b1.enqueue(3);
    b1.enqueue(5);
    b1.enqueue(6);
    b1.enqueue(8);
    System.out.println("a1 = " + a1);
    System.out.println("b1 = " + b1);
    q1 = merge(a1,b1);
    System.out.println("\ta1 = " + a1);
    System.out.println("\tb1 = " + b1);
    System.out.println("\tq1 = " + q1);

    MyQueue<Integer> q2 = new LinkedListQueue<>();
    MyQueue<Integer> a2 = new LinkedListQueue<>();
    MyQueue<Integer> b2 = new LinkedListQueue<>();

    System.out.println("\nTeste #3");
    a2.enqueue(10);
    a2.enqueue(20);
    a2.enqueue(30);
    a2.enqueue(40);
    a2.enqueue(50);
    a2.enqueue(70);
    b2.enqueue(1);
    b2.enqueue(2);
    b2.enqueue(3);
    b2.enqueue(44);
    b2.enqueue(50);
    b2.enqueue(60);
    b2.enqueue(70);
    b2.enqueue(90);
    System.out.println("a2 = " + a2);
    System.out.println("b2 = " + b2);
    q2 = merge(a2,b2);
    System.out.println("\ta2 = " + a2);
    System.out.println("\tb2 = " + b2);
    System.out.println("\tq2 = " + q2);
  }
}
