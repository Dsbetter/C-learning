#ifndef HELLO_H
#define HELLO_H

#include <string>

class Greeter {
public:
    // avoid implicit conversion to string
    explicit Greeter(std::string name);
    //use const to ensure that the method does not modify the object
    void greet() const;

private:
    std::string name_;
};

#endif // HELLO_H
