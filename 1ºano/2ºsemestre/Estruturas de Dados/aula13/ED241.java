import java.util.Scanner;

public class ED241 {
  public static void flag1(Scanner in, int n) {
    BSTree<String> t = new BSTree<>();
    for(int i = 0; i < n; i++) {
      String nome = in.next();
      String problema = in.next();
      String resultado = in.next();
      t.insert(nome);
    }
    System.out.println(t.numberNodes());
  }
  public static void flag2(Scanner in, int n) {
    BSTMap<String,Integer> map = new BSTMap<>();
    String maxK = "";
    Integer maxV = 0;
    for(int i = 0; i < n; i++) {
      String nome = in.next();
      String problema = in.next();
      String resultado = in.next();
      Integer k = map.get(problema);
      if(k == null) map.put(problema,1);
      else map.put(problema,k+1);
      if(map.get(problema) > maxV) {
        maxK = problema;
        maxV = map.get(problema);
      }
    }
    System.out.println(maxK + " " + maxV);
  }
  public static void flag3(Scanner in, int n) {
    BSTMap<String,Integer> map = new BSTMap<>();
    BSTMap<String,Integer> map2 = new BSTMap<>();
    for(int i = 0; i < n; i++) {
      String nome = in.next();
      String problema = in.next();
      String resultado = in.next();
      if(resultado.equals("Accepted")) {
        Integer k = map.get(problema);
        if(k == null) map.put(problema,1);
        else map.put(problema,k+1);
      }
      Integer k = map2.get(problema);
      if(k == null) map2.put(problema,1);
      else map2.put(problema,k+1);
    }
    for(String k : map.keys()) {
      //System.out.println(map.get(k) + " " + map2.get(k));
      if((map.get(k)/((double)(map2.get(k)))) >= 0.5)
        System.out.println(k);
    }
  }
  public static void flag4(Scanner in, int n) {
    BSTMap<String,BSTree<String>> map = new BSTMap<>();
    BSTree<String> t = new BSTree<>();

    for(int i = 0; i < n; i++) {
      String nome = in.next();
      String problema = in.next();
      String resultado = in.next();
      t.insert(problema);
      if(resultado.equals("Accepted")) {
        if(map.get(nome) == null) map.put(nome,new BSTree<String>());
        map.get(nome).insert(problema);
      }
    }
    for(String k : map.keys()) {
      if(t.numberNodes() == map.get(k).numberNodes())
        System.out.println(k);
    }
  }
  public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
     int flag = in.nextInt();
     int n = in.nextInt();
     in.nextLine();

     if(flag == 1) flag1(in,n);
     else if(flag == 2) flag2(in,n);
     else if(flag == 3) flag3(in,n);
     else if(flag == 4) flag4(in,n);
  }
}
