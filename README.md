# Cpp_learn

C++ 学习项目，使用多级 CMake 组织结构。

## 项目结构

```
Cpp_learn/
├── CMakeLists.txt          # 根 CMake（C++17，全局配置）
├── basics/                 # C++ 基础语法学习
│   ├── CMakeLists.txt
│   ├── 01_hello/           # Hello World & 类基础
│   ├── 02_variables/       # 变量、数据类型、auto、结构化绑定
│   ├── 03_functions/       # 函数重载、模板、Lambda
│   └── 04_oop/             # 面向对象、继承、多态、智能指针
└── libs/                   # 库学习
    ├── CMakeLists.txt
    └── stl/                # C++ 标准模板库
        ├── containers.cpp  # vector, map, set, stack...
        └── algorithms.cpp  # sort, transform, accumulate...
```

## 构建

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

可执行文件输出到 `bin/` 目录。

## 扩展新主题

### 添加 basics 子模块
1. 在 `basics/` 下创建目录，如 `05_templates/`
2. 添加 `CMakeLists.txt`，内容参考已有示例
3. 在 `basics/CMakeLists.txt` 末尾加 `add_subdirectory(05_templates)`

### 添加第三方库
在 `libs/CMakeLists.txt` 中取消对应 `add_subdirectory` 的注释，并按需配置。

## 环境要求

- CMake >= 3.16
- C++17 兼容编译器（GCC 7+, Clang 5+, MSVC 2017+）
