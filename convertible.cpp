#include "traits/isconvertible.hpp"

int main() {
    bool c = isConvertible<int, long>;
    std::cout << std::boolalpha;
    std::cout << "from int to long: " << c << std::endl;

    c = isConvertible<long, int>;
    std::cout << "from long to int: " << c << std::endl;

    c = isConvertible<int, int&>;
    std::cout << "from int to int&: " << c << std::endl;

    c = isConvertible<int[2], int[2]>;
    std::cout << "from int[2] to int[2]: " << c << std::endl;

    c = isConvertible<int[2], int*>;
    std::cout << "from int[2] to int*: " << c << std::endl;

    c = isConvertible<int*, int[2]>;
    std::cout << "from int[2] to int*: " << c << std::endl;
}