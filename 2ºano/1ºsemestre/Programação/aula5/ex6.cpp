#include <iostream>
template <typename T>
struct coord2d {
    T x;
    T y;
};
template <typename T>
std::istream& operator>>(std::istream& is, coord2d<T>& c) {
    is >> c.x >> c.y;
    return is;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const coord2d<T>& c) {
    os << c.x << ' ' << c.y;
    return os;
}
template <typename T>
coord2d<T> operator+(const coord2d<T>& a, const coord2d<T>& b) {
    coord2d<T> r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

template <typename T>
coord2d<T> operator*(int f, const coord2d<T>& b) {
    coord2d<T> r;
    r.x = f * b.x;
    r.y = f * b.y;
    return r;
}
template <typename T>
coord2d<T> operator-(const coord2d<T>& a, const coord2d<T>& b) {
    coord2d<T> r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

template <typename T>
coord2d<T> operator-(const coord2d<T>& c) {
    coord2d<T> r;
    r.x = -c.x;
    r.y = -c.y;
    return r;
}
int main() {
    coord2d<double> a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    coord2d<double> d = - a + 2 * b + c;
    std::cout << "- a + 2 * b - c = " << d << std::endl;
    return 0;
}
