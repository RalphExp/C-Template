#ifndef PUSH_FRONT_HPP_
#define PUSH_FRONT_HPP_

#include "tupletypelist.hpp"

template<typename... Types, typename V>
Tuple<Types..., V>
pushFront(Tuple<Types...> const& tuple, V const& value)
{
    return Tuple<Types...>, V>(value, tuple);
}

#endif