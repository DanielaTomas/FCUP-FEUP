class TestBSTree {
   public static void main(String[] args) {

      // Criacao da Arvore
      BSTree<Integer> t = new BSTree<Integer>();

      // Inserindo 11 elementos na arvore binaria de pesquisa
      int[] data = {14, 4, 18, 3, 9, 16, 20, 7, 15, 17, 5};
      for (int i=0; i<data.length; i++) t.insert(data[i]);

      // Escrever resultado de chamada a alguns metodos
      System.out.println("numberNodes = " + t.numberNodes());
      System.out.println("depth = " + t.depth());
      System.out.println("contains(2) = " + t.contains(2));
      System.out.println("contains(3) = " + t.contains(3));

      // Escrever nos da arvore seguindo varias ordens possiveis
      t.printPreOrder();
      t.printInOrder();
      t.printPostOrder();

      // Experimentando remocao
      t.remove(14);
      t.printPreOrder();
      t.printInOrder();
      t.printPostOrder();

      System.out.println("maxValue() = " + t.maxValue());
      System.out.println("minValue() = " + t.minValue());

  /*    //int[] data = {5,3,10,1,4,7,42};
      //int[] data = {7,5,9,6,8,10};
      //int[] data = {5,4,8,2,7};

      for(int i=0; i<data.length; i++) t.insert(data[i]);
      BSTNode<Integer> n = t.getRoot();
      System.out.println("verifyleft() = " + t.verify(n.getLeft(),5,1));
      System.out.println("verifyright() = " + t.verify(n.getRight(),5,0));

      System.out.println("valid() = " + t.valid()); */
      BSTree<Integer> t1 = new BSTree<Integer>();
      int[] data1 = {6,3,10,1,4,8,42,2,7,23,54};
      for (int i=0; i<data1.length; i++) t1.insert(data1[i]);

      System.out.println("countBetween(5,44) = " + t1.countBetween(5,44));
      System.out.println("countBetween(7,10) = " + t1.countBetween(7,10));
      System.out.println("countBetween(0,90) = " + t1.countBetween(0,90));
      System.out.println("countBetween(60,80) = " + t1.countBetween(60,80));
      System.out.println("countBetween(8,54) = " + t1.countBetween(8,54));
      System.out.println("countBetween(2,22) = " + t1.countBetween(2,22));
      System.out.println("countBetween(2,2) = " + t1.countBetween(2,2));
   }
}
