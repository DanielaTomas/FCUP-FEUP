public class BooleanArrayIntSet implements IntSet {
    private int size;   // Numero de elementos do conjunto
    private boolean elem[]; // Array que contem os elementos em si
    private int maxsize;

    BooleanArrayIntSet(int maxSize) {
      elem = new boolean[maxSize+1];
      maxsize = maxSize;
      size = 0;
    }
    public boolean add(int x) {
      if(!contains(x)) {
          if(size == elem.length)
            throw new RuntimeException("Maximum size of set reached");
          elem[x] = true;
          size++;
          return true;
      }
      return false;
    }
    public boolean remove(int x) {
      if(contains(x)) {
          elem[x] = false;
          size--;
          return true;
      }
      return false;
    }
    public boolean contains(int x) {
      if(elem[x] == true)
        return true;
      return false;
    }
    public void clear() {
      size = 0;
      for(int i=0; i < maxsize+1; i++) {
       if(elem[i] == true)
        elem[i] = false;
      }
    }
    public int size() {
      return size;
    }
    public boolean equals(IntSet s) {
      if(size != s.size()) return false;
      for(int i=0; i < maxsize; i++) {
        if(!(s.contains(i) == contains(i))) return false;
      }
     return true;
    }
    public IntSet intersection(IntSet s) {
      IntSet inter = new BooleanArrayIntSet(maxsize);
      for(int i=0; i < maxsize; i++) {
        if(contains(i) && s.contains(i)) {
         inter.add(i);
        }
      }
      return inter;
    }
    @Override
    public String toString() {
      String res = "{";
      for(int i=0; i < maxsize; i++) {
        if (i>0) res += ",";
         res += elem[i];
      }
      res += "}";
      return res;
    }
}
