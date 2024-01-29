#ifndef LARGEST_TYPE_HPP_
#define LARGEST_TYPE_HPP_

#include <type_traits>

#include "typelist.hpp"

template <typename List>
class LargestTypeT;

template <typename List>
class LargestTypeT {
using namespace std;
private:
    using First = Front<List>;
    using Rest = typename LargestTypeT<PopFront<List>>::Type;
public:
    using Type = conditional<(sizeof(First) >= sizeof(Rest)), First, Rest>;
};

template <>
class LargestTypeT<Typelist<>> {
public:
    using Type = char;
};

template<typename List>
using LargestType = typename LargestTypeT<List>::Type;

#endif