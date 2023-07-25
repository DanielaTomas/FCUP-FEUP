public class BTree<T> {
   private BTNode<T> root; // raiz da arvore

   // Construtor
   BTree() {
      root = null;
   }

   // Getter e Setter para a raiz
   public BTNode<T> getRoot() {return root;}
   public void setRoot(BTNode<T> r) {root = r;}

   // Verificar se arvore esta vazia
   public boolean isEmpty() {
      return root == null;
   }

   // Numero de nos da arvore
   public int numberNodes() {
      return numberNodes(root);
   }

   private int numberNodes(BTNode<T> n) {
      if (n == null) return 0;
      return 1 + numberNodes(n.getLeft()) + numberNodes(n.getRight());
   }

   // Altura da arvore
   public int depth() {
      return depth(root);
   }

   private int depth(BTNode<T> n) {
      if (n == null) return -1;
      return 1 + Math.max(depth(n.getLeft()), depth(n.getRight()));
   }


   // O elemento value esta contido na arvore?
   public boolean contains(T value) {
      return contains(root, value);
   }

   private boolean contains(BTNode<T> n, T value) {
      if (n == null) return false;
      if (n.getValue().equals(value)) return true;
      return contains(n.getLeft(), value) || contains(n.getRight(), value);
   }

   // Imprimir arvore em PreOrder
   public void printPreOrder() {
      System.out.print("PreOrder:");
      printPreOrder(root);
      System.out.println();
   }

   private void printPreOrder(BTNode<T> n) {
      if (n == null) return;
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

   private void printInOrder(BTNode<T> n) {
      if (n == null) return;
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

   private void printPostOrder(BTNode<T> n) {
      if (n == null) return;
      printPostOrder(n.getLeft());
      printPostOrder(n.getRight());
      System.out.print(" " + n.getValue());
   }

   // Imprimir arvore numa visita em largura (usando TAD Fila)
   public void printBFS() {
      System.out.print("BFS:");

      MyQueue<BTNode<T>> q = new LinkedListQueue<BTNode<T>>();
      q.enqueue(root);
      while (!q.isEmpty()) {
         BTNode<T> cur = q.dequeue();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.enqueue(cur.getLeft());
            q.enqueue(cur.getRight());
         }
      }
      System.out.println();
   }

   // Imprimir arvore numa visita em profundidade (usando TAD Pilha)
   public void printDFS() {
      System.out.print("DFS:");

      MyStack<BTNode<T>> q = new LinkedListStack<BTNode<T>>();
      q.push(root);
      while (!q.isEmpty()) {
         BTNode<T> cur = q.pop();
         if (cur != null) {
            System.out.print(" " + cur.getValue());
            q.push(cur.getLeft());
            q.push(cur.getRight());
         }
      }
      System.out.println();
   }

   //ED239 - métodos para árvores binárias
   public int count() {
     return count(root);
   }
   private int count(BTNode<T> n) {
    if(n == null) return 0;
    int cont = 0;
    if((n.getLeft() == null && n.getRight() != null) || (n.getLeft() != null && n.getRight() == null)) cont++;
    return cont + (count(n.getLeft())) + (count(n.getRight()));
  }
  public int level(T v) {
    int aux = level(root,v,0);
    if(aux == 100) return -1;
    return aux;
  }
  private int level(BTNode<T> n, T v, int nivel) {
    if(n == null) return 100;
    if(n.getValue().equals(v)) return nivel;
    return Math.min(level(n.getLeft(),v,nivel+1),level(n.getRight(),v,nivel+1));
  }

  //ED233
  public int internal() {
    return internal(root);
  }
  public int internal(BTNode<T> n) {
    if(n == null) return 0;
    int cont = 0;
    if(n.getLeft() != null || n.getRight() != null) cont++;
    return cont + internal(n.getLeft()) + internal(n.getRight());
  }
  public void cut(int d)  {
    if(d <= 0) cut(null,d,0);
    cut(root,d,0);
  }
  public void cut(BTNode<T> n, int d, int nivel) {
    if(n == null) return;
    if(d <= 0) {
      root = null;
      n.setLeft(null);
      n.setRight(null);
    }
    else if(nivel+1 >= d) {
      if (n.getLeft() != null)
         n.setLeft(null);
      if (n.getRight() != null)
         n.setRight(null);
    }
    cut(n.getLeft(),d,nivel+1);
    cut(n.getRight(),d,nivel+1);
  }
  // ↓ NAO ESTA CERTO ↓
  static int max1;
  static int max2;
  public int[] maxLevel() {
    max1 = 0;
    max2 = 0;
    int[] v = new int[2];
    if(numberNodes() == 1) {
      v[0] = 1; v[1] = 1;
    }
    v = maxLevel(root,v,0);
    if(max1 == 1) v[1]++;
    return v;
  }
  public int[] maxLevel(BTNode<T> n, int[] v, int nivel) {
    if(n == null) return null;
    int aux = max1(root,nivel,0);
    if(v[0] == aux) {
      max2++;
      v[1] = max2;
    }
    if(aux > max1) {
      max2 = 0;
      max1 = aux;
      v[0] = aux;
    }
    maxLevel(n.getLeft(),v,nivel+1);
    maxLevel(n.getRight(),v,nivel+1);
    return v;
  }
  public int max1(BTNode<T> n, int nivel, int lvl) {
    if(n == null) return 0;
    int cont = 0;
    if(nivel == lvl) {
      if(n.getLeft() != null) cont++;
      if(n.getRight() != null) cont++;
    }
    return cont + max1(n.getLeft(),nivel,lvl+1) + max1(n.getRight(),nivel,lvl+1);
  }
}
