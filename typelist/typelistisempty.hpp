#ifndef TYPELIST_EMPTY_HPP_
#define TYPELIST_EMPTY_HPP_

#include "typelist.hpp"

template <typename List>
class IsEmpty {
public:
    static constexpr bool value = false;
};

template <>
class IsEmpty<Typelist<>> {
public:
    static constexpr bool value = true;
};

#endif