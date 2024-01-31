#ifndef TUPLE_TYPE_LIST_HPP_
#define TUPLE_TYPE_LIST_HPP_

#include "tuple0.hpp"

template <typename List>
class IsEmpty {
public:
    static constexpr bool value = false;
};

// determine whether the tuple is empty:
template<>
struct IsEmpty<Tuple<>> {
    static constexpr bool value = true;
};

template <typename List>
class FrontT;

// extract front element:
template<typename Head, typename... Tail>
class FrontT<Tuple<Head, Tail...>> {
public:
    using Type = Head;
};

template <typename List>
class PopFrontT;

// remove front element:
template<typename Head, typename... Tail>
class PopFrontT<Tuple<Head, Tail...>> {
public:
    using Type = Tuple<Tail...>;
};

template <typename List, typename Element>
class PushFrontT;

template <typename... Types, typename Element>
class PushFrontT<Tuple<Types...>, Element> {
public:
    using Type = Tuple<Element, Types...>;
};

template <typename List, typename Element>
using PushFront = PushFrontT<List, Element>::Type;

template<typename List, typename NewElement>
class PushBackT;

// add element to the back:
template<typename... Types, typename Element>
class PushBackT<Tuple<Types...>, Element> {
public:
    using Type = Tuple<Types..., Element>;
};

template <typename List, typename Element>
using PushBack = PushBack<List, Element>::Type;

#endif