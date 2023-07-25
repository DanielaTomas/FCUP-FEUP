// Uma classe simples para representar um ponto 2D
class Point {
   int x, y;
   Point() {
      x = y = 0;
   }
   Point(int x0, int y0) {
      x = x0;
      y = y0;
   }
   public String toString() {
      return "(" + x + "," + y + ")";
   }
}
//classe Rectangle
class Rectangle {
   Point left = new Point();
   Point right = new Point();

   Rectangle(int x1, int y1, int x2, int y2) {
      left.x = x1;
      left.y = y1;
      right.x = x2;
      right.y = y2;
   }
   Rectangle(Point p1, Point p2) {
      left.x = p1.x;
      left.y = p1.y;
      right.x = p2.x;
      right.y = p2.y;
   }
   public int area() {
      return ((right.x - left.x)*(right.y - left.y));
   }
   public int perimeter() {
      return ((right.x - left.x)*2 + (right.y - left.y)*2);
   }
   public boolean pointInside(Point p) {
      if(p.x <= right.x && p.x >= left.x && p.y <= right.y && p.y >= left.y)
       return true;
      return false;
   }
   public boolean rectangleInside(Rectangle r) {
      if(pointInside(r.left) && pointInside(r.right))
       return true;
      return false;
   }
}


class TestRectangle {
   public static void main(String[] args) {
      Point a = new Point(1,1);
      Point b = new Point(2,2);
      Point c = new Point(3,4);
      Point d = new Point(8,2);

      Rectangle amarelo  = new Rectangle(a, c);
      Rectangle laranja  = new Rectangle(2, 3, 9, 6);
      Rectangle verde    = new Rectangle(3, 4, 4, 5);
      Rectangle azul     = new Rectangle(5, 1, 6, 5);
      Rectangle vermelho = new Rectangle(7, 3, 9, 5);

      System.out.println("Perimetro do retangulo amarelo = " + amarelo.perimeter()); // 10
      System.out.println("Perimetro do retangulo laranja = " + laranja.perimeter()); // 20

      System.out.println("Area do retangulo amarelo = " + amarelo.area()); // 6
      System.out.println("Area do retangulo laranja = " + laranja.area()); // 21

      System.out.println("Ponto B dentro rectangulo amarelo? " + amarelo.pointInside(b)); // true
      System.out.println("Ponto D dentro rectangulo amarelo? " + amarelo.pointInside(d)); // false

      System.out.println("Retangulo verde dentro do laranja? " + laranja.rectangleInside(verde));       // true
      System.out.println("Retangulo azul dentro do laranja? " + laranja.rectangleInside(azul));         // false
      System.out.println("Retangulo vermelho dentro do laranja? " + laranja.rectangleInside(vermelho)); // true
   }
}
/*
p1 original: (0,0)
p1 modificado: (1,0)
p2: (2,3)
*/
