#include "../../include/library/void_t.hpp"
#include <iostream> // std::cout
#include <utility> // std::declval
#include <string> // std::string
#include <type_traits> // std::void_t, std::false_type, std::true_type

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3911.pdf
// cppreference: http://en.cppreference.com/w/cpp/types/void_t

// also note the detection idiom, which is implemented using std::void_t.
// See: http://en.cppreference.com/w/cpp/experimental/is_detected

namespace cpp17
{
namespace library
{
namespace
{
template <typename, typename = std::void_t<>>
struct is_prefix_incrementable 
    : public std::false_type 
{
};

template <typename Ty>
struct is_prefix_incrementable<
    Ty,
    std::void_t<decltype(++std::declval<Ty &>())>> 
    : public std::true_type 
{
};
} // anonymous namespace

void void_tDemo()
{
    std::cout << "is_prefix_incrementable<int>::value:         " 
              << is_prefix_incrementable<int>::value
              << '\n'
              << "is_prefix_incrementable<std::string>::value: "
              << is_prefix_incrementable<std::string>::value;
}
} // namespace library
} // namespace cpp17
