import java.util.Scanner;

public class TestED247 {
    public static void main(String[] args) {
	IntSet s1 = new BooleanArrayIntSet(100);
	IntSet s2 = new BooleanArrayIntSet(100);

	for (int i=1; i<=5; i++)
	    s1.add(i);
	System.out.println("s1 = " + s1 + " | tamanho = " + s1.size());

	for (int i=3; i<=7; i++)
	    s2.add(i);
	System.out.println("s2 = " + s2 + " | tamanho = " + s2.size());

	IntSet s3 = s1.intersection(s2);
	System.out.println("s3 = " + s3 + " | tamanho = " + s3.size());

	IntSet s4 = s2.intersection(s1);
	System.out.println("s4 = " + s4 + " | tamanho = " + s4.size());

	System.out.println("s1.equals(s2) = " + s1.equals(s2));
	System.out.println("s3.equals(s4) = " + s3.equals(s4));

  IntSet s5 = new BooleanArrayIntSet(1000);
  Scanner ler = new Scanner(System.in);
  for(int i=1; i <= 1000; i++) {
   s5.add(ler.nextInt());
  }
  System.out.println("s5 = " + s5 + " | tamanho = " + s5.size());
 }
}
