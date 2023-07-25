import java.util.Scanner;
public class ED006 {

 public static int numero_palavras(String frase) {
    int count = 1;
    if(frase.length() == 0) return 0;
    for(int i = 0; i < frase.length(); i++) {
      if(frase.charAt(i) == ' ') {
       count++;
      }
    }
    return count;
 }
 public static void resultado(CircularLinkedList nome, int count) {
   if(nome.getFirst().equals("Carlos")) {
    System.out.println("O Carlos nao se livrou");
   }
   else {
    System.out.println("O Carlos livrou-se (coitado do " + nome.getFirst() + "!)");
  }
 }
 public static void main(String[] args) {
  Scanner in = new Scanner(System.in);
  CircularLinkedList<String> nome = new CircularLinkedList<>();
  int n = in.nextInt();
  in.nextLine();

  for(int i = 0; i < n; i++) {
    String frase = in.nextLine();
    int count = numero_palavras(frase);
    int k = in.nextInt();
    for(int j = 0; j < k; j++) {
      nome.addLast(in.next());
    }
    while(nome.size() > 1) {
      for(int j = 0; j < count-1; j++) {
       nome.rotate();
      }
      nome.removeFirst();
    }
    resultado(nome,count);
    for(int j = 0; j < count; j++) {
      nome.removeFirst();
    }
    in.nextLine();
  }
 }
}
