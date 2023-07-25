import java.util.Scanner;
public class ED005 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    MyStack<Integer> pilha = new LinkedListStack<>();
    int n = in.nextInt();
    in.nextLine();
    for(int i = 0; i < n; i++) {
      int cont1 = 0, cont2 = 0;
      while(!pilha.isEmpty()) {
       pilha.pop();
      }
      String s = in.nextLine();
      for(int j = 0; j < s.length(); j++) {
        if((s.charAt(j) >= '0' && s.charAt(j) <= '9')) {
         cont1++;
         pilha.push(Character.getNumericValue(s.charAt(j)));
        }
        else if(s.charAt(j) != ' '){
          if(pilha.size() > 1) {
            int k1 = pilha.pop();
            int k2 = pilha.pop();
            if(s.charAt(j) == '+') pilha.push(k1+k2);
            else if(s.charAt(j) == '-') pilha.push(k2-k1);
            else if(s.charAt(j) == '*') pilha.push(k1*k2);
            else if(s.charAt(j) == '/') pilha.push(k2/k1);
            cont2++;
          }
        }
      }
      if((pilha.size() != 1) || (cont1 != (cont2+1))) System.out.println("Expressao Incorreta");
      else  System.out.println(pilha.top());
      System.out.println(pilha);
    }
  }
}
