#include <type_traits> // for true_type, false_type, and void_t


// 1) Member must unambiguously identify a member of T 
//    (e.g., it cannot be an overloaded member function name, 
// or the name of multiple inherited members of the same name

// 2) The member must be accessible
// 3) The member must be a nontype, nonenumerator member 
//    (otherwise the prefix & would be invalid)

// 4) If T::Member is a static data member, its type must not provide an operator& that makes
//    &T::Member invalid

#define DEFINE_HAS_MEMBER(Member) \
    template<typename, typename = std::void_t<>> \
    struct HasMemberT_##Member : std::false_type { }; \
\
    template<typename T> \
    struct HasMemberT_##Member<T, std::void_t<decltype(&T::Member)>> \
        : std::true_type { } // ; intentionally skipped