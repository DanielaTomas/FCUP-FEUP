// -----------------------------------------------------------
// Estruturas de Dados 2020/2021 (CC1007) - DCC/FCUP
// http://www.dcc.fc.up.pt/~pribeiro/aulas/edados2021/
// -----------------------------------------------------------
// Teste da MinHeap
// Ultima alteraÃ§Ã£o: 18/05/2018
// -----------------------------------------------------------

import java.util.Comparator;

public class TestMinHeap {
   public static void main(String[] args) {

      // Criar uma heap h (para inteiros) com capacidade para 100 elementos
      MinHeap<Integer> h1 = new MinHeap<>(100);

      // Criar um array com 10 inteiros
      int[] v1 = {10,4,3,12,9,1,7,11,5,4};

      // Inserir na heap h todos os elementos do array v1[]
      for (int i=0; i<v1.length; i++)
         h1.insert(v1[i]);

      // Retirar um a um os elementos e imprimir (empates sÃ£o resolvidos "aleatoriamente")
      for (int i=0; i<v1.length; i++)
         System.out.print(h1.removeMin() + " ");
      System.out.println();

      // ----------------------------------------------

      // Criar uma heap h (para strings) com capacidade para 100 elementos
      MinHeap<String> h2 = new MinHeap<>(100);

      // Criar um array com 5 strings
      String[] v2 = {"bbb", "aaaaa", "ee", "cccc", "d"};

      // Inserir na heap h todos os elementos do array v2[]
      for (int i=0; i<v2.length; i++)
         h2.insert(v2[i]);

      // Retirar um a um os elementos e imprimir (ordem natural e alfabetica)
      for (int i=0; i<v2.length; i++)
         System.out.print(h2.removeMin() + " ");
      System.out.println();

      // ----------------------------------------------

      // Criar uma heap h (para strings) com comparador customizado (definido em baixo)
      MinHeap<String> h = new MinHeap<>(100, new LengthComparator());
      // Inserir na heap h todos os elementos do array v2[] criado anteriormento
      for (int i=0; i<v2.length; i++)
         h.insert(v2[i]);

      // Retirar um a um os elementos e imprimir (por ordem crescente de tamanho)
      for (int i=0; i<v2.length; i++)
         System.out.print(h.removeMin() + " ");
      System.out.println();
   }
}

// ----------------------------------------------------------------------------------

// Comparador customizado para strings (comparar tamanho)
class LengthComparator implements Comparator<String> {
   // Assumindo que nÃ£o sÃ£o nulas
   public int compare(String a, String b) {
      // Conseguem perceber porque podemos subtrair?
      // Quando e que a subtraÃ§Ã£o da um numero negativo? E positivo? E zero?
      return a.length() - b.length();
   }
}
