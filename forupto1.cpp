#include <vector>
#include <iostream>
#include <functional>
#include <type_traits>

using namespace std;

template <typename F>
void forUpTo(int n, F f)
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
}