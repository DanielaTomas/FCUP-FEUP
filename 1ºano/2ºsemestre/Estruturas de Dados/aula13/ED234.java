import java.util.Scanner;
public class ED234 {
  public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int flag = in.nextInt();
      int n = in.nextInt();

      BSTMap<String,Integer> t = new BSTMap<>();
      BSTMap<String,Integer> e = new BSTMap<>();

      int max = 0,av = 0;
      for(int i = 0; i < n; i++) {
        String film = in.next();
        av = in.nextInt();
        if(flag == 1) t.put(film,av);
        else if(flag == 2) {
          Integer a = t.get(film);
          if(a == null) t.put(film,1);
          else {
            if(a+1 > max) max = a+1;
            t.put(film,a+1);
          }
        }
        else if(flag == 3) {
          Integer a = e.get(film);
          if(a == null) e.put(film,1);
          else {
            if(a+1 > max) max = a+1;
            e.put(film,a+1);
          }
          a = t.get(film);
          if(a == null) t.put(film,av);
          else t.put(film,((t.get(film)+av)));
        }
      }
      if(flag == 1) System.out.println(t.size());
      else if(flag == 2) {
        for(String s : t.keys())
          if(t.get(s) == max) System.out.println(s + " " + max);
      }
      else if(flag == 3) {
        for(String s : t.keys()) {
         //System.out.println(s + " " + ((double)t.get(s))/((double)e.get(s)));
          if(((double)t.get(s))/((double)e.get(s)) >= 5) System.out.println(s);
        }
      }
  }
}
