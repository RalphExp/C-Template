#include "traits/hassizetype.hpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    bool c = HasSizeType<int>::value;
    cout << boolalpha;
    cout << "int has size type: " << c << endl;

    c = HasSizeType<vector<int>>::value;
    cout << "vector<int> has size_type: " << c << endl;

}