#include <iostream>

using namespace std;

class A {
public:
    // A() : a_(9), b_(22) {}
    int a_ = 42;
    int b_ = 100;
};

int main() {
    A a;
    // output 42, 100
    cout << a.a_ << ", " << a.b_ << endl;
}
