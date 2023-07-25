#include <iostream>
#include <climits>
int main(void) {
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    int x;
    for(int i = 0; i < n; i++) {
        std::cout << "Enter value: ";
        std::cin >> x;
        if (x > max) max = x;
        if (x < min) min = x;
        sum += x;
    }
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Sum: " << sum << std::endl;
}
