#ifndef TYPELIST_FRONT_HPP_
#define TYPELIST_FRONT_HPP_

#include "typelist.hpp"

template <typename List>
class FrontT;

template <typename Head, typename... Tail>
class FrontT<Typelist<Head, Tail...>> {
public:
    using Type = Head;
};

template<typename List>
using Front = typename FrontT<List>::Type;

#endif