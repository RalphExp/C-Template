#ifndef INSERT_SORTED_HPP_
#define INSERT_SORTED_HPP_

#include "typelistisempty.hpp"
#include "traits/ifthenelse.hpp"

using namespace std;

template <typename List, 
    typename Element, template<typename T, typename U> class Compare, bool = IsEmpty<List>::value>
class InsertSortedT : public PushFrontT<List, Element> {
};

// recursive case:
template <typename List, typename Element,
        template<typename T, typename U> class Compare>
class InsertSortedT<List, Element, Compare, false> {
// compute the tail of the resulting list:
private:
    using NewTail = typename conditional<Compare<Element, Front<List>>::value,
        IdentityT<List>, InsertSortedT<PopFront<List>, Element, Compare>>::Type;
    
    // compute the head of the resulting list:
    using NewHead = IfThenElse<Compare<Element, Front<List>>::value,
                               Element,
                               Front<List>>;
public:
    using Type = PushFront<NewTail, NewHead>;
};

template <typename List, typename Element,
           template<typename T, typename U> class Compare>
using InsertSorted = typename InsertSortedT<List, Element, Compare>::Type;

template <typename List, typename Element,
         template<typename T, typename U> class Compare>
class InsertSortedT<List, Element, Compare, false>
 : public IfThenElseT<Compare<Element, Front<List>>::value,
{};

#endif