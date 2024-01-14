#ifndef ISDEFAULTCONSTRUCTABLE1_HPP_
#define ISDEFAULTCONSTRUCTABLE1_HPP_

#include "issame.hpp"

template <typename T>
struct IsDefaultConstructable {
private:

    // Note that we can’t use the template parameter T in the 
    // first test() directly: This doesn’t work, however, because 
    // for any T, always, all member functions are substituted, 
    // so that for a type that isn’t default constructible, 
    // the code fails to compile instead of ignoring the first test()
    // overload. By passing the class template parameter T to a 
    // function template parameter U, we create a specific SFINAE 
    // context only for the second test() overload.
    template <typename U, typename = decltype(U())>
    static char test(void*);

    template <typename>
    static long test(...);

public:
    static constexpr bool value = 
        IsSameT<decltype(test<T>(nullptr)), char>::value;
};

#endif