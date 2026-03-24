# C++ 学习笔记

## 目录

- [基础语法](#基础语法)
  - [变量与数据类型](#变量与数据类型)
  - [函数](#函数)
  - [面向对象](#面向对象)
- [标准库 STL](#标准库-stl)
  - [容器](#容器)
  - [算法](#算法)
- [现代 C++ 特性](#现代-c-特性)

---

## 基础语法

### 变量与数据类型

#### 基本类型

| 类型 | 大小 | 范围 |
|------|------|------|
| `int` | 4 字节 | -2³¹ ~ 2³¹-1 |
| `double` | 8 字节 | ±1.7×10³⁰⁸ |
| `char` | 1 字节 | 0 ~ 255 |
| `bool` | 1 字节 | true / false |
| `long long` | 8 字节 | -2⁶³ ~ 2⁶³-1 |

#### auto 类型推断（C++11）

```cpp
auto x = 42;          // int
auto y = 3.14;        // double
auto s = std::string{"hello"};  // string
```

#### 结构化绑定（C++17）

```cpp
std::pair<int, std::string> p{1, "one"};
auto [num, name] = p;  // num=1, name="one"

std::map<std::string, int> m;
for (auto& [key, val] : m) { ... }
```

#### 常量

```cpp
const int MAX = 100;         // 运行时常量
constexpr int SIZE = 256;    // 编译期常量（推荐）
```

---

### 函数

#### 函数重载

```cpp
int    add(int a, int b)    { return a + b; }
double add(double a, double b) { return a + b; }
// 根据参数类型自动选择
```

#### 模板函数

```cpp
template <typename T>
T max_of(T a, T b) { return a > b ? a : b; }

max_of(3, 7);       // int
max_of(3.0, 2.0);   // double
```

#### 默认参数

```cpp
int power(int base, int exp = 2);
power(3);     // 3² = 9
power(2, 10); // 2¹⁰ = 1024
```

#### Lambda 表达式（C++11）

```cpp
auto square = [](int n) { return n * n; };
auto add    = [](int a, int b) -> int { return a + b; };

// 捕获外部变量
int offset = 10;
auto add_offset = [offset](int x) { return x + offset; };  // 值捕获
auto inc        = [&offset](int x) { return x + offset; }; // 引用捕获
```

---

### 面向对象

#### 类基础

```cpp
class Shape {
public:
    virtual ~Shape() = default;       // 虚析构（必须）
    virtual double area() const = 0;  // 纯虚函数 → 抽象类
    virtual std::string name() const = 0;
};
```

#### 继承与多态

```cpp
class Circle : public Shape {
public:
    explicit Circle(double r) : radius_(r) {}
    double area() const override { return PI * radius_ * radius_; }
    std::string name() const override { return "Circle"; }
private:
    double radius_;
};
```

#### 智能指针（C++11，推荐替代裸指针）

```cpp
// unique_ptr：独占所有权
auto p = std::make_unique<Circle>(5.0);

// shared_ptr：共享所有权
auto p1 = std::make_shared<Circle>(3.0);
auto p2 = p1;  // 引用计数 +1

// 多态容器
std::vector<std::unique_ptr<Shape>> shapes;
shapes.push_back(std::make_unique<Circle>(5.0));
shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
```

---

## 标准库 STL

### 容器

| 容器 | 特点 | 适用场景 |
|------|------|----------|
| `vector<T>` | 动态数组，随机访问 O(1) | 最常用，默认首选 |
| `map<K,V>` | 红黑树，有序，O(log n) | 需要有序键值对 |
| `unordered_map<K,V>` | 哈希表，无序，O(1) | 只查找，不关心顺序 |
| `set<T>` | 自动排序+去重 | 集合运算 |
| `deque<T>` | 双端队列 | 两端频繁增删 |
| `stack<T>` | LIFO | 括号匹配、DFS |
| `queue<T>` | FIFO | BFS |

```cpp
// vector 常用操作
std::vector<int> v = {1, 2, 3};
v.push_back(4);     // 末尾插入
v.pop_back();       // 末尾删除
v.size();           // 大小
v.empty();          // 是否为空
v[0];               // 随机访问（不检查越界）
v.at(0);            // 随机访问（检查越界）

// map 常用操作
std::map<std::string, int> m;
m["key"] = 1;
m.count("key");     // 是否存在（0 或 1）
m.find("key");      // 返回迭代器
m.erase("key");
```

### 算法

> 头文件 `<algorithm>` 和 `<numeric>`

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};

std::sort(v.begin(), v.end());              // 升序排序
std::sort(v.begin(), v.end(), std::greater<int>()); // 降序

std::find(v.begin(), v.end(), 4);           // 查找值
std::find_if(v.begin(), v.end(), [](int x){ return x > 3; }); // 条件查找

std::count(v.begin(), v.end(), 1);          // 统计个数
std::count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

std::transform(v.begin(), v.end(), v.begin(), [](int x){ return x * 2; });

int sum = std::accumulate(v.begin(), v.end(), 0);  // 求和
```

---

## 现代 C++ 特性

### 移动语义（C++11）

```cpp
std::string a = "hello";
std::string b = std::move(a);  // a 的资源转移给 b，a 变为空
// 避免深拷贝，提升性能
```

### nullptr（C++11）

```cpp
int* p = nullptr;  // 替代 NULL 或 0
```

### 范围 for（C++11）

```cpp
for (const auto& x : vec) { ... }  // 只读
for (auto& x : vec) { x *= 2; }    // 可修改
```

### if/switch 初始化语句（C++17）

```cpp
if (auto it = m.find("key"); it != m.end()) {
    // it 只在 if 块内有效
}
```

### std::optional（C++17）

```cpp
std::optional<int> find_value(bool found) {
    if (found) return 42;
    return std::nullopt;
}

auto val = find_value(true);
if (val) std::cout << *val;  // 42
```
