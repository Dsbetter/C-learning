#include "math_utils.h"
#include <iostream>

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

int main() {
    // 重载
    std::cout << "add(1, 2)       = " << add(1, 2) << "\n";
    std::cout << "add(1.5, 2.5)   = " << add(1.5, 2.5) << "\n";

    // 模板
    std::cout << "max_of(3, 7)    = " << max_of(3, 7) << "\n";
    std::cout << "max_of(3.0,2.0) = " << max_of(3.0, 2.0) << "\n";

    // 默认参数
    std::cout << "power(3)        = " << power(3) << "\n";
    std::cout << "power(2, 10)    = " << power(2, 10) << "\n";

    // Lambda (C++11)
    auto square = [](int n) { return n * n; };
    std::cout << "square(5)       = " << square(5) << "\n";

    return 0;
}
