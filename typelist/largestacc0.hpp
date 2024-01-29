#ifndef LARGEST_ACC0_HPP_
#define LARGEST_ACC0_HPP_

#include <type_traits>

#include "accumulate.hpp"

template<typename T, typename U>
class LargerTypeT : public std::conditional<sizeof(T) >= sizeof(U), T, U> {
    using Type = type;
};

template<typename Typelist>
class LargestTypeAccT : public AccumulateT<PopFront<Typelist>, LargerTypeT, Front<Typelist>> { 
};

#endif
