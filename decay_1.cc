#include <iostream>
#include <typeinfo>
#include <type_traits>

template<typename T>
struct RemoveConstT {
	using Type = T;
};

template<typename T>
struct RemoveConstT<T const> {
	using Type = T;
};

template<typename T>
using RemoveConst = typename RemoveConstT<T>::Type;


template<typename T>
struct RemoveVolatileT {
	using Type = T;
};

template<typename T>
struct RemoveVolatileT<T volatile> {
	using Type = T;
};

template<typename T>
using RemoveVolatile = typename RemoveVolatileT<T>::Type;

template<typename T>
struct RemoveCVT : RemoveConstT<typename RemoveVolatileT<T>::Type> {
};

template<typename T>
using RemoveCV = typename RemoveCVT<T>::Type;

template<typename T>
struct DecayT : RemoveCVT<T> {
};

template<typename T>
struct DecayT<T[]> {
	using Type = T*;
};

template<typename T, std::size_t N>
struct DecayT<T[N]> {
	using Type = T*;
};

template<typename R, typename... Args>
struct DecayT<R(Args...)> {
	using Type = R (*)(Args...);
};

template<typename R, typename... Args>
struct DecayT<R(Args......)> {
	using Type = R (*)(Args......);
};

template<typename T>
void printDecayedType()
{
	using A = typename DecayT<T>::Type;
    std::cout << "Parameter type: " << typeid(A).name() << '\n';
    std::cout << "- is int: " << std::is_same<A,int>::value << '\n';
    std::cout << "- is const: " << std::is_const<A>::value << '\n';
    std::cout << "- is pointer: " << std::is_pointer<A>::value << '\n';
}

int main()
{
    printDecayedType<int>();
    printDecayedType<int const>();
    printDecayedType<int[7]>();
    printDecayedType<int(int)>();
}

