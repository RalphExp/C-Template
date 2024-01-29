#include "typelist/accumulate.hpp"
#include "typelist/typelistpushfront.hpp"
#include <typeinfo>
#include <iostream>
#include <type_traits>

using namespace std;

int main() {
    using SignedIntegralTypes =
              Typelist<signed char, short, int, long, long long>;

    // produces TypeList<long long, long, int, short, signed char>
    using Result = Accumulate<SignedIntegralTypes, PushFrontT, Typelist<>>;

    cout << boolalpha;

    cout << typeid(Result).name() << endl;

    cout << is_same_v<Result, Typelist<long long, long, int, short, signed char>> << endl;
}