#ifndef SUMPOLICY1_HPP_
#define SUMPOLICY1_HPP_

class SumPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate(T1& total, T2 const& value) {
        total += value;
    }
};

#endif // SUMPOLICY1_HPP_