#include "iostream"
int main() {
    int v;
    /*
    //7.1  v = 2
    v = 1;
    int& r = v;
    r = 2;       //v = 2
     */

    /*
    //7.2  v = 5
    v = 2;
    int& r = v;
    int* p = &v;
    r = *p + r;    // v = 2 + 2 = 4
    r++;           // v = 5
     */

    /*
    //7.3  v = 5
    v = 3;
    int v2 = 4;
    int& r = v;
    int& r2 = v2;
    r = r2;       // v = 4
    r2 = r;
    r++;         // v = 5
     */

    //7.4  v = 7
    v = 3;
    int a[2] = { 1, 2 };
    int& r = v;
    int& r2 = a[1];
    r2++;
    r += a[0] + a[1];  // v = 3 + 1 + 3 = 7

    std::cout << v << std::endl;

    return 0;
}