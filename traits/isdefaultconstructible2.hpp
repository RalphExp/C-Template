#ifndef ISDEFAULTCONSTRUCTIBLE2_HPP_
#define ISDEFAULTCONSTRUCTIBLE2_HPP_

#include "boolconstant.hpp"

template <typename T>
struct IsDefaultConstructibleHelper {
private:

    // Note that we can’t use the template parameter T in the 
    // first test() directly: This doesn’t work, however, because 
    // for any T, always, all member functions are substituted, 
    // so that for a type that isn’t default constructible, 
    // the code fails to compile instead of ignoring the first test()
    // overload. By passing the class template parameter T to a 
    // function template parameter U, we create a specific SFINAE 
    // context only for the second test() overload.

    // test() trying substitute call of a default constructor for T passed as U:
    template<typename U, typename = decltype(U())>
    static std::true_type test(void*);

    // test() fallback:
    template<typename>
    static std::false_type test(...);

public:
    using Type = decltype(test<T>(nullptr));
};

template<typename T>
struct IsDefaultConstructibleT : IsDefaultConstructibleHelper<T>::Type {
};

#endif