# C++ 学习笔记（完整版）

## 目录

- [1. 内存模型与基础机制](#1-内存模型与基础机制)
- [2. 基础语法](#2-基础语法)
- [3. 函数与模板](#3-函数与模板)
- [4. 面向对象 (OOP)](#4-面向对象-oop)
- [5. 标准库 STL](#5-标准库-stl)
- [6. 现代 C++ 核心进阶](#6-现代-c-核心进阶)

---

## 1. 内存模型与基础机制

### 内存的几个区域

C++ 程序的内存布局主要分为以下五个区域：

| 区域 | 说明 |
|------|------|
| **栈区 (Stack)** | 由编译器自动分配释放，存放函数的参数值、局部变量等。高效但空间有限 |
| **堆区 (Heap)** | 由程序员手动分配和释放。若不释放会导致内存泄漏 |
| **全局/静态存储区** | 全局变量和 `static` 变量存储于此，程序结束后由系统释放 |
| **常量存储区** | 存放常量字符串等，不允许修改 |
| **代码区** | 存放函数体的二进制机器代码 |

### 动态内存管理 (New/Delete)

- **关键字**：`new` / `delete` 用于单个对象；`new[]` / `delete[]` 用于数组。
- **与 malloc/free 的区别**：
  - `new/delete` 是 C++ 运算符；`malloc/free` 是 C 标准库函数。
  - `new` 在分配内存后会自动调用对象的**构造函数**，`delete` 会调用**析构函数**；而 `malloc/free` 只处理纯粹的内存分配与释放。

```cpp
int* p = new int(42);
delete p;

int* arr = new int[10];
delete[] arr;
```

### 引用 (Reference)

- **本质**：引用是变量的别名，底层通过指针常量实现。声明时必须初始化，且不能改变指向。
- **常量引用**：`const Type&`，常用于函数参数，既能避免拷贝提升效率，又能防止数据被意外修改。
- **注意**：绝对不能返回局部变量的引用，因为局部变量在函数结束后会被销毁。

```cpp
int a = 10;
int& ref = a;   // ref 是 a 的别名
ref = 20;       // a 也变为 20

void print(const std::string& s);  // 常量引用参数：避免拷贝 + 防止修改
```

---

## 2. 基础语法

### 变量与数据类型

#### 基本类型

| 类型 | 大小 | 范围 |
|------|------|------|
| `int` | 4 字节 | -2^31 ~ 2^31-1 |
| `double` | 8 字节 | ±1.7×10^308 |
| `char` | 1 字节 | 0 ~ 255 |
| `bool` | 1 字节 | true / false |
| `long long` | 8 字节 | -2^63 ~ 2^63-1 |

#### 常量

```cpp
const int MAX = 100;         // 运行时常量
constexpr int SIZE = 256;    // 编译期常量（推荐）
```

#### auto 类型推断（C++11）

```cpp
auto x = 42;                    // int
auto y = 3.14;                  // double
auto s = std::string{"hello"};  // string
```

#### 结构化绑定（C++17）

```cpp
std::pair<int, std::string> p{1, "one"};
auto [num, name] = p;  // num=1, name="one"

std::map<std::string, int> m;
for (auto& [key, val] : m) { /* ... */ }
```

---

## 3. 函数与模板

### 函数重载

重载条件：同一作用域下，函数名相同，但参数的个数、类型或顺序不同。**返回值不同不能作为重载条件。**

原理：编译器在编译阶段通过"名称修饰 (Name Mangling)"将参数类型信息附加到函数名中。

```cpp
int    add(int a, int b)       { return a + b; }
double add(double a, double b) { return a + b; }
// 根据参数类型自动选择
```

### 默认参数

```cpp
int power(int base, int exp = 2);
power(3);     // 3^2 = 9
power(2, 10); // 2^10 = 1024
```

### 模板

允许编写与类型无关的代码，实现代码复用。

```cpp
template <typename T>
T max_of(T a, T b) { return a > b ? a : b; }

max_of(3, 7);       // int
max_of(3.0, 2.0);   // double
```

类模板常用于容器的实现，例如：`template <class T> class MyVector { /* ... */ };`

---

## 4. 面向对象 (OOP)

### 封装

将数据和操作数据的方法绑定在一起，隐藏内部实现细节。

| 访问权限 | 说明 |
|---------|------|
| `public` | 类内外均可访问 |
| `private` | 仅类内部成员函数和友元可访问 |
| `protected` | 类内部及子类可访问 |

核心概念：
- **构造函数与析构函数**：负责对象的初始化与清理。
- **深拷贝与浅拷贝**：默认拷贝是浅拷贝（逐字节复制）。当类中有指针成员时，浅拷贝会导致 Double Free 风险，必须重写拷贝构造函数和赋值运算符实现深拷贝。
- **初始化列表**：用于在构造函数体执行前初始化成员，效率更高。`const` 成员和引用成员 `&` 必须使用它初始化。
- **this 指针**：隐含的指针，指向调用成员函数的当前对象本身。
- **友元 (Friend)**：使用 `friend` 关键字，允许外部函数或类访问本类的私有成员。
- **运算符重载**：赋予内置运算符处理自定义数据类型的能力。

### 继承

代码复用机制，描述"Is-A"关系。通常使用 `public` 继承，保持父类的 `public` 和 `protected` 属性不变。

- **构造与析构顺序**：构造时先父类后子类；析构时先子类后父类。
- **同名成员**：子类会隐藏父类的同名成员，需通过 `Base::func()` 显式调用父类版本。
- **菱形继承与虚继承**：当两个子类继承同一父类，又有孙子类多重继承时，会产生数据冗余和二义性。通过 `virtual public Base` 虚继承解决。

### 多态

同一接口，多种实现。

- **静态多态**：编译期决定（函数重载、模板）。
- **动态多态**：运行期决定，通过虚函数 (`virtual`) 和继承实现。

**原理**：包含虚函数的类会由编译器生成一张虚函数表 (vtable)，对象内部持有一个虚指针 (vptr) 指向该表。运行时根据对象的实际类型，通过 vptr 查找并调用对应的函数地址。

```cpp
class Shape {
public:
    virtual ~Shape() = default;       // 虚析构（必须，防止内存泄漏）
    virtual double area() const = 0;  // 纯虚函数 → 抽象类
    virtual std::string name() const = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double r) : radius_(r) {}
    double area() const override { return 3.14159 * radius_ * radius_; }
    std::string name() const override { return "Circle"; }
private:
    double radius_;
};
```

---

## 5. 标准库 STL

### 容器

| 分类 | 容器 | 特点与适用场景 |
|------|------|--------------|
| 序列式 | `vector<T>` | 动态数组，随机访问 O(1)。最常用，默认首选 |
| 序列式 | `deque<T>` | 双端队列，两端频繁增删效率高 |
| 序列式 | `list<T>` | 双向链表，适合频繁在中间插入和删除 |
| 序列式 | `string` | 专门处理字符序列的封装 |
| 关联式 | `map<K,V>` | 红黑树，有序键值对，查找 O(log n) |
| 关联式 | `set<T>` | 红黑树，自动排序+去重，集合运算 |
| 无序关联 | `unordered_map<K,V>` | 哈希表，无序键值对，查找 O(1) |
| 无序关联 | `unordered_set<T>` | 哈希表，无序集合，查找 O(1) |
| 适配器 | `stack<T>` | LIFO（后进先出），用于括号匹配、DFS |
| 适配器 | `queue<T>` | FIFO（先进先出），用于 BFS |
| 适配器 | `priority_queue` | 优先队列（底层为堆），默认大顶堆 |

**对组**：`std::pair<T1, T2>`，将两个不同类型的数据组合成一个整体，常用于 map 的元素。

```cpp
// vector 常用操作
std::vector<int> v = {1, 2, 3};
v.push_back(4);     // 末尾插入
v.pop_back();       // 末尾删除
v.size();           // 大小
v.empty();          // 是否为空
v[0];               // 随机访问（不检查越界）
v.at(0);            // 随机访问（检查越界，抛出异常）

// map 常用操作
std::map<std::string, int> m;
m["key"] = 1;
m.count("key");     // 是否存在（0 或 1）
m.find("key");      // 返回迭代器，找不到返回 m.end()
m.erase("key");

// priority_queue（大顶堆）
std::priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(5);
std::cout << pq.top();  // 5
```

### 迭代器与函数对象

- **迭代器**：行为类似指针，是连接容器与算法的桥梁，用于遍历容器元素。
- **函数对象 (Functor)**：重载了 `operator()` 的类对象，可以像函数一样被调用。
- **谓词**：返回 `bool` 类型的函数对象（一元谓词接收1个参数，二元谓词接收2个）。
- **内建函数对象**：STL 提供的标准仿函数，如 `std::greater<T>`（降序）、`std::plus<T>`。

### 常用算法

> 需引入头文件 `<algorithm>` 和 `<numeric>`

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};

// 排序算法
std::sort(v.begin(), v.end());                      // 升序排序
std::sort(v.begin(), v.end(), std::greater<int>()); // 降序排序

// 查找算法
std::find(v.begin(), v.end(), 4);                   // 查找特定值
std::find_if(v.begin(), v.end(), [](int x){ return x > 3; }); // 条件查找

// 统计算法
std::count(v.begin(), v.end(), 1);                  // 统计特定值个数
std::count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

// 变换
std::transform(v.begin(), v.end(), v.begin(), [](int x){ return x * 2; });

// 算数生成
int sum = std::accumulate(v.begin(), v.end(), 0);   // 求和
```

---

## 6. 现代 C++ 核心进阶

### RAII（资源获取即初始化）

C++ 资源管理的核心思想。在对象的构造函数中申请资源，在析构函数中释放资源，利用局部对象离开作用域自动析构的特性来防止资源泄漏。

### 异常处理

使用 `try`, `catch`, `throw` 机制。**注意**：析构函数中绝对不能抛出异常。

### 智能指针（C++11，推荐替代裸指针）

基于 RAII 思想实现，自动管理内存。

| 智能指针 | 说明 |
|---------|------|
| `std::unique_ptr` | 独占所有权，不可复制，只能转移 (`move`) |
| `std::shared_ptr` | 共享所有权，基于引用计数，计数归零时释放内存 |
| `std::weak_ptr` | 配合 `shared_ptr` 使用，不增加引用计数，用于打破循环引用 |

```cpp
auto p = std::make_unique<Circle>(5.0);          // 独占
auto p1 = std::make_shared<Circle>(3.0);         // 共享
auto p2 = p1;                                    // 引用计数 +1

std::vector<std::unique_ptr<Shape>> shapes;
shapes.push_back(std::make_unique<Circle>(5.0)); // 多态容器
```

### 右值引用与移动语义（C++11）

大幅提升性能，避免无意义的深拷贝。

- **右值引用 (`&&`)**：绑定到即将销毁的临时对象（右值）。
- **`std::move`**：将左值无条件转换为右值引用。
- **移动构造/赋值**：直接"接管"右值的内存资源，将原对象的指针置空。

```cpp
std::string a = "hello";
std::string b = std::move(a);  // a 的资源转移给 b，a 变为空
```

### Lambda 表达式（C++11）

轻量级的匿名函数对象，配合 STL 算法极其方便。

```cpp
auto square = [](int n) { return n * n; };
auto add    = [](int a, int b) -> int { return a + b; };

// 捕获外部变量
int offset = 10;
auto add_offset = [offset](int x) { return x + offset; };  // 值捕获
auto inc        = [&offset](int x) { return x + offset; }; // 引用捕获
```

### 更安全的类型转换

放弃 C 风格强转 `(Type)value`，使用以下四种：

| 转换 | 用途 |
|------|------|
| `static_cast` | 基础数据类型转换，或继承关系的上行转换（安全） |
| `dynamic_cast` | 多态类的向下转换，运行时类型安全检查（依赖 RTTI） |
| `const_cast` | 专门用于移除 `const` 或 `volatile` 属性 |
| `reinterpret_cast` | 极不安全，用于底层的位模式重新解释（如指针转整型） |

### 内存模型与多线程（C++11）

```cpp
#include <thread>
#include <mutex>

std::mutex mtx;

void safe_print(int id) {
    std::lock_guard<std::mutex> lock(mtx);  // RAII 风格的锁，自动解锁
    std::cout << "Thread " << id << "\n";
}
```

### 范围 for 与初始化语句

```cpp
// 范围 for (C++11)
for (const auto& x : vec) { /* 只读 */ }
for (auto& x : vec) { x *= 2; /* 可修改 */ }

// if/switch 初始化语句 (C++17)
if (auto it = m.find("key"); it != m.end()) {
    // it 只在 if 块内有效，避免污染外部作用域
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
