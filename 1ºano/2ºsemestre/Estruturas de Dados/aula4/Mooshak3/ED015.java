import java.util.Scanner;
class Sopa {
  char[][] sopa;
  String word;
  int rows;
  int cols;
  char[][] output;

  Sopa(int rows, int cols) {
     this.rows = rows;
     this.cols = cols;
     sopa = new char[rows][cols];
     output = new char[rows][cols];
  }
  void readsopa(Scanner ler) {
     for (int i=0; i < rows; i++) {
        String buf = ler.next();
        for (int j=0; j < cols; j++) {
           sopa[i][j] = buf.charAt(j);
           output[i][j] = '.';
        }
     }
  }
  public void test(String word, int y, int x, int incy, int incx) {
     // Verificar se palavra esta nesta posicao e direcao
   	 for(int i=0, yy=y, xx=x; i < word.length(); i++, yy+=incy, xx+=incx)
	     if (!(yy >= 0 && yy < rows && xx >= 0 && xx < cols) || sopa[yy][xx] != word.charAt(i))
		   return;
	   // Palavra descoberta, marcar no tabuleiro
	   for(int i = 0, yy = y, xx = x; i < word.length(); i++, yy += incy, xx += incx)
	     output[yy][xx] = sopa[yy][xx];
  }
  public void search(String word) {
  for(int i=0; i < rows; i++)
   for(int j=0; j < cols; j++)
       if(sopa[i][j] == word.charAt(0)) {
         test(word, i, j, 0, 1);  // esquerda para direita
         test(word, i, j, 0, -1); // direita para esquerda
         test(word, i, j, 1, 0);  // cima para baixo
         test(word, i, j, -1, 0); // baixo para cima
       }
   }
   public void show() {
      for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
          System.out.print(output[i][j]);
        }
        System.out.println();
      }
  }
}
public class ED015 {
   public static void main (String[] arg) {
      Scanner ler = new Scanner(System.in);
      int rows = ler.nextInt();
      int cols = ler.nextInt();
      for(int i=0; rows != 0 && cols != 0; i++) {
        ler.nextLine();
        System.out.println("Input #" + (i+1));
        Sopa sopa = new Sopa(rows,cols);
        sopa.readsopa(ler);
        ler.nextLine();
        int nwords = ler.nextInt();
        ler.nextLine();
        for(int j=0; j < nwords; j++) {
         String word = ler.next();
         sopa.search(word);
        }
        sopa.show();
        rows = ler.nextInt();
        cols = ler.nextInt();
     }
  }
}
