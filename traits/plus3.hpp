#ifndef PLUS3_HPP_
#define PLUS3_HPP_

#include <type_traits>
#include "hasplus.hpp"

template<typename T1, typename T2, bool = HasPlusT<T1, T2>::value>
struct PlusResultT {
    // primary template, used when HasPlusT yields true
    using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
struct PlusResultT<T1, T2, false> {
    // partial specialization, used otherwise
};

#endif