#ifndef REMOVE_CONST_HPP_
#define REMOVE_CONST_HPP_

template<typename T>
struct RemoveConstT {
    using Type = T;
};

template<typename T>
struct RemoveConstT<T const> {
    using Type = T;
};

template<typename T>
using RemoveConst = typename RemoveConstT<T>::Type;

#endif