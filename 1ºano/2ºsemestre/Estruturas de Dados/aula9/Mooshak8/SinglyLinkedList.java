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
   public T remove1(Integer pos) {
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
   // Conta e devolve o número de ocorrências do valor value
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
   // Inverte a lista
   public SinglyLinkedList<T> reverse() {
      SinglyLinkedList<T> novalista = new SinglyLinkedList<>();
      Node<T> cur = this.first;
      if(!this.isEmpty()) {
       while(cur != null) {
         novalista.addFirst(cur.getValue());
         cur = cur.getNext();
       }
      }
      return novalista;
   }
   // Devolve uma lista com as posições de um elemento
   public int[] occurrences(T elem) {
      Node<T> cur = this.first;
      int j = 0;
      if(!this.isEmpty()) {
       while(cur != null) {
         if(elem.equals(cur.getValue()))
           j++;
         cur = cur.getNext();
       }
      }
      if(j == 0) return null;
      int[] posicao = new int[j];
      int i = 0; j = 0; cur = this.first;
      while(cur != null) {
        if(elem.equals(cur.getValue())) {
          posicao[j] = i;
          j++;
        }
        cur = cur.getNext();
        i++;
      }
      return posicao;
   }
   // Remove elementos dae uma lista
   public void remove(SinglyLinkedList<T> toRemove){
     if(!this.isEmpty()) {
      Node<T> aux = null;
      Node<T> cur = this.first;
      while(cur != null){
        if(contains(toRemove,cur.getValue())) {
          if(aux == null) {
            first = cur.getNext();
            cur = first;
          }
          else {
            cur = cur.getNext();
            aux.setNext(cur);
          }
          size--;
        }
        else {
          aux = cur;
          cur = cur.getNext();
        }
      }
     }
   }
   // Verificar se lista contém elemento
   public boolean contains(SinglyLinkedList<T> toRemove, T val){
     Node<T> cur = toRemove.first;
     while(cur != null){
       if(val.equals(cur.getValue()))return true;
       cur = cur.getNext();
     }
     return false;
   }
   // Nova lista com elementos entre a posicao a e b
   public SinglyLinkedList<T> cut(int a, int b) {
     SinglyLinkedList<T> lista = new SinglyLinkedList<>();
     Node<T> cur = first;
     int i = 0;
     while(cur != null) {
      if(i >= a && i <= b) lista.addLast(cur.getValue());;
      cur = cur.getNext();
      i++;
     }
     return lista;
   }
   // Retira o último elemento da lista e acrescenta-o no inicio k vezes
   public void shift(int k) {
    while(k > 0) {
      Node<T> cur = first;
      Node<T> aux = null;
      while(cur != null) {
       aux = cur;
       cur = cur.getNext();
      }
      addFirst(aux.getValue());
      removeLast();
      k--;
    }
   }
   // Remove todas as ocorrências de um elemento
   public void removeAll(T value) {
     while(!this.isEmpty() && value.equals(first.getValue())) removeFirst();
     Node<T> cur = first;
     while(cur != null && cur.getNext() != null) {
       while(cur.getNext() != null && value.equals(cur.getNext().getValue())) {
         cur.setNext(cur.getNext().getNext());
         size--;
       }
       cur = cur.getNext();
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
