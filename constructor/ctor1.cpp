#include <iostream>
#include <string>

using namespace std;

class A {
public:
  A(const string& s) : s_(s) { cout << "const constructor" << endl; }
  A(string& s) : s_(s) { cout << "nonconst constructor" << endl; }
  A(string&& s) : s_(move(s)) { cout << "move constructor" << endl; }

  string s_;
};

int main() {
  A a1("test");
  A a2(string("test"));

  string s("test");
  A a3(s);
  A a4(move(s));
}
