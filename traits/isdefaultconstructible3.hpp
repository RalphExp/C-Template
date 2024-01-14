#ifndef ISDEFAULTCONSTRUCTIBLE3_HPP_
#define ISDEFAULTCONSTRUCTIBLE3_HPP_

#include "issame.hpp"
#include <type_traits>

// template<typename...> 
// using VoidT = void;

template<typename, typename = std::void_t<>>
struct IsDefaultConstructibleT : std::false_type
{
};

template<typename T>
struct IsDefaultConstructibleT<T, std::void_t<decltype(T())>> : std::true_type
{
};

#endif