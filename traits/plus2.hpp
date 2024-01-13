#ifndef PLUS2_HPP_
#define PLUS2_HPP_

template<typename T1, typename T2>
struct PlusResultT {
    using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
using PlusResult = typename PlusResultT<T1, T2>::Type;

#endif