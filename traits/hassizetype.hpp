
#include <type_traits>

using namespace std;

template <typename T, typename = void_t<>>
struct HasSizeType : true_type {

};

template <typename T>
struct HasSizeType<T, void_t<typename remove_reference<T>::type::size_type> > : false_type {

};