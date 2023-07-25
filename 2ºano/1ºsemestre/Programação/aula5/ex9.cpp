#include <iostream>

/*
//9.1
    namespace a {
         int f(int x, int y=1) { // 10 * 3 ; 9 * 1
             return x * y;
         }
         namespace b {
             int f(int x) {
                 return x + a::f(x-1); // 10 + a::(9,1) = 10 + 9 * 1 = 19
             }
         }
    }
    int f() {
     return 100;
    }
    int f(int x) {
     return f() - a::f(x, 3) - a::b::f(x) - 9; // 100 - a::f(10,3) - a::b::f(10) - 9 = 100 - 30 - 19 - 9 = 42
    }*/

//9.2
    namespace a {
        int f(int x=2, int y=1) {
            return x - y;         // 2 - 1; 4 - 2; 2 - 1
        }
        namespace b {
            int f(int x) {
                return x > 2 ?                      //true; true; false
                       x * f(x - 1) :            // 4 * f(3) = 4 * 3 * f(2) = 4 * 3 * a::f(2,1) * a::f(2 * 2, 2) = 12 * 1 * 2 = 24
                       a::f(x) * a::f(x * x, x);
            }
        }
    }
    int f(int x) {
        return 2 * a::b::f(4) - 6 * a::f(); // 2 * 24 - 6 * 1 = 42
    }
    int main() {
     std::cout << f(10) << std::endl;
     return 0;
    }