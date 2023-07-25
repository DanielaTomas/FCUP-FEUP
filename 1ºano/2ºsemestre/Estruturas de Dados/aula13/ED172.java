import java.util.Scanner;
import java.util.LinkedList;
public class ED172 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    BSTMap<String,Integer> map = new BSTMap<>();

    while(in.hasNextLine()) {
      String s = in.nextLine();
      String[] words = s.split(" ");
      for(int j = 0; j < words.length; j++) {
        Integer i = map.get(words[j]);
        if (i == null) map.put(words[j],1);
        else map.put(words[j],i+1);
      }
    }

    LinkedList<String> words = map.keys();

    for(String s : words)
    System.out.println(s + ": " + map.get(s));

  }
}
