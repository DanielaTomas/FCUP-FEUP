import java.util.Scanner;
public class Palindrome {
  public static boolean isPalindrome(String s) {
    int size = s.length();
    for (int i = 0; i < size / 2; i++) {
      if (s.charAt(i) != s.charAt(size - i - 1))
        return false;
    }
    return true;
  }
  public static String Min_Espacos(String s) {
    int size = s.length();
    String news = "";
    for (int i = 0; i < size; i++) {
      if (Character.isLetter(s.charAt(i)) == true) {
        news += s.charAt(i);
      }
    }
    news = news.toLowerCase();

    return news;
  }
  public static void main(String[] args) {
    Scanner ler = new Scanner(System.in);
    int n = ler.nextInt();
    ler.nextLine();
    System.out.println(n);
    for (int i = 0; i < n; i++) {
      String s = ler.nextLine();
      s = Min_Espacos(s);
      if (isPalindrome(s) == true) {
        System.out.println("sim");
      }
      else {
        System.out.println("nao");
      }
    }
  }
}
