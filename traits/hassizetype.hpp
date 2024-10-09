#ifndef HASSIZETYPE_HPP_
#define HASSIZETYPE_HPP_

#include <type_traits>

#include "removereference.hpp"

using namespace std;

template <typename T, typename = void_t<>>
struct HasSizeTypeT : false_type {
};

template <typename T>
struct HasSizeTypeT<T, void_t<typename RemoveReference<T>::size_type>> : true_type {
};

#endif