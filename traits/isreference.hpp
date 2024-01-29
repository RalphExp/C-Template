#ifndef IS_REFERENCE_HPP_
#define IS_REFERENCE_HPP_

#include "islvaluereference.hpp"
#include "isrvaluereference.hpp"
#include "ifthenelse.hpp"
  
template<typename T>
class IsReferenceT : public IfThenElseT<IsLValueReferenceT<T>::value,
                        IsLValueReferenceT<T>,
                        IsRValueReferenceT<T>>::Type {
};

#endif