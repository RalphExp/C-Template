#include "elementtype.hpp"
#include <iostream>
#include <typeinfo>

template<typename T>
void printElementType (T const& c) {
    std::cout << "Container of "
        << typeid(ElementType<T>).name()
        << " elements.\n";
}

int main() {
    std::vector<bool> s;

    printElementType(s);
    
    int arr[42];
    printElementType(arr);
}