#include <iostream>

using namespace std;

class A {
public:
  // C style enum
  enum E1 { ONE, TWO };

  // C++11 strong enum, implicit conversion to int is impossible
  enum class E2 : int { ONE, TWO };
};

int main() {
  // output "0,1"
  cout << A::ONE << "," << A::TWO << endl;

  // output "0,1"
  cout << int(A::E2::ONE) << "," << int(A::E2::TWO) << endl;
}


