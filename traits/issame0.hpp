#ifndef IS_SAME0_HPP_
#define IS_SAME0_HPP_

template<typename T1, typename T2>
struct IsSameT {
    static constexpr bool value = false;
};

template<typename T>
struct IsSameT<T, T> {
    static constexpr bool value = true;
};

#endif