#include<iostream>

int main() {
   /*
    // 8.1
    int* p = new int[3] { 0 };
    p[1] = p[0] + p[2];
    */

   /*
    // 8.2
    int* p = new int[3] { 0 };
    p[1] = p[0] + p[3];
    delete [] p;
    */

   /*
    // 8.3
    int* p = new int[3] { 0 };
    delete [] p;
    p[1] = p[0] + p[2];
    */

   /*
    // 8.4
    int* p = new int[3] { 0 };
    int* q = p + 1;
    *p = 1;
    delete [] p;
    *q= 2;
    */

    /*
  // 8.5
    int* p = new int[3] { 0 };
    int* q = new int;
    *q = p[2];
    *p = *q;
    delete [] p;
  */

    /*
  // 8.6
    int* p = new int[3] { 0 };
    int* q = new int;
    *q = 3;
    p[*q] = 1;
    delete [] p;
    delete q;
  */
    return 0;
}
