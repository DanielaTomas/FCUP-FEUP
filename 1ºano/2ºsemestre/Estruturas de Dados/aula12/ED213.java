import java.util.Scanner;
public class ED213 {
  static String path;
  static int max;
  public static String maxSum(BTree<Integer> t) {
    max = 0;
    maxSum(t.getRoot(),0,"");
    return path;
  }
  public static void maxSum(BTNode<Integer> n,int soma,String s) {
   if(n == null) return;
   soma += n.getValue();
   if(n.getLeft() == null && n.getRight() == null) {
     if(soma > max) {
       max = soma;
       path = s;
     }
   }
   maxSum(n.getLeft(),soma,s + "E");
   maxSum(n.getRight(),soma,s + "D");
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();

    for(int i = 0; i < n; i++) {
     BTree<Integer> t = LibBTree.readIntTree(in);
     System.out.println(maxSum(t));
    }

  }
}
