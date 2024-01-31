#ifndef PUSH_BACK_HPP_
#define PUSH_BACK_HPP_

#include "tupletypelist.hpp"

template<typename V>
Tuple<V> pushBack(Tuple<> const&, V const& value)
{
    return Tuple<V>(value);
}

template<typename Head, typename... Tail, typename V>
Tuple<Head, Tail..., V>
pushBack(Tuple<Head, Tail...> const& tuple, V const& value)
{
    return Tuple<Head, Tail..., V>(tuple.getHead(), 
        pushBack(tuple.getTail(), value));
}

#endif