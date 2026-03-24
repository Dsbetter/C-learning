#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// 函数重载
int    add(int a, int b);
double add(double a, double b);

// 模板函数
template <typename T>
T max_of(T a, T b) {
    return a > b ? a : b;
}

// 默认参数
int power(int base, int exp = 2);

#endif // MATH_UTILS_H
