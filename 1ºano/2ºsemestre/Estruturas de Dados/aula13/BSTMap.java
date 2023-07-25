import java.util.LinkedList;

// K e o tipo da chave (key) e V o tipo do valor (value)
// O tipo K tem de implementar o interface Comparable
// (ou te-lo herdado de uma super classe).
public class BSTMap<K extends Comparable<? super K>,V> {
   private BSTMapNode<K,V> root; // raiz da arvore

   // Construtor
   BSTMap() {
      root = null;
   }

   // Getter e Setter para a raiz
   public BSTMapNode<K,V> getRoot() {return root;}
   public void setRoot(BSTMapNode<K,V> r) {root = r;}

   // Verificar se o dicionario esta vazio
   public boolean isEmpty() {
      return root == null;
   }

   // Limpa o dicionario (torna-o vazia)
   public void clear() {
      root = null;
   }

   // --------------------------------------------------------
   // Tamanho do dicionario (numero de chaves guardadas)
   public int size() {
      return size(root);
   }

   private int size(BSTMapNode<K,V> n) {
      if (n == null) return 0;
      return 1 + size(n.getLeft()) + size(n.getRight());
   }

   // --------------------------------------------------------
   // Devolver o valor associado a uma chave (ou null caso nao exista)
   public V get(K key) {
      return get(root, key);
   }

   private V get(BSTMapNode<K,V> n, K key) {
      if (n==null) return null;
      if (key.compareTo(n.getKey()) < 0) return get(n.getLeft(), key);
      if (key.compareTo(n.getKey()) > 0) return get(n.getRight(), key);
      return n.getValue(); // se nao e menor ou maior, e porque e igual
   }

   // --------------------------------------------------------
   // Adicionar par (chave,valor) ao dicionario
   // Se chave ja existir, substitui o valor antigo pelo novo
   public void put(K key, V value) {
      root = put(root, key, value);
   }

   private BSTMapNode<K,V> put(BSTMapNode<K,V> n, K key, V value) {
      if (n==null)
         return new BSTMapNode<K,V>(key, value, null, null);
      else if (key.compareTo(n.getKey()) < 0)
         n.setLeft(put(n.getLeft(), key, value));
      else if (key.compareTo(n.getKey()) > 0)
         n.setRight(put(n.getRight(), key, value));
      else
         n.setValue(value);
      return n;
   }

   // --------------------------------------------------------
   // Remover uma chave do dicionario
   // Devolve true se conseguiu remover, false caso contrario
   public boolean remove(K key) {
      if (get(key)==null) return false;
      root = remove(root, key);
      return true;
   }

   // Assume-se que elemento existe (foi verificado antes)
   private BSTMapNode<K,V> remove(BSTMapNode<K,V> n, K key) {
      if (key.compareTo(n.getKey()) < 0)
         n.setLeft(remove(n.getLeft(), key));
      else if (key.compareTo(n.getKey()) > 0)
         n.setRight(remove(n.getRight(), key));
      else if (n.getLeft() == null) // Nao tem filho esquerdo
         n = n.getRight();
      else if (n.getRight() == null) // Nao tem filho direito
         n = n.getLeft();
      else { // Dois fihos: ir buscar maximo do lado esquerdo
         BSTMapNode<K,V> max = n.getLeft();
         while (max.getRight() != null) max = max.getRight();
         n.setKey(max.getKey());     // Substituir chave removida
         n.setValue(max.getValue()); // Substituir valor removido
         // Apagar valor que foi para lugar do removido
         n.setLeft(remove(n.getLeft(), max.getKey()));
      }
      return n;
   }

   // --------------------------------------------------------
   // Devolver lista ligada das chaves (usando listas do Java)
   public LinkedList<K> keys() {
      LinkedList<K> list = new LinkedList<K>();
      keys(root, list);
      return list;
   }

   private void keys(BSTMapNode<K,V> n, LinkedList<K> l) {
      if (n==null) return;
      keys(n.getLeft(), l);
      l.addLast(n.getKey());
      keys(n.getRight(), l);
   }

}
