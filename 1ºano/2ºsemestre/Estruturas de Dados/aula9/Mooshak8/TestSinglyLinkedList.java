import java.util.*;
public class TestSinglyLinkedList {
   public static void main(String[] args) {
      SinglyLinkedList<Character> list = new SinglyLinkedList<>();

      list.addLast('a');
      list.addLast('e');
      list.addLast('i');
      list.addLast('o');
      list.addLast('u');

      SinglyLinkedList<Integer> list1 = new SinglyLinkedList<>();
      list1.addLast(1);
      list1.addLast(2);
      list1.addLast(2);
      list1.addLast(2);
      list1.addLast(1);
      list1.addLast(3);
      list1.addLast(4);
      list1.addLast(2);
      list1.addLast(1);
      System.out.println(list1);
      list1.removeAll(2);
      System.out.println("removeAll({2}) = " + list1 + " size = " + list1.size());

    /*  --------------------------------------
      list = {1,2,2,2,1,3,4,2,1}
      list.removeAll(2)
      Depois do remove, list = {1,1,3,4,1} [size=5]
      --------------------------------------
      list = {1,2,2,2,1,3,4,2,1}
      list.removeAll(3)
      Depois do remove, list = {1,2,2,2,1,4,2,1} [size=8]
      --------------------------------------
      list = {1,2,2,2,1,3,4,2,1}
      list.removeAll(4)
      Depois do remove, list = {1,2,2,2,1,3,2,1} [size=8]
      --------------------------------------
      list = {1,2,2,2,1,3,4,2,1}
      list.removeAll(5)
      Depois do remove, list = {1,2,2,2,1,3,4,2,1} [size=9]
      -------------------------------------- */

  /*    SinglyLinkedList<Character> list1 = new SinglyLinkedList<>();

      list1.addLast('a');
      list1.addLast('b');
      list1.addLast('c');
      list1.addLast('d');
      list1.addLast('e');
      System.out.println(list1);
      list1.shift(2);
      System.out.println("shift(2) = " + list1); */


  /*  SinglyLinkedList<Integer> list1 = new SinglyLinkedList<>();
      System.out.println("cut(1,1) = " + list.cut(1,1));

      SinglyLinkedList<Integer> list1 = new SinglyLinkedList<>();

      list1.addLast(2);
      list1.addLast(4);
      list1.addLast(6);
      list1.addLast(8);
      list1.addLast(10);

      System.out.println("cut(2,3) = " + list1.cut(2,4)); */

  /*    SinglyLinkedList<Character> list1 = new SinglyLinkedList<>();
      list1.addLast('e');
      list1.addLast('i');

      SinglyLinkedList<Character> list2 = new SinglyLinkedList<>();
      list2.addLast('a');
      list2.addLast('u');


      System.out.println(list);
      list.remove(list1);
      System.out.println("remove({e,i}) = " + list);
      System.out.println(list);
      list.remove(list2);
      System.out.println("remove({a,u}) = " + list);
      System.out.println(list);

      System.out.println(list);
      System.out.println("reverse() = " + list.reverse());
      System.out.println(list);

      SinglyLinkedList<String> list1 = new SinglyLinkedList<>();

      list1.addLast("edados");

      System.out.println(list1);
      System.out.println("reverse() = " + list1.reverse());
      System.out.println(list1);

      SinglyLinkedList<String> list2 = new SinglyLinkedList<>();

      System.out.println(list2);
      System.out.println("reverse() = " + list2.reverse());
      System.out.println(list2); */

  /*  list.addLast('a');
      list.addLast('a');
      list.addLast('i');
      list.addLast('a');
      list.addLast('u');
      System.out.println(list);
      System.out.println("occurrences('a') = " + Arrays.toString(list.occurrences('a')));
      System.out.println(list);

      SinglyLinkedList<String> list1 = new SinglyLinkedList<>();

      list1.addLast("estruturas");
      list1.addLast("dados");

      System.out.println(list1);
      System.out.println("occurrences(''de'') = " + list1.occurrences("de"));
      System.out.println(list1);

      SinglyLinkedList<Integer> list2 = new SinglyLinkedList<>();

      list2.addLast(1);
      list2.addLast(1);
      list2.addLast(1);
      list2.addLast(1);
      list2.addLast(1);

      System.out.println(list2);
      System.out.println("occurrences(1) = " + Arrays.toString(list2.occurrences(1)));
      System.out.println(list2);
      */
   }
}
