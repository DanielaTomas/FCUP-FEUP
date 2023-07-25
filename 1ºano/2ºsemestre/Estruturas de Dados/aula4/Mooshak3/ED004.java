/* -----------------------------------
   Estruturas de Dados 2020/2021
   Jogo do Galo [ED004]
   Pedro Ribeiro (DCC/FCUP)
   ----------------------------------- */

import java.util.Scanner;

class Game {
   private int n;       // tamanho do tabuleiro
   private char m[][];  // matriz que representa o tabuleiro

   // Construtor que recebe como argumento o tamanho n
   Game(int n) {
      this.n = n;
      m = new char[n][n];
   }

   // Leitura de input para o tabuleiro
   void read(Scanner in) {
      for (int i=0; i<n; i++) {
         String buf = in.next();
         for (int j=0; j<n; j++)
            m[i][j] = buf.charAt(j);
	 }
   }

   // Escreve mensagem dizendo que jogador player ganhou
   void win(char player) {
      System.out.println("Ganhou o " + player);
      System.exit(0);
   }

   // Verifica se a linha que comeca em (x,y) e com incrementos
   // incx e incy tem todas as posicoes preenchidas com o mesmo caracter
   void verify(int y, int x, int incy, int incx) {
      if (m[y][x] == '.') return;
      for (int i=0, yy=y, xx=x; i<n; i++, yy+=incy, xx+=incx)
         if (m[y][x] != m[yy][xx]) return;
      win(m[y][x]);
   }

   // Devolve true se o tabuleiro estiver cheio ou false caso contrario
   boolean finished() {
      for (int i=0; i<n; i++)
         for (int j=0; j<n; j++)
            if (m[i][j] == '.') return false;
      return true;
   }

   // Verifica o estado do jogo
   void check() {
      for (int i=0; i<n; i++) verify(i, 0, 0, 1); // Linhas
      for (int j=0; j<n; j++) verify(0, j, 1, 0); // Colunas
      verify(0, 0, 1, 1);                         // Diagonal 1
      verify(0, n-1, 1, -1);                      // Diagonal 2

      if (!finished()) System.out.println("Jogo incompleto");
      else             System.out.println("Empate");

   }
}

public class ED004 {
   public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      Game g = new Game(n);
      g.read(in);
      g.check();
   }
}
