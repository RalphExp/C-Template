
#include <type_traits>

#include "removereference.hpp"

using namespace std;

template <typename T, typename = void_t<>>
struct HasSizeTypeT : true_type {

};

template <typename T>
struct HasSizeTypeT<T, void_t<typename RemoveReference<T>::size_type>> : false_type {

};