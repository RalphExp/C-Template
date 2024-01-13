#include <iostream>

#include "traits/accum7.hpp"

template<typename T1, typename T2>
class MultPolicy {
public:
    static void accumulate (T1& total, T2 const& value) {
        total *= value;
    }
};

int main() {
    // create array of 5 integer values
    int num[] = { 1, 2, 3, 4, 5 };
    // print product of all values
    std::cout << "the sum of the integer values is "
        << accum<int, SumPolicy>(num, num+5)
        << '\n';

    std::cout << "the product of the integer values is "
        << accum<int, MultPolicy>(num, num+5,1)
        << '\n';
}
