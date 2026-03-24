#ifndef SHAPES_H
#define SHAPES_H

#include <string>

// 抽象基类
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual std::string name() const = 0;
    void print() const;
};

class Circle : public Shape {
public:
    explicit Circle(double radius);
    double area() const override;
    std::string name() const override;

private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double area() const override;
    std::string name() const override;

private:
    double width_, height_;
};

#endif // SHAPES_H
