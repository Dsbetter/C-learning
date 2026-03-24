// stl/algorithms.cpp - STL 算法使用示例
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // sort
    std::cout << "=== sort ===\n";
    std::sort(v.begin(), v.end());
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // binary_search
    std::cout << "\n=== binary_search ===\n";
    std::cout << "find 7: " << std::boolalpha << std::binary_search(v.begin(), v.end(), 7) << "\n";

    // transform
    std::cout << "\n=== transform (x*2) ===\n";
    std::vector<int> doubled(v.size());
    std::transform(v.begin(), v.end(), doubled.begin(), [](int x) { return x * 2; });
    for (int x : doubled) std::cout << x << " ";
    std::cout << "\n";

    // accumulate
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "\nsum = " << sum << "\n";

    // count_if
    int evens = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "even count = " << evens << "\n";

    // find_if
    auto it = std::find_if(v.begin(), v.end(), [](int x) { return x > 5; });
    if (it != v.end()) std::cout << "first > 5: " << *it << "\n";

    return 0;
}
