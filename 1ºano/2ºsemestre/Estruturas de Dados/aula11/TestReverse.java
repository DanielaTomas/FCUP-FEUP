import java.util.Arrays;

public class TestReverse {

   // Inverter array v entre posicoes start e end
   static void reverse(int v[], int start, int end) {
      if (start >= end) return;     // Caso base: array de tamanho < 2
      int tmp = v[start];         // Trocar primeiro com ultimo
      v[start] = v[end];
      v[end] = tmp;
      reverse(v, start+1, end-1); // Chamada recursiva para o resto
   }

   // -----------------------------------------------------------

   static boolean capicua(int v[], int start, int end) {
     if (start >= end) return true;
     return ((v[start] == v[end]) && capicua(v, start+1, end-1));
   }

   public static void main(String[] args) {
      int v[] = {2,4,6,8,10}; // Inicializacao de array

      System.out.println("Antes  do reverse: " + Arrays.toString(v));
      reverse(v, 0, v.length-1);
      System.out.println("Depois do reverse: " + Arrays.toString(v));
      int v1[] = {1,2,3,2,1};
      System.out.println("Capicua {1,2,3,2,1}: " + capicua(v1,0,4));
      int v2[] = {5,8,8,5};
      System.out.println("Capicua {5,8,8,5}: " + capicua(v2,0,3));
      int v3[] = {1,2,3,1};
      System.out.println("Capicua {1,2,3,1}: " + capicua(v3,0,3));
      int v4[] = {5,8,7,5};
      System.out.println("Capicua {5,8,7,5}: " + capicua(v4,0,3));
   }
}
