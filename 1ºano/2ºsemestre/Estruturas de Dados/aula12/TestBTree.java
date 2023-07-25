import java.util.Scanner;

public class TestBTree {
   public static void main(String[] args) {
      // Ler arvore de inteiros em preorder
      Scanner in = new Scanner(System.in);
      BTree<Integer> t = LibBTree.readIntTree(in);

      // Escrever resultado de chamada a alguns metodos
      System.out.println("numberNodes = " + t.numberNodes());
      System.out.println("depth = " + t.depth());
      System.out.println("contains(2) = " + t.contains(2));
      System.out.println("contains(3) = " + t.contains(3));

      // Escrever nos da arvore seguindo varias ordens possiveis
      t.printPreOrder();
      t.printInOrder();
      t.printPostOrder();
      t.printBFS();
      t.printDFS();

    /*  System.out.println("numberLeafs() = " + t.numberLeafs());

      System.out.println("strict() = " + t.strict());

      System.out.println("path('ED') = " + t.path("ED"));
      System.out.println("path('E') = " + t.path("E"));
      System.out.println("path('DD') = " + t.path("DD"));
      System.out.println("path('R') = " + t.path("R"));
      System.out.println("path('DE') = " + t.path("DE"));

      System.out.println("nodesLevel(0) = " + t.nodesLevel(0));
      System.out.println("nodesLevel(1) = " + t.nodesLevel(1));
      System.out.println("nodesLevel(2) = " + t.nodesLevel(2));
      System.out.println("nodesLevel(3) = " + t.nodesLevel(3));

      System.out.println("minValue() = " + t.minValue());
      System.out.println("maxValue() = " + t.maxValue()); */

   }
}
