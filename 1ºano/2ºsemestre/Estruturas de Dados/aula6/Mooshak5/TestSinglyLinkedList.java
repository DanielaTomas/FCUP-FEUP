public class TestSinglyLinkedList {
   public static void main(String[] args) {

      // Criacao de lista de inteiros
  /*    SinglyLinkedList<Integer> list = new SinglyLinkedList<Integer>();

      // Escrevendo lista (no inicio esta vazia)
      System.out.println(list);

      // Verificando se esta vazia
      System.out.println("isEmpty? " + list.isEmpty());

      // Adicionando numeros de 1 a 5 ao final da lista
      for (int i=1; i<=5; i++)
         list.addLast(i);
      System.out.println(list);

      // Adicionando numeros de 6 a 10 ao inicio da lista
      for (int i=6; i<=10; i++)
         list.addFirst(i);
      System.out.println(list);

      // Verificando o tamanho da lista
      System.out.println("size = " + list.size());

      // Retirando o primeiro elemento
      list.removeFirst();
      System.out.println(list);

      // Retirando o ultimo elemento
      list.removeLast();
      System.out.println(list);

      // Verificando se esta vazia
      System.out.println("isEmpty? " + list.isEmpty());

      // Escreve o primeiro e ultimo elementos
      System.out.println("getFirst() = " + list.getFirst());
      System.out.println("getLast() = " + list.getLast()); */

      SinglyLinkedList<Character> list1 = new SinglyLinkedList<>();

      list1.addLast('a');
      list1.addLast('e');
      list1.addLast('i');
      list1.addLast('o');
      list1.addLast('u');
    /* System.out.println(list1);
      list1.get(0);
      list1.get(3);
      System.out.println("get(0) = " + list1.get(0));
      System.out.println("get(3) = " + list1.get(3 ));
      list1.get(6);
      list1.get(-1);
      System.out.println("get(6) = " + list1.get(6));
      System.out.println("get(-1) = " + list1.get(-1)); */

  /*    System.out.println(list1);
      System.out.println("remove(0) = " + list1.remove(0));
      System.out.println(list1);
      System.out.println("remove(2) = " + list1.remove(2));
      System.out.println(list1);
      list1.remove(6);
      list1.remove(-1);
      System.out.println("remove(6) = " + list1.remove(6));
      System.out.println("remove(-1) = " + list1.remove(-1)); */

      SinglyLinkedList<Integer> list2 = new SinglyLinkedList<>();

      list2.addLast(0);
      list2.addLast(1);
      list2.addLast(2);
      list2.addLast(3);
      list2.addLast(4);
      list2.addLast(5);
      list2.addLast(6);
      list2.addLast(7);
      list2.addLast(8);
      list2.addLast(9);
      list2.addLast(10);
      list2.addLast(11);
      list2.addLast(12);
      list2.addLast(13);



      System.out.println(list2);
      list2.removeEven();
      System.out.println("removeEven() = " + list2);

    /* System.out.println(list1);
      System.out.println("copy() = " + list1.copy()); */

    /*  System.out.println(list1);
      list1.duplicate();
      System.out.println(list1); */

    /*  System.out.println(list1);
      System.out.println("count(a) = " + list1.count('a'));
      System.out.println("count(o) = " + list1.count('o'));
      list1.addFirst('a');
      list1.addFirst('a');
      list1.addFirst('a');
      list1.addLast('u');
      list1.addLast('u');
      System.out.println(list1);
      System.out.println("count('a') = " + list1.count('a'));
      System.out.println("count('u') = " + list1.count('u')); */
   }
}
