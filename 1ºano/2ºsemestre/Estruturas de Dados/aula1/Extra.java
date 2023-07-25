public class Extra {
 static void losango(int n) {
  int i,espacos,cardinais;
  cardinais=1;
  if(n%2!=0) { //impar
   n-=1;
   //parte de cima losango
   for(espacos=n/2; espacos>0; espacos--) {
    //espacos
    for(i=1; i<=espacos; i++) {
     System.out.print(" ");
    }
    //cardinais
    for(i=1; i<=cardinais; i++) {
     System.out.print("#");
    }
   cardinais+=2;
   System.out.print("\n");
  }
  //parte de baixo losango
   for( ; cardinais>0; cardinais-=2) {
    //espacos
    for(i=1; i<=espacos; i++) {
     System.out.print(" ");
    }
   //cardinais
   for(i=1; i<=cardinais; i++) {
    System.out.print("#");
   }
   espacos++;
   System.out.print("\n");
  }
 }
}
static void fatores(int n) {
 int i,num;
 num=n;
  System.out.print(n + " = ");
  for (i=2; i<=n; i++) {
    if(num%i==0) {
    System.out.print(i);
    num/=i;
    i=n;
   }
  }
  for(i=2; i<=n; i++) {
   for( ; num%i==0; num/=i) {
     System.out.print(" * " + i);
   }
  }
  System.out.println();
}
static void count(String s, char c) {
 int size,cont=0;
 char position;
 size=s.length();
 for(int i=0; i<size; i++) {
   position=s.charAt(i);
  if(position==c)
  cont++;
 }
 System.out.println(cont);
}
static void lsystem(int n) {
 String c,s = "A";
 char position;
 int size;
 for(int i=1; i<=n; i++) {
  if(i==1) {
   System.out.println('A');
  }
  else {
   size=s.length();
   c=s;
   s="0";
   for(int j=0; j<size; j++) {
    position=c.charAt(j);
    if(position=='A') {
      System.out.print("AB");
      if(s=="0") {
       s="AB";
      }
      else {
       s=s+"AB";
      }
    }
    else if(position=='B'){
     System.out.print("A");
     if(s=="0") {
      s="A";
     }
     else {
      s=s+"A";
     }
    }
   }
   System.out.println();
  }
 }
}
 public static void main(String[] args) {
  losango(5);
  fatores(20);
  count("algoritmo",'o');
  lsystem(7);
 }
}
