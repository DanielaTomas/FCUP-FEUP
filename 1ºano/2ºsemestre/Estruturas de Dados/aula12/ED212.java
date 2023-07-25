import java.util.Scanner;
public class ED212 {
  public static int[] sumLevels(BTree<Integer> t) {
    int size = t.depth()+1;
     int[] v = new int[size];
       sumLevels(t.getRoot(),v,0);
     return v;
  }
  public static int sumLevels(BTNode<Integer> n,int[] v, int i) {
   if(n == null) return 0;
   v[i] += n.getValue();
   sumLevels(n.getRight(),v,i+1);
   sumLevels(n.getLeft(),v,i+1);
   return v[i];
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    BTree<Integer> t = LibBTree.readIntTree(in);
    int size = sumLevels(t).length;
    int[] v = sumLevels(t);
    for(int i = 0; i < size; i++) {
      System.out.println("sumLevels("+ i +") = " + v[i]);
    }

  }
}
