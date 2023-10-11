#include <iostream>

// int main() {
//     std::cout << "Please enter two numbers:" << std::endl;
//     int lo = 0, hi = 0;
//     std::cin >> lo >> hi;
//     if (lo > hi) {
//         int temp = lo;
//         lo = hi;
//         hi = temp;
//     }

//     while (lo <= hi) {
//         std::cout << lo++ << ' ';
//     }
//     std::cout << std::endl;

//     return 0;
// }

void printRange(int lo, int hi) {
    if (lo > hi) {
        printRange(hi, lo);
        return;
    }

    while (lo <= hi) {
        std::cout << lo++ << ' ';
    }
}

int main() {
    std::cout << "Please input two integers:" << std::endl;
    int low = 0, high = 0;
    std::cin >> low >> high;
    printRange(low, high);
    std::cout << std::endl;

    return 0;
}