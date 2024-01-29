#ifndef IS_RVALUE_REFERENCE_HPP_
#define IS_RVALUE_REFERENCE_HPP_

#include <type_traits>

template <typename T>
struct IsRValueReferenceT : std::false_type {
};

template<typename T>
struct IsRValueReferenceT<T&&> : std::true_type {
    using BaseT = T; // type referring to 
};

#endif