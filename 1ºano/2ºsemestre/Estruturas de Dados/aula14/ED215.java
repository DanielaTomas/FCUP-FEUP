import java.util.Scanner;
import java.util.Comparator;
class Person implements Comparable<Person> {
  String nome;
  Integer preco;

  Person(String n, int p) {
    nome = n;
    preco = p;
  }

  public int compareTo(Person person) {
    return (person.preco).compareTo(preco);
  }
}

public class ED215 {
  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int max = 0;
    MinHeap<Person> heap = new MinHeap<>(n);
    for(int i = 0; i < n; i++) {
      String evento = in.next();
      if(evento.equals("OFERTA")) {
        Person person = new Person(in.next(),in.nextInt());
        heap.insert(person);
      }
      else if(evento.equals("VENDA")) {
        Person aux = heap.removeMin();
        System.out.println(aux.preco + " " + aux.nome);
      }
    }
  }
}
