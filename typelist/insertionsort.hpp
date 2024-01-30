#ifndef INSERTION_SORT_HPP_
#define INSERTION_SORT_HPP_

#include "typelist.hpp"
#include "typelistisempty.hpp"
#include "insertsorted.hpp"

template <typename List, template<typename T, typename U> class Compare, bool = IsEmpty<List>::value>
class InsertionSortT {
public:
    using Type = List;
};

template <typename List, template<typename T, typename U> class Compare>
using InsertionSort = typename InsertionSortT<List, Compare>::Type;

template <typename List, template<typename T, typename U> class Compare>
class InsertionSortT<List, Compare, false> : 
    public InsertSortedT<InsertionSort<PopFront<List>, Compare>, Front<List>, Compare> { 
};


#endif