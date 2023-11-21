#include <utility>
#include <string>
#include <iostream>
#include <type_traits>

using namespace std;

class Person;

template <typename S>
using same_as_person = enable_if_t<!is_same_v<decay_t<S>, Person>>;

class Person {
private:
    std::string name;

public:

    // generic constructor for passed initial name:
    template<typename S, typename = same_as_person<S>>
    explicit Person(S &&n) : name(std::forward<S>(n)) {
        std::cout << "TMPL-CONSTR for '" << name << "'\n";
    }

    // copy and move constructor:
    Person (Person const& p) : name(p.name) {
        std::cout << "COPY-CONSTR Person '" << name << "'\n";
    }

    Person (Person&& p) : name(std::move(p.name)) {
        std::cout << "MOVE-CONSTR Person '" << name << "'\n";
    }
};

int main()
{
    std::string s = "sname";
    Person p1(s); // init with string object => calls copying string-CONSTR
    Person p2("tmp"); // init with string literal => calls moving string-CONSTR
    Person p3(p1); // copy Person => calls COPY-CONSTR
    Person p4(std::move(p1)); // move Person => calls MOVE-CONST
}
