// 02_variables: 变量、数据类型、类型推断
#include <iostream>
#include <string>
#include <vector>

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

    // 常量：const vs constexpr
    const int MAX = 100;          // 运行时常量
    constexpr int SIZE = 256;     // 编译期常量（推荐）
    std::cout << "\nconst MAX = " << MAX << ", constexpr SIZE = " << SIZE << "\n";

    // 引用：别名，不可改变指向
    int val = 10;
    int& ref = val;
    ref = 20;
    std::cout << "ref after assign: val = " << val << "\n";  // 20

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

    // C++17: if 初始化语句（限制变量作用域）
    std::vector<int> vec = {1, 2, 3, 4, 5};
    if (auto it = std::find(vec.begin(), vec.end(), 3); it != vec.end()) {
        std::cout << "found: " << *it << "\n";
    }

    return 0;
}
