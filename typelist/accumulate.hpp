#ifndef ACCUMULATE_HPP_
#define ACCUMULATE_HPP_

#include "typelistisempty.hpp"
#include "typelistfront.hpp"
#include "typelistpopfront.hpp"

template <typename List, template<typename X, typename Y> class F, typename I, bool = IsEmpty<List>::value>
class AccumulateT {
public:
    using Type = I;
};

template <typename List, template<typename X, typename Y> class F, typename I>
class AccumulateT<List, F, I, false> : 
    public AccumulateT<PopFront<List>, F, typename F<I, Front<List>>::Type> {
};

template <typename List, template<typename X, typename Y> class F, typename I>
using Accumulate = typename AccumulateT<List, F, I>::Type;

#endif