#ifndef MAKE_TUPLE_HPP_
#define MAKE_TUPLE_HPP_

#include <type_traits>

template<typename... Types>
auto makeTuple(Types&&... elems) {
    return Tuple<std::decay_t<Types>...>(std::forward<Types>(elems)...);
}

#endif