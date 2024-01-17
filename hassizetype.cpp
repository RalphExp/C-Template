#include "traits/hassizetype.hpp"

#include <vector>
#include <iostream>

using namespace std;

struct size_type {
};
struct Sizeable : size_type {
};

int main() {
    // static_assert(HasSizeTypeT<Sizeable>::value, "Compiler bug: Injected class name missing");

    bool c = HasSizeTypeT<int>::value;
    cout << boolalpha;
    cout << "int has size type: " << c << endl;

    c = HasSizeTypeT<vector<int>>::value;
    cout << "vector<int> has size_type: " << c << endl;
}