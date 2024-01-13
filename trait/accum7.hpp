#ifndef ACCUM7_HPP_
#define ACCUM7_HPP_

#include "accumtraits4.hpp"
#include "sumpolicy2.hpp"

template<typename T, 
    template<typename, typename> class Policy = SumPolicy,
    typename Traits = AccumulationTraits<T>>

auto accum (T const* beg, T const* end) {
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero();
    
    while (beg != end) {
        Policy<AccT, T>::accumulate(total, *beg);
        ++beg;
    }
    return total;
}

#endif // ACCUM7_HPP
