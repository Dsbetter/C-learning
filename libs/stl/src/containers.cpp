// stl/containers.cpp - STL 容器使用示例
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <queue>

int main() {
    // --- vector ---
    std::cout << "=== vector ===\n";
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    vec.push_back(5);
    std::cout << "size: " << vec.size() << ", front: " << vec.front() << "\n";

    // --- map ---
    std::cout << "\n=== map ===\n";
    std::map<std::string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"]   = 87;
    scores["Carol"] = 92;
    for (const auto& [name, score] : scores) {  // C++17 structured binding
        std::cout << name << ": " << score << "\n";
    }

    // --- set ---
    std::cout << "\n=== set ===\n";
    std::set<int> s = {5, 3, 1, 4, 1, 5, 9};  // 自动去重并排序
    for (int v : s) std::cout << v << " ";
    std::cout << "\n";

    // --- stack / queue ---
    std::cout << "\n=== stack ===\n";
    std::stack<int> stk;
    for (int i = 1; i <= 5; ++i) stk.push(i);
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "\n";

    return 0;
}
