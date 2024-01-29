#ifndef LARGEST_ACC_HPP_
#define LARGEST_ACC_HPP_

#include <type_traits>

#include "accumulate.hpp"

using namespace std;

template<typename T, typename U>
class LargerTypeT : public conditional<sizeof(T) >= sizeof(U), T, U> {
};

template<typename Typelist, bool = IsEmpty<Typelist>::value>
class LargestTypeAccT {
};
  
template<typename Typelist>
class LargestTypeAccT<Typelist, false> 
    : public AccumulateT<PopFront<Typelist>, LargerTypeT, Front<Typelist>> {    
};

template<typename Typelist>
using LargestTypeAcc = typename LargestTypeAccT<Typelist>::Type;

#endif