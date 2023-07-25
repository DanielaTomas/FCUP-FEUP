public class DoublyLinkedList<T> {
   private DNode<T> first; // Primeiro no da lista
   private DNode<T> last;  // Ultimo no da lista
   private int size;       // Tamanho da lista

   // Construtor (cria lista vazia com dois nos sentinelas)
   DoublyLinkedList() {
      first = new DNode<T>(null, null, null);
      last  = new DNode<T>(null, first, null); // Antes do ultimo vem o primeiro
      first.setNext(last); // A seguir ao primeiro vem o ultimo
      size = 0;
   }

   // Retorna o tamanho da lista
   public int size() {
      return size;
   }

   // Devolve true se a lista estiver vazia ou falso caso contrario
   public boolean isEmpty() {
      return (size == 0);
   }

   // Retorna o primeiro valor da lista (ou null se a lista for vazia)
   public T getFirst() {
      if (isEmpty()) return null;
      return first.getNext().getValue();
   }

   // Retorna o ultimo valor da lista (ou null se a lista for vazia)
   public T getLast() {
      if (isEmpty()) return null;
      return last.getPrev().getValue();
   }

   // Adiciona v ao inicio da lista
   public void addFirst(T v) {
      addBetween(v, first, first.getNext());
   }

   // Adiciona v ao final da lista
   public void addLast(T v) {
      addBetween(v, last.getPrev(), last);
   }

   // Adiciona elemento entre dois nos n1 e n2
   private void addBetween(T v, DNode<T> n1, DNode<T> n2) {
      DNode<T> newNode = new DNode<T>(v, n1, n2);
      n1.setNext(newNode);
      n2.setPrev(newNode);
      size++;
   }

   // Remove o primeiro elemento da lista (se for vazia nao faz nada)
   public void removeFirst() {
       if (isEmpty()) return;
       remove(first.getNext());
   }

   // Remove o ultimo elemento da lista (se for vazia nao faz nada)
   public void removeLast() {
       if (isEmpty()) return;
      remove(last.getPrev());
   }

   // Remove um no da lista
   private void remove(DNode<T> n) {
      DNode<T> prev = n.getPrev();
      DNode<T> next = n.getNext();
      prev.setNext(next);
      next.setPrev(prev);
      size--;
   }

   // Converte a lista para uma String
   public String toString() {
      String str = "{";
      DNode<T> cur = first.getNext();
      for (int i=0; i<size; i++) {
         str += cur.getValue();
         cur = cur.getNext();
         if (cur != last) str += ",";
      }
      str += "}";
      return str;
   }
}
