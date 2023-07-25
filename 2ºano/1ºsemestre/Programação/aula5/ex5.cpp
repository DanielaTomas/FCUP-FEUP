#include <iostream>
struct coord2d {
    int x;
    int y;
};
std::istream& operator>>(std::istream& is, coord2d& c) {
    is >> c.x >> c.y;
    return is;
}
std::ostream& operator<<(std::ostream& os, const coord2d& c) {
    os << c.x << ' ' << c.y;
    return os;
}
coord2d operator+(const coord2d& a, const coord2d& b) {
    coord2d r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}
coord2d operator*(int f, const coord2d& c) {
    coord2d r;
    r.x = f * c.x;
    r.y = f * c.y;
    return r;
}
coord2d operator-(const coord2d& a, const coord2d& b) {
    coord2d r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}
coord2d operator-(const coord2d& c) {
    coord2d r;
    r.x = -c.x;
    r.y = -c.y;
    return r;
}
int main() {
  /*  coord2d a, b;
    std::cout << "Enter a and b: ";
    std::cin >> a >> b;
    coord2d c = 2 * a + b;
    std::cout << "2 * a + b = " << c << std::endl; */

    coord2d a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    coord2d d = - a + 2 * b - c;
    std::cout << "- a + 2 * b - c = " << d << std::endl;
    return 0;
}