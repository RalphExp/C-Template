#ifndef GENERIC_LARGEST_TYPE_HPP_
#define GENERIC_LARGEST_TYPE_HPP_

#include "typelistisempty.hpp"
#include "typelist.hpp"

#include <type_traits>

template<typename List, bool Empty = IsEmpty<List>::value>
class LargestTypeT {
public:
    using Type = char;
};

// recursive case:
template <typename List>
class LargestTypeT<List, false> {
using namespace std;
private:
    using Contender = Front<List>;
    using Best = typename LargestTypeT<PopFront<List>>::Type;
public:
    using Type = conditional<(sizeof(Contender) >= sizeof(Best)), Contender, Best>;
};

template<typename List>
using LargestType = typename LargestTypeT<List>::Type;

#endif