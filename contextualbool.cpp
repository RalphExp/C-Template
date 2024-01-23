#include "typeoverload/iscontextualbool.hpp"

struct X1 {};
bool operator< (X1 const&, X1 const&) { return true; }

struct X2 {};
bool operator<(X2, X2) { return true; }

struct X3 {};
bool operator<(X3&, X3&) { return true; }

struct X4 {};
struct BoolConvertible {
  operator bool() const { return true; }
};

struct X5 {};
BoolConvertible operator< (X5 const&, X5 const&)
{
  return BoolConvertible();
}

struct NotBoolConvertible {};
struct X6 {};
NotBoolConvertible operator< (X6 const&, X6 const&)
{
    return NotBoolConvertible();
}

// implicit conversion to bool
// no conversion to bool
struct BoolLike {
    explicit operator bool() const { return true; } // explicit conversion to bool
};

struct X7 {};
BoolLike operator< (X7 const&, X7 const&) { return BoolLike(); }

int main() {
    using namespace std;
    cout << boolalpha;
    cout << "X4 is bool: " << IsContextualBool<bool> << endl;
    cout << "X4 is bool: " << IsContextualBool<int> << endl;
    cout << "X4 is bool: " << IsContextualBool<X4> << endl;
    cout << "X5 is bool: " << IsContextualBool<X5> << endl;
    cout << "X6 is bool: " << IsContextualBool<X6> << endl;
    cout << "X6 is bool: " << IsContextualBool<X7> << endl;
}