import java.util.Scanner;

class Game {
    final char DEAD  = '.';  // Constante que indica uma celula morta
    final char ALIVE = 'O';  // Constante que indica uma celula viva
    private int rows, cols;  // Numero de linhas e colunas
    private char m[][];      // Matriz para representar o estado do jogo

    // Construtor: inicializa as variaveis tendo em conta a dimensao dada
    Game(int r, int c) {
	     rows = r;
	     cols = c;
	     m = new char[r][c];
    }
    // Metodo para ler o estado inicial para a matriz m[][]
    public void read(Scanner in) {
	     for (int i=0; i<rows; i++)
	      m[i] = in.next().toCharArray();
    }
    // Metodo para escrever a matriz m[][]
    public void write() {
       for(int i=0; i<rows; i++) {
         for(int j=0; j<cols; j++) {
           System.out.print(m[i][j]);
         }
         System.out.println();
       }
    }
    // Deve devolver o numero de celulas vivas que sao vizinhas de (y,x)
    private int countAlive(int y, int x) {
	     int count = 0;
       for(int i=y-1; i<=y+1; i++) {
        for(int j=x-1; j<=x+1; j++) {
          if((i==y && j==x) || (x==0 && j==x-1) || (y==0 && i==y-1) || (x==cols-1 && j==x+1) || (y==rows-1 && i==y+1)) continue;
          else if(m[i][j] == 'O') count++;
        }
       }
	     return count;
    }
    // Deve fazer uma iteracao: cria nova geracao a partir da actual
    public void iterate() {
       char m2[][] = new char[rows][cols];
       for(int y=0; y<rows; y++) {
        for(int x=0; x<cols; x++) {
         if(m[y][x] == 'O') {
          if(countAlive(y,x) == 2 || countAlive(y,x) == 3) m2[y][x] = 'O';
          else m2[y][x] = '.';
        }
        else if(m[y][x] == '.') {
         if(countAlive(y,x) == 3) m2[y][x] = 'O';
         else m2[y][x] = '.';
       }
       }
      }
      for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
          m[i][j] = m2[i][j];
        }
      }
    }
}

public class ED088 {
    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);

	int rows = in.nextInt();
	int cols = in.nextInt();
	int n    = in.nextInt();
	Game g   = new Game(rows, cols);
	g.read(in);
  for(int i=0; i<n; i++) {
   g.iterate();
  }
  g.write();
	 //int count = g.countAlive(0,0);
   //System.out.println(count);
  }
}
