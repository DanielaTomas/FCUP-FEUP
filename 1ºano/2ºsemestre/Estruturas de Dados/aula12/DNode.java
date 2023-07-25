public class DNode<T> {
   private T value;       // Valor guardado no no
   private DNode<T> prev; // Referencia para o no anterior da lista
   private DNode<T> next; // Referencia para o proximo no da lista

   // Construtor
   DNode(T v, DNode<T> p, DNode<T> n) {
      value = v;
      prev = p;
      next = n;
   }

   // Getters e Setters
   public T getValue() { return value; }
   public DNode<T> getPrev()  { return prev; }
   public DNode<T> getNext()  { return next; }
   public void setValue(T v) { value=v; }
   public void setPrev(DNode<T> p) { prev = p; }
   public void setNext(DNode<T> n) { next = n; }
}
