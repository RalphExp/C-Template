template<typename T>
struct AccumulationTraits;

template<>
struct AccumulationTraits<char> {
    using AccT = int;
    static AccT constexpr zero() {
        return 0;
    }
};

template<>
struct AccumulationTraits<short> {
    using AccT = int;
    static AccT constexpr zero() {
        return 0;
    }
};

template<>
struct AccumulationTraits<int> {
    using AccT = long;
    static AccT constexpr zero() {
        return 0;
    }
};

template<>
struct AccumulationTraits<unsigned int> {
    using AccT = unsigned long;
    static AccT constexpr zero() {
        return 0;
    }
};

template<>
struct AccumulationTraits<float> {
    using AccT = double;
    static AccT constexpr zero() {
        return 0;
    }
};

template<>
struct AccumulationTraits<double> {
    using AccT = double;
    static AccT constexpr zero() {
        return 0;
    }
};

