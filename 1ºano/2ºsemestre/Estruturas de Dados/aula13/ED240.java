import java.util.Scanner;
import java.util.Arrays;
public class ED240 {
  static int min; //valor minimo na arvore
  static int occ; //numero de ocorrencias do minimo
  static int i;
  public static void minValue(BTree<Integer> t) { //valor minimo na arvore
     min = t.getRoot().getValue();
     minValue(t.getRoot(),t);
     //System.out.println(min);
  }
  private static void minValue(BTNode<Integer> n, BTree<Integer> t) {
     if (n == null) return;
     if(n.getValue() < min) min = n.getValue();
     minValue(n.getLeft(),t);
     minValue(n.getRight(),t);
  }

  //----------------------------------------------------------------------------------------------//

  public static int minOccurrences(BTree<Integer> t) { //numero de ocorrencias do minimo
     occ = 0;
     return minOccurrences(t.getRoot(),t);
  }
  private static int minOccurrences(BTNode<Integer> n, BTree<Integer> t) {
     if(n == null) return 0;
     int cont = 0;
     if(n.getValue().equals(min)) cont++;
     return cont + minOccurrences(n.getLeft(),t) + minOccurrences(n.getRight(),t);
  }

  //----------------------------------------------------------------------------------------------//

  public static String[] paths(BTree<Integer> t) { //caminhos da arvore que vao dar ao valor minimo
    minValue(t);
    occ = minOccurrences(t.getRoot(),t);
    i = 0;
    String[] s = new String[occ];
    paths(t.getRoot(),"",s,t);
    return s;
  }
  private static void paths(BTNode<Integer> n, String p, String[] s,BTree<Integer> t) {
    if(n == null) return;
    if(t.getRoot().getValue().equals(min) && i == 0) { //raiz igual ao minimo
      s[0] = "R";
      i++;
    }
    else if(n.getValue().equals(min)) {
      s[i] = p;
      //System.out.println("s[" + i + "] = " + s[i]);
      i++;
    }
    paths(n.getLeft(),p + "E",s,t);
    paths(n.getRight(),p + "D",s,t);
  }

  //----------------------------------------------------------------------------------------------//

  public static void main(String[] args) {
     Scanner in = new Scanner(System.in);

     int j = in.nextInt();
     for(int l = 0; l < j; l++) {
       BTree<Integer> t = LibBTree.readIntTree(in);
       minValue(t);
       occ = minOccurrences(t.getRoot(),t);

       String[] s = new String[occ];

       s = paths(t);
       System.out.println(Arrays.toString(s));
     }
  }
}
