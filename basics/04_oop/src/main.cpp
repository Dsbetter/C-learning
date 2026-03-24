#include "shapes.h"
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

constexpr double PI = 3.14159265358979323846;

void Shape::print() const {
    std::cout << name() << ": area = " << area() << "\n";
}

Circle::Circle(double r) : radius_(r) {}
double Circle::area() const { return PI * radius_ * radius_; }
std::string Circle::name() const { return "Circle(r=" + std::to_string(radius_) + ")"; }

Rectangle::Rectangle(double w, double h) : width_(w), height_(h) {}
double Rectangle::area() const { return width_ * height_; }
std::string Rectangle::name() const {
    return "Rectangle(" + std::to_string(width_) + "x" + std::to_string(height_) + ")";
}

int main() {
    // 多态：用基类指针管理派生类对象
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(3.0));

    for (const auto& s : shapes) {
        s->print();
    }

    return 0;
}
