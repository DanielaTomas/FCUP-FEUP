import java.util.Scanner;
public class ED211 {
  //ED211 - contando números pares
  public static int countEven(BTree<Integer> t) {
    return countEven(t.getRoot());
  }
  public static int countEven(BTNode<Integer> n) {
     if(n == null) return 0;
     int cont = 0;
     if(n.getValue() % 2 == 0) cont++;
     return cont + countEven(n.getLeft()) + countEven(n.getRight());
  }
  public static void main(String[] args) {

   Scanner in = new Scanner(System.in);
   BTree<Integer> t = LibBTree.readIntTree(in);

   System.out.println("countEven(...) = " + countEven(t));
  }
}
