public class ArrayListIntSet implements IntSet {
   private int size;   // Numero de elementos do conjunto
   private int elem[]; // Array que contem os elementos em si
/* 10000.txt
real	0m0.431s
user	0m0.360s
sys	0m0.023s */
   ArrayListIntSet(int maxSize) {
      elem = new int[maxSize];
      size = 0;
   }
   public boolean add(int x) {
      if (!contains(x)) {
         if (size == elem.length)
            throw new RuntimeException("Maximum size of set reached");
         elem[size] =  x;
         size++;
         return true;
      }
      return false;
   }
   public boolean remove(int x) {
      if (contains(x)) {
         int pos = 0;
         while (elem[pos] != x) pos++;
         size--;
         elem[pos] = elem[size]; // Trocar ultimo elemento
         return true;            // com o que se removeu
      }
      return false;
   }
   public boolean contains(int x) {
      for (int i=0; i<size; i++)
         if (elem[i] == x)
            return true;
      return false;
   }
   public void clear() {
      size = 0;
   }
   public int size() {
      return size;
   }
   public boolean equals(IntSet s) {
     if(size != s.size()) return false;
     for(int i=0; i < size; i++) {
       if(!(s.contains(elem[i]))) return false;
     }
    return true;
   }
   public IntSet intersection(IntSet s) {
     IntSet inter = new ArrayListIntSet(100);
    for(int i=0; i < size; i++) {
      if(s.contains(elem[i])) {
       inter.add(elem[i]);
      }
    }
    return inter;
   }
   @Override
   public String toString() {
      String res = "{";
      for (int i=0; i<size; i++) {
         if (i>0) res += ",";
         res += elem[i];
      }
      res += "}";
      return res;
   }
}
