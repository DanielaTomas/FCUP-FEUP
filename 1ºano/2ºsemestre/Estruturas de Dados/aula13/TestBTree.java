import java.util.Scanner;
import java.util.Arrays;

public class TestBTree {
   public static void main(String[] args) {
      // Ler arvore de inteiros em preorder
      Scanner in = new Scanner(System.in);
      BTree<Integer> t = LibBTree.readIntTree(in);

  /*    System.out.println("count() = " + t.count());
      System.out.println("level(2) = " + t.level(2));
      System.out.println("level(5) = " + t.level(5));
      System.out.println("level(1) = " + t.level(1));
      System.out.println("level(3) = " + t.level(3));

      System.out.println("internal() = " + t.internal());

      t.printPreOrder();
      t.cut(-1);
      t.printPreOrder(); */
      int[] v = new int[2];
      v = t.maxLevel();
      System.out.println(Arrays.toString(v));

      
   }
}
