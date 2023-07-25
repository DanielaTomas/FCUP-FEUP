import java.util.Scanner;
public class ED164 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
   // o 15 está a ficar na árvore, devia ler primeiro o 15 e depois os valores da árvore
    BSTree<String> t = new BSTree<>();
    while(in.hasNextLine()) {
      String s = in.nextLine();
      if(t.contains(s)) continue;
      else t.insert(s);
      System.out.println(s);
    }
    System.out.println((t.numberNodes()-1));
  }
}
