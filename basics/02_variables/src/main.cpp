// 02_variables: 变量、数据类型、类型推断
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

int main() {
    // 基本类型
    int    a = 42;
    double b = 3.14;
    char   c = 'A';
    bool   d = true;

    std::cout << "int:    " << a << "\n";
    std::cout << "double: " << b << "\n";
    std::cout << "char:   " << c << "\n";
    std::cout << "bool:   " << std::boolalpha << d << "\n";

    // C++11: auto 类型推断
    auto x = 100;
    auto y = 2.718;
    auto s = std::string{"C++17"};

    std::cout << "\nauto int:    " << x << "\n";
    std::cout << "auto double: " << y << "\n";
    std::cout << "auto string: " << s << "\n";

    // C++17: structured bindings
    std::pair<int, std::string> p{1, "one"};
    auto [num, name] = p;
    std::cout << "\nstructured binding: " << num << " = " << name << "\n";

    return 0;
}
