#include "hello.h"
#include <iostream>

// initializer list
Greeter::Greeter(std::string name) : name_(std::move(name)) {}

// implementation of greet method
void Greeter::greet() const {
    std::cout << "Hello, " << name_ << "!\n";
}

int main() {
    Greeter g("World");
    g.greet();
    return 0;
}
