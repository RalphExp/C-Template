#ifndef ISCONVERTIBLE_HPP_
#define ISCONVERTIBLE_HPP_

#include <type_traits> // for true_type and false_type
#include <utility> // for declval
#include <iostream>

using namespace std;

template<typename FROM, typename TO, bool = 
    is_void<TO>::value || 
    is_array<TO>::value || 
    is_function<TO>::value>

struct IsConvertibleHelper {
    using Type = std::integral_constant<bool,is_void<TO>::value && is_void<FROM>::value>;
};

template<typename FROM, typename TO>
struct IsConvertibleHelper<FROM, TO, false> {
private:
    // test() trying to call the helper aux(TO) for a FROM passed as F:
    static void aux(TO);

    template<typename F, typename = decltype(aux(std::declval<F>()))>
    static std::true_type test(void*);
    
    // test() fallback:
    template<typename>
    static std::false_type test(...);

public:
    using Type = decltype(test<FROM>(nullptr));
};

template<typename FROM, typename TO>
struct IsConvertibleT : IsConvertibleHelper<FROM, TO>::Type {
};

template<typename FROM, typename TO>
using IsConvertible = typename IsConvertibleT<FROM, TO>::type;
 
template<typename FROM, typename TO>
constexpr bool isConvertible = IsConvertibleT<FROM, TO>::value;

#endif