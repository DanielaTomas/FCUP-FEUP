#include <algorithm>
#include <iostream>
int main(void) {
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;
    std::cout << "Enter values: ";
    // Allocate array
    int* a = new int[n];
    // Read values
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    double median;
    if(n % 2 != 0) median = (a[n/2]);
    else {
      median = (((double)(a[n/2-1]+a[n/2]))/2);
    }
    std::cout << "Median: " << median << std::endl;
    // Release memory
    delete [] a;
    return 0;
}
