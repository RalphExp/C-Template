#ifndef IS_POINTER_HPP_
#define IS_POINTER_HPP_

template<typename T>
struct IsPointerT : std::false_type { //primary template: bydefault not a pointer 
};

template<typename T>
struct IsPointerT<T*> : std::true_type { // partial specialization for pointers
    using BaseT = T; // type pointing to 
};

#endif