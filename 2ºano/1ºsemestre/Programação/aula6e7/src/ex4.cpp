#include <iostream>
//4.1
namespace leic {
  class coord3d {
   private:
     int x;
     int y;
     int z;

   public:
     coord3d() {
       x = 0;
       y = 0;
       z = 0;
     }

     coord3d(int vx, int vy, int vz) {
       x = vx;
       y = vy;
       z = vz;
     }

     coord3d(const coord3d& c) {
       x = c.x;
       y = c.y;
       z = c.z;
     }

     ~coord3d() { }

     int get_x() const {
       return x;
     }

     void set_x(int vx) {
       x = vx;
     }

     int get_y() const {
       return y;
     }

     void set_y(int vy) {
       y = vy;
     }

     int get_z() const {
       return z;
     }

     void set_z(int vz) {
       z = vz;
     }

  };

  //4.2
  std::ostream& operator<<(std::ostream& out, const coord3d& c) {
    out << '(' << c.get_x() << ',' << c.get_y() << ',' << c.get_z() << ')';
    return out;
  }
}

int main() {
  return 0;
}
