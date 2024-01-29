#ifndef TYPELIST_PUSH_FRONT_HPP_
#define TYPELIST_PUSH_FRONT_HPP_

#include "typelist.hpp"

template<typename List, typename NewElement>
class PushFrontT;

template<typename... Elements, typename NewElement>
class PushFrontT<Typelist<Elements...>, NewElement> {
public:
    using Type = Typelist<NewElement, Elements...>;
};
  
template<typename List, typename NewElement>
using PushFront = typename PushFrontT<List, NewElement>::Type;

#endif