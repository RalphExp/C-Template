#include "traits/isconvertible.hpp"

int main() {
    bool c = isConvertible<int, long>;
    std::cout << std::boolalpha;
    std::cout << "from int to long: " << c << std::endl;

    c = isConvertible<long, int>;
    std::cout << "from long to int: " << c << std::endl;

    c = isConvertible<int, int&>;
    std::cout << "from int to int&: " << c << std::endl;
}