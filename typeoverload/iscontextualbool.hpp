#ifndef ISCONTEXTUALBOOL_HPP_
#define ISCONTEXTUALBOOL_HPP_

#include <utility> // for declval()
#include <type_traits> // for true_type and false_type
#include <iostream>
  
template<typename T>
class IsContextualBoolT {
private:
    template<typename S> struct Identity;

    template<typename U> 
    static std::true_type test(Identity<decltype(declval<U>() ? 0 : 1)>*);

    template<typename U> static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};
  
template<typename T>
static constexpr bool IsContextualBool = IsContextualBoolT<T>::value;

#endif