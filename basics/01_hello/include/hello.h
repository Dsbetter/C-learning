#ifndef HELLO_H
#define HELLO_H

#include <string>

class Greeter {
public:
    explicit Greeter(std::string name);
    void greet() const;

private:
    std::string name_;
};

#endif // HELLO_H
