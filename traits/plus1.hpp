#ifndef PLUS1_HPP_
#define PLUS1_HPP_

template<typename T1, typename T2>
struct PlusResultT {
    using Type = decltype(T1() + T2());
};

template<typename T1, typename T2>
using PlusResult = typename PlusResultT<T1, T2>::Type;

#endif