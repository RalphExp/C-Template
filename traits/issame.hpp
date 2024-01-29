#ifndef IS_SAME_HPP_
#define IS_SAME_HPP_

#include "boolconstant.hpp"

template<typename T1, typename T2>
struct IsSameT : FalseType
{
};

template<typename T>
struct IsSameT<T, T> : TrueType
{
};

template<typename T1, typename T2>
using IsSame = typename IsSameT<T1, T2>::Type;

#endif