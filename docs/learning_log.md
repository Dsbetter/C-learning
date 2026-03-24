# 学习日志

## 格式说明

每次学习后记录在此，格式如下：

```
### YYYY-MM-DD
**主题：** xxx
**文件：** basics/0x_xxx/
**学到了：** 简短总结
**疑问：** 待解决的问题
```

---

## 记录

### 2026-03-24

**主题：** 项目初始化

**文件：** 项目整体结构

**学到了：**
- CMake 多级项目结构：根 CMakeLists.txt 通过 `add_subdirectory()` 管理子模块
- `target_include_directories` 比 `include_directories` 更规范（作用域更精确）
- `.gitignore` 应排除 `build/`、`bin/` 等生成目录

**疑问：**
- [ ] CMake 中 `PUBLIC` / `PRIVATE` / `INTERFACE` 的区别？
- [ ] 如何在 CMake 中引入第三方库（如 fmt、nlohmann_json）？

---

### 2026-03-24（笔记整理）

**主题：** C++ 完整知识体系整理

**文件：** `docs/cpp_notes.md`（全面扩充）、`basics/02_variables/`、`basics/03_functions/`、`libs/stl/`

**学到了：**
- **内存模型**：栈/堆/全局区/常量区/代码区五大区域；`new`/`delete` 会调用构造/析构函数，`malloc`/`free` 不会
- **引用**：底层是指针常量，必须初始化且不能改变指向；`const &` 是函数参数的最佳实践
- **OOP 深入**：深拷贝 vs 浅拷贝（Double Free 问题）；初始化列表比赋值更高效；虚函数表(vtable)与虚指针(vptr)实现动态多态
- **STL 补充**：`list`（双向链表）、`priority_queue`（大顶堆）、`pair`（对组）；函数对象与谓词；`std::greater<T>` 实现降序
- **Lambda 捕获**：值捕获在 Lambda 创建时固定值，引用捕获随变量变化
- **移动语义**：`std::move` 转移所有权，避免深拷贝；右值引用 `&&`
- **四种类型转换**：`static_cast` / `dynamic_cast` / `const_cast` / `reinterpret_cast` 各有适用场景
- **RAII**：`lock_guard`、智能指针均是 RAII 的典型应用

**疑问：**
- [ ] `std::weak_ptr` 打破循环引用的具体场景？
- [ ] `dynamic_cast` 失败时返回 `nullptr` vs 抛出异常的条件？
- [ ] 完美转发 `std::forward` 与 `std::move` 的区别？
