public class BSTMapNode<K extends Comparable<? super K>, V> {
   private K key;                 // chave
   private V value;               // valor
   private BSTMapNode<K,V> left;  // Filho esquerdo
   private BSTMapNode<K,V> right; // Filho direito

   // Construtor
   BSTMapNode(K k, V v, BSTMapNode<K,V> l, BSTMapNode<K,V> r) {
      key = k;
      value = v;
      left = l;
      right = r;
   }

   // Getters e Setters
   public K getKey() {return key;}
   public V getValue() {return value;}
   public BSTMapNode<K,V> getLeft() {return left;}
   public BSTMapNode<K,V> getRight() {return right;}
   public void setKey(K k) {key = k;}
   public void setValue(V v) {value = v;}
   public void setLeft(BSTMapNode<K,V> l) {left = l;}
   public void setRight(BSTMapNode<K,V> r) {right = r;}
}
