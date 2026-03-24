// stl/containers.cpp - STL 容器使用示例
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <utility>

int main() {
    // --- vector ---
    std::cout << "=== vector ===\n";
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    vec.push_back(5);
    std::cout << "size: " << vec.size() << ", front: " << vec.front() << "\n";
    std::cout << "v[2]=" << vec[2] << " (不检查越界), v.at(2)=" << vec.at(2) << " (检查越界)\n";

    // --- list (双向链表) ---
    std::cout << "\n=== list ===\n";
    std::list<int> lst = {1, 2, 3};
    lst.push_front(0);   // 头部插入
    lst.push_back(4);    // 尾部插入
    for (int v : lst) std::cout << v << " ";
    std::cout << "\n";

    // --- map ---
    std::cout << "\n=== map ===\n";
    std::map<std::string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"]   = 87;
    scores["Carol"] = 92;
    for (const auto& [name, score] : scores) {  // C++17 structured binding
        std::cout << name << ": " << score << "\n";
    }
    std::cout << "count(Alice): " << scores.count("Alice") << "\n";
    std::cout << "count(Dave):  " << scores.count("Dave")  << "\n";

    // --- set ---
    std::cout << "\n=== set ===\n";
    std::set<int> s = {5, 3, 1, 4, 1, 5, 9};  // 自动去重并排序
    for (int v : s) std::cout << v << " ";
    std::cout << "\n";

    // --- pair (对组) ---
    std::cout << "\n=== pair ===\n";
    std::pair<std::string, int> person{"Alice", 30};
    std::cout << person.first << " is " << person.second << "\n";
    auto [pname, page] = person;  // C++17 结构化绑定
    std::cout << pname << " is " << page << "\n";

    // --- stack ---
    std::cout << "\n=== stack (LIFO) ===\n";
    std::stack<int> stk;
    for (int i = 1; i <= 5; ++i) stk.push(i);
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "\n";

    // --- queue ---
    std::cout << "\n=== queue (FIFO) ===\n";
    std::queue<int> q;
    for (int i = 1; i <= 5; ++i) q.push(i);
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    // --- priority_queue (大顶堆) ---
    std::cout << "\n=== priority_queue (max-heap) ===\n";
    std::priority_queue<int> pq;
    pq.push(3); pq.push(1); pq.push(5); pq.push(2);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";  // 每次弹出最大值
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}
