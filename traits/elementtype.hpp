#ifndef ELEMENT_TYPE_HPP_H
#define ELEMENT_TYPE_HPP_H_

#include <vector>
#include <list>

template <typename T>
struct ElementT {
    using Type = typename T::value_type;
};

template <typename T>
struct ElementT<std::vector<T>> { // partial specialization for std::vector
    using Type = T;
};

template<typename T>
struct ElementT<std::list<T>> { // partial specialization for std::list
    using Type = T;
};

template<typename T, std::size_t N>
    struct ElementT<T[N]> { // partial specialization for arrays of known bounds
    using Type = T;
};

template<typename T>
struct ElementT<T[]> { // partial specialization for arrays of unknown bounds
    using Type = T;
};

template<typename T>
using ElementType = typename ElementT<T>::Type;

#endif