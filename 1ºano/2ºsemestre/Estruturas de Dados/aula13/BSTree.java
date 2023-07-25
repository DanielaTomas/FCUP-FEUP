// O tipo T tem de implementar o interface Comparable
// (ou te-lo herdado de uma super classe).
public class BSTree<T extends Comparable<? super T>> {
   private BSTNode<T> root; // raiz da arvore

   // Construtor
   BSTree() {
      root = null;
   }
   // Getter e Setter para a raiz
   public BSTNode<T> getRoot() {return root;}
   public void setRoot(BSTNode<T> r) {root = r;}

   // Verificar se arvore esta vazia
   public boolean isEmpty() {
      return root == null;
   }

   // Limpa a arvore (torna-a vazia)
   public void clear() {
      root = null;
   }

   // Numero de nos da arvore
   public int numberNodes() {
      return numberNodes(root);
   }

   private int numberNodes(BSTNode<T> n) {
      if (n == null) return 0;
      return 1 + numberNodes(n.getLeft()) + numberNodes(n.getRight());
   }

   // O elemento value esta contido na arvore?
   public boolean contains(T value) {
      return contains(root, value);
   }

   private boolean contains(BSTNode<T> n, T value) {
      if (n == null) return false;
      if (value.compareTo(n.getValue()) < 0) // menor? sub-arvore esquerda
         return contains(n.getLeft(), value);
      if (value.compareTo(n.getValue()) > 0) // maior? sub-arvore direita
         return contains(n.getRight(), value);
      return true; // se nao e menor ou maior, e porque e igual
   }

   // Adicionar elemento a uma arvore de pesquisa
   // Devolve true se conseguiu inserir, false caso contrario
   public boolean insert(T value) {
      if (contains(value)) return false;
      root = insert(root, value);
      return true;
   }

   private BSTNode<T> insert(BSTNode<T> n, T value) {
      if (n==null)
         return new BSTNode<T>(value, null, null);
      else if (value.compareTo(n.getValue()) < 0)
         n.setLeft(insert(n.getLeft(), value));
      else if (value.compareTo(n.getValue()) > 0)
         n.setRight(insert(n.getRight(), value));
      return n;
   }

   // Remover elemento de uma arvore de pesquisa
   // Devolve true se conseguiu remover, false caso contrario
   public boolean remove(T value) {
      if (!contains(value)) return false;
      root = remove(root, value);
      return true;
   }

   // Assume-se que elemento existe (foi verificado antes)
   private BSTNode<T> remove(BSTNode<T> n, T value) {
      if (value.compareTo(n.getValue()) < 0)
         n.setLeft(remove(n.getLeft(), value));
      else if (value.compareTo(n.getValue()) > 0)
         n.setRight(remove(n.getRight(), value));
      else if (n.getLeft() == null) // Nao tem filho esquerdo
         n = n.getRight();
      else if (n.getRight() == null) // Nao tem filho direito
         n = n.getLeft();
      else { // Dois fihos: ir buscar maximo do lado esquerdo
         BSTNode<T> max = n.getLeft();
         while (max.getRight() != null) max = max.getRight();
         n.setValue(max.getValue()); // Substituir valor removido
         // Apagar valor que foi para lugar do removido
         n.setLeft(remove(n.getLeft(), max.getValue()));
      }
      return n;
   }

   // Altura da arvore
   public int depth() {
      return depth(root);
   }

   private int depth(BSTNode<T> n) {
      if (n == null) return -1;
      return 1 + Math.max(depth(n.getLeft()), depth(n.getRight()));
   }

   // Imprimir arvore em PreOrder
   public void printPreOrder() {
      System.out.print("PreOrder:");
      printPreOrder(root);
      System.out.println();
   }

   private void printPreOrder(BSTNode<T> n) {
      if (n==null) return;
      System.out.print(" " + n.getValue() );
      printPreOrder(n.getLeft());
      printPreOrder(n.getRight());
   }

   // Imprimir arvore em InOrder
   public void printInOrder() {
      System.out.print("InOrder:");
      printInOrder(root);
      System.out.println();
   }

   private void printInOrder(BSTNode<T> n) {
      if (n==null) return;
      printInOrder(n.getLeft());
      System.out.print(" " + n.getValue());
      printInOrder(n.getRight());
   }

   // Imprimir arvore em PostOrder
   public void printPostOrder() {
      System.out.print("PostOrder:");
      printPostOrder(root);
      System.out.println();
   }

   private void printPostOrder(BSTNode<T> n) {
      if (n==null) return;
      printPostOrder(n.getLeft());
      printPostOrder(n.getRight());
      System.out.print(" " + n.getValue());
   }

   // Imprimir arvore numa visita em largura (usando TAD Fila)
   public void printBFS() {
      System.out.print("BFS:");

      MyQueue<BSTNode<T>> q = new LinkedListQueue<BSTNode<T>>();
      q.enqueue(root);
      while (!q.isEmpty()) {
         BSTNode<T> cur = q.dequeue();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.enqueue(cur.getLeft());
            q.enqueue(cur.getRight());
         }
      }
      System.out.println();
   }

   // Imprimir arvore numa visita em largura (usando TAD Pilha)
   public void printDFS() {
      System.out.print("DFS:");

      MyStack<BSTNode<T>> q = new LinkedListStack<BSTNode<T>>();
      q.push(root);
      while (!q.isEmpty()) {
         BSTNode<T> cur = q.pop();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.push(cur.getLeft());
            q.push(cur.getRight());
         }
      }
      System.out.println();
   }

   //ED208 - min e max de uma árvore
   public T minValue() {
      return minValue(root);
   }
   public T minValue(BSTNode<T> min) {
      BSTNode<T> cur = null;
      while(min != null) {
        cur = min;
        min = min.getLeft();
      }
      return cur.getValue();
   }
   public T maxValue() {
      return maxValue(root);
   }
   public T maxValue(BSTNode<T> max) {
      BSTNode<T> cur = null;
      while(max != null) {
        cur = max;
        max = max.getRight();
      }
      return cur.getValue();
   }

   //ED210
   public boolean valid() {
      return valid(root);
   }
   private boolean valid(BSTNode<T> n) {
     if(n == null) return true;
     if(!verify(n.getRight(),n.getValue(),0)) return false;
     if(!verify(n.getLeft(),n.getValue(),1)) return false;

     return valid(n.getLeft()) && valid(n.getRight());
   }
   private boolean verify(BSTNode<T> n, T value, int i) {
    if(n == null) return true;
    //System.out.println(value + " " + n.getValue());
    if(i == 0)
      if(n.getValue().compareTo(value) <= 0) return false;
    else if(i == 1)
      if(n.getValue().compareTo(value) >= 0) return false;

    return verify(n.getLeft(),value,i) && verify(n.getRight(),value,i);
  }
  //ED209
  public int countBetween(T a, T b) {
    return countBetween(root,a,b);
  }
  private int countBetween(BSTNode<T> n, T a, T b) {
    if(n == null) return 0;
    int soma = 0;
    if(n.getValue().compareTo(a) >= 0 && n.getValue().compareTo(b) <= 0) soma = 1;
    return soma + countBetween(n.getLeft(),a,b) + countBetween(n.getRight(),a,b);
  }
}
