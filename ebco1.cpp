#include <iostream>

class Empty {
	using Int = int; // type alias members don’t make a class nonempty
};

class EmptyToo : public Empty {
};

class EmptyThree : public EmptyToo {
};

int main() {
    std::cout << "sizeof(Empty): " << sizeof(Empty) << std::endl;
    std::cout << "sizeof(EmptyToo): " << sizeof(EmptyToo) << std::endl;
    std::cout << "sizeof(EmptyThree): " << sizeof(EmptyThree) << std::endl;
}
