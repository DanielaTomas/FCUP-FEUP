import java.util.Scanner;
public class ED216 {
  static int rows;
  static int cols;
  static int max;
  static int seg;
  public static void testar(char[][] matrix, int y, int x, int incy, int incx) {
     int cont = 0;
     for(int i = 0, yy = y, xx = x; yy < rows && xx < cols; i++, yy += incy, xx += incx) {
       if(matrix[yy][xx] == '#') cont++;
       else break;
     }
     if(cont > max) {
       max = cont;
       seg = 1;
     }
     else if(cont == max) seg++;
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    rows = in.nextInt();
    cols = in.nextInt();
    char[][] matrix = new char[50][50];
    for(int i = 0; i < rows; i++)
      matrix[i] = in.next().toCharArray();

    max = 0; seg = 1;
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        if(matrix[i][j] == '#') {
          testar(matrix,i,j,0,1);
          testar(matrix,i,j,1,0);
        }
    System.out.println(max + " " + seg);
  }
}
