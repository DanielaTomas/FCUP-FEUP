public class ED195 {
  public static boolean balanced(String s) {
    MyStack<Character> pilha = new LinkedListStack<>();
    if(s.length() == 1) return false;
    for(int i=0; i < s.length(); i++) {
      if(s.charAt(i) == '[' || s.charAt(i) == '(') {
       pilha.push(s.charAt(i));
      }
      else if(s.charAt(i) == ']') {
       if(pilha.size() != 0 && pilha.top() == '[')
        pilha.pop();
       else return false;
      }
      else if(s.charAt(i) == ')') {
        if(pilha.size() != 0 && pilha.top() == '(')
        pilha.pop();
       else return false;
      }
    }
    if(pilha.size() == 0) return true;
    else return false;
  }
  public static void main(String[] args){
  	String s = " ([()]) ";  //true
	  String s1 = " [()()] "; //true
  	String s2 = " (()] ";   //false
  	String s3 = " [()[]) "; //false
  	String s4 = " [()[] ";  //false
    String s5 = " ( ";      //false
  	System.out.println(balanced(s));
  	System.out.println(balanced(s1));
  	System.out.println(balanced(s2));
  	System.out.println(balanced(s3));
  	System.out.println(balanced(s4));
    System.out.println(balanced(s5));

  }
}
