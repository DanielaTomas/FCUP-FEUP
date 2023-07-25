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
