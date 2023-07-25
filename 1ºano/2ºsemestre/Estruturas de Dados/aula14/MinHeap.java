import java.util.Comparator;

public class MinHeap<T> {
   private T[] data; // Guardar elementos entre posicoes 1 e size
   private int size; // Quantidade de elementos
   private Comparator<T> comparator; // Comparador (opcional)

   // Construtor (heap com uma dada capacidade)
   @SuppressWarnings("unchecked") // Por causa da criaÃ§Ã£o de um array de genericos
   MinHeap(int capacity) {
      data = (T[]) new Object[capacity+1]; // Java proibe directamente array de genericos, dai o cast
      size = 0;
      comparator = null;
   }

   // Construtor (heap com uma dada capacidade e comparador customizado)
   MinHeap(int capacity, Comparator<T> comp) {
      this(capacity); // Chama o construtor padrÃ£o
      comparator = comp;
   }

   // Numero de elementos guardados na heap
   public int size() {
      return size;
   }

   // Heap vazia?
   public boolean isEmpty() {
      return (size==0);
   }

   // ---------------------------------------------------------------------

   // Inserir um elemento na heap
   public void insert(T value) {
      if (size + 1 >= data.length) throw new RuntimeException("Heap is full");
      size++;
      data[size] = value;
      upHeap(size);
   }

   // Devolver (sem retirar) elemento minimo
   public T min() {
      if (isEmpty()) return null;
      return data[1];
   }

   // Remover e devolver elemento minimo
   public T removeMin() {
      if (isEmpty()) return null;
      T min = data[1];
      data[1] = data[size];
      data[size] = null; // Para ajudar no garbage collection
      size--;
      downHeap(1);
      return min;
   }

   // ---------------------------------------------------------------------

   // Fazer um elemento subir na heap ate a sua posiÃ§Ã£o
   private void upHeap(int i) {
      while (i>1 && smaller(i, i/2)) { // Enquanto o elemento for menor que o pai e nÃ£o estiver na raiz
         swap(i, i/2);                 // Trocar com o pai
         i = i/2;
      }
   }

   // Fazer um elemento descer na heap ate a sua posiÃ§Ã£o
   private void downHeap(int i) {
      while (2*i <= size) { // Enquanto estiver dento dos limites da heap
         int j = i*2;
         if (j<size && smaller(j+1, j)) j++; // Escolher filho mais pequeno (posicao i*2 ou i*2+1)
         if (smaller(i, j)) break;           // Se no ja e menor que filho mais pequeno, terminamos
         swap(i, j);                         // Caso contrario, trocar com filho mais pequeno
         i = j;
      }
   }

   // Saber o elemento na posiÃ§Ã£o i e menor que o elemento na posiÃ§Ã£o j
   @SuppressWarnings("unchecked") // Para que o java nÃ£o se queixe do cast que diz que elementos sÃ£o comparaveis
   private boolean smaller(int i, int j) {
      if (comparator == null) // Se nÃ£o existe comparador usar comparaÃ§Ã£o natural
         return ((Comparable<? super T>) data[i]).compareTo(data[j]) < 0;
      else // Se existe comparador... usa-lo
         return comparator.compare(data[i], data[j]) < 0;
   }

   // Trocar elementos entre as posiÃ§Ãµes i e j
   private void swap(int i, int j) {
      T tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
   }

}
