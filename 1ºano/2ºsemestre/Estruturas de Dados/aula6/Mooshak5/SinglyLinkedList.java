public class SinglyLinkedList<T> {
   private Node<T> first;    // Primeiro no da lista
   private int size;         // Tamanho da lista

   // Construtor (cria lista vazia)
   SinglyLinkedList() {
      first = null;
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
   // Adiciona v ao inicio da lista
   public void addFirst(T v) {
      Node<T> newNode = new Node<T>(v, first);
      first = newNode;
      size++;
   }
   // Adiciona v ao final da lista
   public void addLast(T v) {
      Node<T> newNode = new Node<T>(v, null);
      if (isEmpty()) {
         first = newNode;
      } else {
         Node<T> cur = first;
         while (cur.getNext() != null)
            cur = cur.getNext();
         cur.setNext(newNode);
      }
      size++;
   }
   // Retorna o primeiro valor da lista (ou null se a lista for vazia)
   public T getFirst() {
      if (isEmpty()) return null;
      return first.getValue();
   }
   // Retorna o ultimo valor da lista (ou null se a lista for vazia)
   public T getLast() {
      if (isEmpty()) return null;
      Node<T> cur = first;
      while (cur.getNext() != null)
         cur = cur.getNext();
      return cur.getValue();
   }
   // Remove o primeiro elemento da lista (se for vazia nao faz nada)
   public void removeFirst() {
      if (isEmpty()) return;
      first = first.getNext();
      size--;
   }
   // Remove o ultimo elemento da lista (se for vazia nao faz nada)
   public void removeLast() {
      if (isEmpty()) return;
      if (size == 1) {
         first = null;
      } else {
         // Ciclo com for e uso de de size para mostrar alternativa ao while
         Node<T> cur = first;
         for (int i=0; i<size-2; i++)
            cur = cur.getNext();
         cur.setNext(cur.getNext().getNext());
      }
      size--;
   }
   // Devolve elemento numa dada posição
   public T get(int pos) {
     Node<T> cur = first;
     if(isEmpty()) return null;
     for(int i=0; i < size; i++) {
       if(cur.getValue() != null) {
        if(i == pos) return cur.getValue();
        cur = cur.getNext();
       }
     }
     return null;
   }
   // Remove elemento numa dada posição
   public T remove(Integer pos) {
      if(pos < 0 || size <= pos || isEmpty()) {
         return null;
      }
      else if(pos == 0) {
         T val = getFirst();
         removeFirst();
         return val;
      }
      else if(pos == (size - 1)) {
         T val = getLast();
         removeLast();
         return val;
      }
      else {
         Node<T> cur = first;
         for(int i = 0; i < pos-1; i++) {
            cur = cur.getNext();
         }
         T val = cur.getNext().getValue();
         cur.setNext(cur.getNext().getNext());
         size--;
         return val;
      }
   }
   // Cópia de uma lista
   public SinglyLinkedList<T> copy() {
    SinglyLinkedList<T> list = new SinglyLinkedList<>();
    Node<T> cur = first;
    for(int i=0; i < size; i++) {
      list.addLast(cur.getValue());
      cur = cur.getNext();
    }
    return list;
   }
   // Duplica cada elemento da lista
   public void duplicate() {
    SinglyLinkedList<T> cp = copy();
    Node<T> cur = cp.first;
    if(this.isEmpty()) return;
    this.first.setNext(null);
    this.removeFirst();
    size = 0;
    for(int i=0; i < cp.size; i++) {
     this.addLast(cur.getValue());
     this.addLast(cur.getValue());
     cur = cur.getNext();
    }
   }
   // conta e devolve o número de ocorrências do valor value
   public int count(T value) {
     Node<T> cur = first;
     int count = 0;
     while(cur != null) {
      if(value.equals(cur.getValue()))
       count++;
      cur = cur.getNext();
     }
     return count;
   }

   //Remover nós pares
   public void removeEven() {
     if(size < 0) return;
     if(size == 1) {
       first = null;
       size--;
     }
     else {
       Node<T> cur = first;
       for(int i = 0; cur != null && cur.getNext() != null; i++) {
         if(i == 0) {
           first = first.getNext();
         }
         else if(i % 2 != 0) {
           cur.setNext(cur.getNext().getNext());
           i++;
         }
         size--;
         cur = cur.getNext();
       }
     }
   }
   // Converte a lista para uma String
   public String toString() {
      String str = "{";
      Node<T> cur = first;
      while (cur != null) {
         str += cur.getValue();
         cur = cur.getNext();
         if (cur != null) str += ",";
      }
      str += "}";
      return str;
   }
}
