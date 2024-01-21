#ifndef UNSIGNED_HPP_
#define UNSIGNED_HPP_

#include "ifthenelse.hpp"

// There is a standard trait, std::make_unsigned, which does this conversion, 
// but it requires that the passed type is a signed integral type and no bool; 
// otherwise its use results in undefined behavior (see Section D.4 on page 729). 
// So it might be a good idea to implement a trait that yields the corresponding 
// unsigned type if this is possible and the passed type otherwise 
// (thus, avoiding undefined behavior if an inappropriate type is given). 
// The naive implementation does not work:

// template<typename T>
// struct UnsignedT {
//      using Type = IfThenElse<std::is_integral<T>::value
//                                && !std::is_same<T,bool>::value,
//                              typename std::make_unsigned<T>::type,
//                              T>;
// };


// yield T when using member Type: 
template <typename T>
struct IdentityT {
    using Type = T;
};

// to make unsigned after IfThenElse was evaluated:
template <typename T>
struct MakeUnsignedT {
    using Type = typename std::make_unsigned<T>::type;
};

// In this definition of UnsignedT, the type arguments to IfThenElse are 
// both instances of type func- tions themselves. However, the type functions
// are not actually evaluated before IfThenElse se- lects one. Instead, 
// IfThenElse selects the type function instance (of either MakeUnsignedT or IdentityT). 
// The ::Type then evaluates the selected type function instance to produce Type.
template<typename T>
struct UnsignedT {
    using Type = typename IfThenElse<std::is_integral<T>::value && !std::is_same<T,bool>::value,
        MakeUnsignedT<T>, IdentityT<T>>::Type;
};

#endif