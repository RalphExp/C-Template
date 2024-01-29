#include <vector>
#include <iostream>
#include <functional>
#include <type_traits>
#include <functional>
#include <tuple>

#include "bridge/functionptr.hpp"

using namespace std;

void forUpTo(int n, FunctionPtr<void(int)> f)
{
    for (int i = 0; i != n; ++i) {
        f(i);
    }
}

void printInt(int i)
{
    cout << i << ' ';
}

class A {
public:
    A() {};

    void operator()(int) { return; };
};

int main() {
    vector<int> values;
    // insert values from 0 to 4:
    forUpTo(5, [&values](int i) { 
        values.push_back(i);
    });
    
    // print elements: 0 1 2 3 4
    forUpTo(5, printInt);
    cout << endl;

    // 
    FunctionPtr<void(int)> v = printInt;
    cout << boolalpha << (v == v) << endl; 

    FunctionPtr<void(int)> v2 = [&values](int){};
    cout << boolalpha << (v2 == v2) << endl;
}
