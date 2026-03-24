// stl/algorithms.cpp - STL 算法使用示例
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // sort 升序
    std::cout << "=== sort (ascending) ===\n";
    std::sort(v.begin(), v.end());
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // sort 降序（使用内建函数对象 std::greater）
    std::cout << "\n=== sort (descending) ===\n";
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
    std::sort(v.begin(), v.end());  // 恢复升序

    // binary_search（要求已排序）
    std::cout << "\n=== binary_search ===\n";
    std::cout << "find 7: " << std::boolalpha << std::binary_search(v.begin(), v.end(), 7) << "\n";

    // find / find_if
    std::cout << "\n=== find / find_if ===\n";
    auto it1 = std::find(v.begin(), v.end(), 4);
    if (it1 != v.end()) std::cout << "find 4: " << *it1 << "\n";

    auto it2 = std::find_if(v.begin(), v.end(), [](int x) { return x > 5; });
    if (it2 != v.end()) std::cout << "first > 5: " << *it2 << "\n";

    // count / count_if
    std::cout << "\n=== count / count_if ===\n";
    std::vector<int> v2 = {3, 1, 4, 1, 5, 1, 9};
    std::cout << "count(1): " << std::count(v2.begin(), v2.end(), 1) << "\n";
    int evens = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "even count = " << evens << "\n";

    // transform
    std::cout << "\n=== transform (x*2) ===\n";
    std::vector<int> doubled(v.size());
    std::transform(v.begin(), v.end(), doubled.begin(), [](int x) { return x * 2; });
    for (int x : doubled) std::cout << x << " ";
    std::cout << "\n";

    // accumulate（求和）
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "\naccumulate sum = " << sum << "\n";

    return 0;
}
