#ifndef ACCUM_TRAIT2_HPP_
#define ACCUM_TRAIT2_HPP_

template<typename T>
struct AccumulationTraits {
    using AccT = T;
};

template<>
struct AccumulationTraits<char> {
    using AccT = int;
};

template<>
struct AccumulationTraits<short> {
    using AccT = int;
};

template<>
struct AccumulationTraits<int> {
    using AccT = long;
};

template<>
struct AccumulationTraits<unsigned int> {
    using AccT = unsigned long;
};

template<>
struct AccumulationTraits<float> {
    using AccT = double;
};

#endif