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
