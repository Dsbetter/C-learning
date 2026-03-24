#include "math_utils.h"
#include <iostream>

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

// 演示：常量引用参数避免拷贝
void print_str(const std::string& s) {
    std::cout << "string: " << s << "\n";
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

    // 常量引用参数
    print_str("hello C++");

    // Lambda (C++11)
    auto square = [](int n) { return n * n; };
    std::cout << "square(5)       = " << square(5) << "\n";

    // Lambda 值捕获 vs 引用捕获
    int offset = 10;
    auto add_offset = [offset](int x) { return x + offset; };   // 值捕获
    auto inc        = [&offset](int x) { return x + offset; };  // 引用捕获
    offset = 20;
    std::cout << "add_offset(5)   = " << add_offset(5) << "\n"; // 15（捕获时 offset=10）
    std::cout << "inc(5)          = " << inc(5) << "\n";        // 25（引用，offset=20）

    return 0;
}
