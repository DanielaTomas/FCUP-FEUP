import java.util.Scanner;
class Sopa {
  char[][] sopa;
  String word;
  int rows;
  int cols;
  int[] posicao = new int[4];
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
  private void firstposition(int iinicial, int jinicial) {
      posicao[0] = iinicial;
      posicao[1] = jinicial;
  }
  private void lastposition(int ifinal, int jfinal) {
      posicao[2] = ifinal;
      posicao[3] = jfinal;
  }
  private void copy() {
     int iinicial = posicao[0];
     int jinicial = posicao[1];
     int ifinal = posicao[2];
     int jfinal = posicao[3];
     for(int i=iinicial; i <= ifinal; i++) {
       for(int j=jinicial; j <= jfinal; j++) {
         output[i][j] = sopa[i][j];
      }
    }
  }
  public boolean horizontal(String word, int p, int i, int j) {
     int p1 = 0;
         if(p == -1) p1 = j-1;
         else if (p == 1) p1 = j+1;
         for(int l=1; l < word.length(); l++) {
           if(p1 < cols && p1 >= 0) {
            //System.out.println(sopa[p1][j]  + "---" + word.charAt(l));
            if(sopa[i][p1] == word.charAt(l)) {
             lastposition(i,p1);
             if(p == -1) p1--;
             else if (p == 1) p1++;
            }
            else {
             firstposition(-1,-1);
             lastposition(-1,-1);
             break;
            }
          }
        }
        //System.out.println("posicao " + posicao[0]);
        //System.out.println("posicao " + posicao[1]);
        //System.out.println("posicao " + posicao[2]);
        //System.out.println("posicao " + posicao[3]);
        if(posicao[0] != -1 && posicao[1] != -1 && posicao[2] != -1 && posicao[3] != -1) return true;
       return false;
   }
   public boolean vertical(String word, int p, int i, int j) {
      int p1 = 0;
          if(p == -1) p1 = i-1;
          else if (p == 1) p1 = i+1;
          for(int l=1; l < word.length(); l++) {
            if (p1 < rows && p1 >= 0) {
             //System.out.println(sopa[p1][j]  + "---" + word.charAt(l));
             if(sopa[p1][j] == word.charAt(l)) {
              lastposition(i,p1);
              if(p == -1) p1--;
              else if (p == 1) p1++;
             }
             else {
              firstposition(-1,-1);
              lastposition(-1,-1);
              break;
             }
           }
         }
         //System.out.println("posicao " + posicao[0]);
         //System.out.println("posicao " + posicao[1]);
         //System.out.println("posicao " + posicao[2]);
         //System.out.println("posicao " + posicao[3]);
        if(posicao[0] != -1 && posicao[1] != -1 && posicao[2] != -1 && posicao[3] != -1) return true;
      return false;
    }
  public void search(String word) {
     for(int i=0; i < rows; i++) {
       for(int j=0; j < cols; j++) {
         if(sopa[i][j] == word.charAt(0))   {
          firstposition(i,j);
          lastposition(-1,-1);
          if(horizontal(word,1,i,j)) { //esquerda para direita
           copy();
          }
          else if(horizontal(word,-1,i,j)) { //direita para esquerda
           copy();
          }
          else if(vertical(word,1,i,j)) { //cima para baixo
           copy();
          }
          else if(vertical(word,-1,i,j)) { //baixo para cima
           copy();
          }
         }
         if(posicao[0] != -1 && posicao[1] != -1 && posicao[2] != -1 && posicao[3] != -1) {
          i = rows;
          posicao[0] = -1; posicao[1] = -1; posicao[2] = -1; posicao[3] = -1;
          break;
         }
        }
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
public class tentativaED015 {
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
