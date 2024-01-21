#ifndef IsNothrowMoveConstructibleT_HPP_
#define IsNothrowMoveConstructibleT_HPP_

#include <type_traits>

// As discussed in Section 19.4.4 on page 424, we have to check 
// whether the expression computing the result is valid before
// it is evaluated. Here, we have to find out whether move 
// construction is valid before checking whether it is noexcept. 
// Thus, we revise the first version of the trait by adding a template 
// parameter that defaults to void and a partial that uses std::void_t 
// for that parameter with an argument that is valid only if move 
// construction is valid:

// NOTE: The C++ standard library provides a corresponding 
// type trait std::is_move_constructible<>.

// primary template:
template<typename T, typename = std::void_t<>>
struct IsNothrowMoveConstructibleT : std::false_type
{
};

// partial specialization (may be SFINAE’d away):
template<typename T>
struct IsNothrowMoveConstructibleT
          <T, std::void_t<decltype(T(std::declval<T>()))>>
  : std::bool_constant<noexcept(T(std::declval<T>()))>
{ };

#endif