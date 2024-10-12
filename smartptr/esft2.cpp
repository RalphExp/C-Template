#include <iostream>
#include <string>
#include <vector>
#include <memory>

class A : public std::enable_shared_from_this<A> {
public:
    int a;
    std::shared_ptr<A> s() { return shared_from_this(); }
};

std::shared_ptr<A> sp;

void f() { 
    std::shared_ptr<A> a = std::make_shared<A>();
    sp = a->s(); // ok

    std::cout << "OK" << std::endl;

    A b;
    sp = b.s(); // BAD WEAK POINTER

    std::cout << "never reach here" << std::endl;
}

int main() {
    try {
        f();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
} 