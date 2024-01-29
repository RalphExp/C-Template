#ifndef IF_THEN_ELSE_HPP_
#define IF_THEN_ELSE_HPP_

// primary template: yield the second argument by default and rely on
// a partial specialization to yield the third argument
// if COND is false

// Note:
// The IfThenElseT template is available in the C++ standard library as std::conditional<>

#include <type_traits>

using namespace std;

template <bool Cond, typename TrueType, typename FalseType>
struct IfThenElseT {
    using Type = TrueType;
};

template <typename TrueType, typename FalseType>
struct IfThenElseT<false, TrueType, FalseType> {
    using Type = FalseType;
};

template<bool Cond, typename TrueType, typename FalseType>
using IfThenElse = typename IfThenElseT<Cond, TrueType, FalseType>::Type; 

#endif