
#include "accum2.hpp"
#include <iostream>

int main() {
    // create array of 5 integer values
    int num[] = { 1, 2, 3, 4, 5 };

    std::cout << "the average value of the integer values is "
        << accum(num, num+5) / 5
        << '\n';

    // create array of character values
    char name[] = "templates";
    int length = sizeof(name)-1;
    // (try to) print average character value
    std::cout << "the average value of the characters in \""
        << name << "\" is "
        << accum(name, name+length) / length
        << '\n';

    double dnum[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::cout << "the average value of the floating point values is "
        << accum(dnum, dnum+5) / 6
        << '\n';
}