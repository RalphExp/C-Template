#ifndef GENERIC_PUSH_BACK_HPP_
#define GENERIC_PUSH_BACK_HPP_

#include "typelist.hpp"
#include "typelistisempty.hpp"

template <typename List, typename NewElement, bool = IsEmpty<List>::value> 
class PushBackRecT {
public:
    using Type = PushFront<List, NewElement>;
};

template <typename List, typename NewElement>
class PushBackRecT<List, NewElement, false> {
private:
    using Head = Front<List>;
    using Tail = PopFront<List>;
    using NewTail = typename PushBackRecT<Tail, NewElement>::Type;
public:
    using Type = PushFront<Head, NewTail>;
};

// generic push-back operation:
template <typename List, typename NewElement>
class PushBackT : public PushBackRecT<List, NewElement> {
};

template<typename List, typename NewElement>
using PushBack = typename PushBackT<List, NewElement>::Type;

#endif
