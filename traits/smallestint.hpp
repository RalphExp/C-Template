#ifndef SMALLESTINT_HPP_
#define SMALLESTINT_HPP_

#include "ifthenelse.hpp"

#include <limits>

template<auto N>
struct SmallestIntT {
  using Type =
    typename IfThenElseT<N <= std::numeric_limits<char>::max(), char,
      typename IfThenElseT<N <= std::numeric_limits<short>::max(), short,
        typename IfThenElseT<N <= std::numeric_limits<int>::max(), int,
          typename IfThenElseT<N <= std::numeric_limits<long>::max(), long,
            typename IfThenElseT<N <= std::numeric_limits<long long>::max(), long long, // then
              void // fallback
            >::Type // longlong
          >::Type // long
        >::Type // int
      >::Type // short
    >::Type;// char
};

#endif