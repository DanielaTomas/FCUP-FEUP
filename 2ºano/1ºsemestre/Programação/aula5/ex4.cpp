#include <iostream>

template <typename T>
T max_value(const T arr[], int n) {
    T max = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
template <typename T>
void norm_values(T arr[], int n, T min, T max) {
    for(int i = 0; i < n; i++) {
        if(arr[i] < min) arr[i] = min;
        if(arr[i] > max) arr[i] = max;
    }
}

int main() {
    int iarr[6] = { 2, -1, 2, 5, 1, 4};
    int imax = max_value(iarr, 6);
    norm_values(iarr, 6, 0, 3);
    std::cout <<  "---- Teste Int ----" << std::endl;
    std::cout <<  "imax: " << imax << std::endl;
    for(int i = 0; i < 6; i++) {
        std::cout <<  "a[" << i << "] = " << iarr[i] << std::endl;
    }

    double darr[6] = { -1.2, 0.5, 1.3, 3.2, -0.7, 1.1 };
    double dmax = max_value(darr, 6);
    norm_values(darr, 6, -1.0, 1.0);
    std::cout <<  "---- Teste Double ----" << std::endl;
    std::cout <<  "imax: " << dmax << std::endl;
    for(int i = 0; i < 6; i++) {
        std::cout <<  "a[" << i << "] = " << darr[i] << std::endl;
    }
    return 0;
}
