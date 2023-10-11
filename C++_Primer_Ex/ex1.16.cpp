#include <iostream>

// int main() {
//     int value = 0, sum = 0;
//     while (std::cin >> value) {
//         sum += value;
//     }
//     std::cout << sum << std::endl;

//     return 0;
// }

int main() {
    int sum = 0;
    for (int val = 0; std::cin >> val; sum += val) ;
    std::cout << sum << std::endl;

    return 0;
}