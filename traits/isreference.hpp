#ifndef ISREFERENCE_HPP_
#define ISREFERENCE_HPP_

#include "islvaluereference.hpp"
#include "isrvaluereference.hpp"
#include "ifthenelse.hpp"
  
template<typename T>
class IsReferenceT : public IfThenElseT<IsLValueReferenceT<T>::value,
                        IsLValueReferenceT<T>,
                        IsRValueReferenceT<T>>::Type {
};

#endif