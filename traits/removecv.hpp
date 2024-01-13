#ifndef REMOVECV_HPP_
#define REMOVECV_HPP_

#include "removeconst.hpp"
#include "removevolatile.hpp"

template<typename T>
struct RemoveCVT : RemoveConstT<typename RemoveVolatileT<T>::Type> {};

template<typename T>
using RemoveCV = typename RemoveCVT<T>::Type;

#endif