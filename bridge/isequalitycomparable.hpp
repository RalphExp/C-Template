#ifndef IS_EQUALITY_COMPARABLE_HPP_
#define IS_EQUALITY_COMPARABLE_HPP_

#include <type_traits>
#include <exception>

using namespace std;

template <typename T>
class IsEqualityComparable {
private:
    static void* conv(bool);

    // The IsEqualityComparable trait applies the typical form for expression-testing 
    // traits as introduced in Section 19.4.1 on page 416: two test() overloads, 
    // one of which contains the expressions to test wrapped in decltype, 
    // and the other that accepts arbitrary arguments via an ellipsis. 
    // The first test() function attempts to compare two objects of type T const 
    // using == and then ensures that the result can be both implicitly converted 
    // to bool (for the first parameter) and passed to the logical negation operator operator!) 
    // with a result convertible to bool. If both operations are well formed, 
    // the parameter types themselves will both be void*.
    template <typename U>
    static true_type test(
        decltype(conv(declval<U const&>() == declval<U const&>())),
        decltype(conv(!(declval<U const&>() == declval<U const&>())))
    );

    template <typename U>
    static false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(nullptr, nullptr))::value;
};

class NotEqualityComparable : public std::exception {
};

template<typename T, bool EqComparable = IsEqualityComparable<T>::value>
struct TryEquals {
    static bool equals(T const& x1, T const& x2) {
        return x1 == x2;
    } 
};

template<typename T>
struct TryEquals<T, false> {
    static bool equals(T const& x1, T const& x2) {
        throw NotEqualityComparable();
    } 
};

#endif