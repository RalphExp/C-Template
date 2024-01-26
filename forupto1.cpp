#include <vector>
#include <iostream>
#include <functional>
#include <type_traits>
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
    // FunctionPtr<void(void)> v = &printInt;
}