// 02_variables: variables, data types, type deduction

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Basic types
    int    a = 42;
    double b = 3.14;
    char   c = 'A';
    bool   d = true;

    std::cout << "int:    " << a << " sizeof = " << sizeof(a) << "\n";
    std::cout << "double: " << b << " sizeof = " << sizeof(b) << "\n";
    std::cout << "char:   " << c << " sizeof = " << sizeof(c) << "\n";
    std::cout << "bool:   " << std::boolalpha << d << " sizeof = " << sizeof(d) << "\n";

    // const vs constexpr
    const int MAX = 100;          // runtime constant
    constexpr int SIZE = 256;     // compile constant (recommended)
    std::cout << "\nconst MAX = " << MAX << ", constexpr SIZE = " << SIZE << "\n";

    // Reference: alias, cannot change the object it points to
    int val = 10;
    int& ref = val;
    ref = 20;
    std::cout << "ref after assign: val = " << val << "\n";  // 20

    // C++11: auto type deduction
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

    // C++17: if statement with initializer
    std::vector<int> vec = {1, 2, 3, 4, 5};
    if (auto it = std::find(vec.begin(), vec.end(), 3); it != vec.end()) {
        std::cout << "found: " << *it << "\n";
    }

    return 0;
}
