#ifndef ADD_CONST_HPP_
#define ADD_CONST_HPP_

template<typename T>
struct AddConstT {
    using Type = T const;
};
  
template<typename T>
using AddConst = typename AddConstT<T>::Type;

#endif