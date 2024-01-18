#include "traits/smallestint.hpp"

#include <typeinfo>
#include <iostream>

using namespace std;

int main() {
    cout << boolalpha;
    cout << "92: " << typeid(SmallestIntT<92>::Type).name() << endl; // c
    cout << "922: " << typeid(SmallestIntT<922>::Type).name() << endl; // s
    cout << "92222: " << typeid(SmallestIntT<92222>::Type).name() << endl; // i
    cout << "9222222222222: " << typeid(SmallestIntT<9222222222222>::Type).name() << endl; // l
    cout << "9222222222222222222: " << typeid(SmallestIntT<9222222222222222222>::Type).name() << endl; // v
}