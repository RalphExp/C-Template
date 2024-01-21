#ifndef ISLVALUEREFERENCE_HPP_
#define ISLVALUEREFERENCE_HPP_

#include <type_traits>

template <typename T>
struct IsLValueReferenceT : std::false_type {
};

template<typename T>
struct IsLValueReferenceT<T&> : std::true_type {
    using BaseT = T; // type referring to 
};

#endif