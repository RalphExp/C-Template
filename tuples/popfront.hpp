#ifndef POP_FRONT_HPP_
#define POP_FRONT_HPP_

#include "tupletypelist.hpp"

template<typename... Types>
PopFront<Tuple<Types...>>
popFront(Tuple<Types...> const& tuple)
{
    return tuple.getTail();
}

#endif