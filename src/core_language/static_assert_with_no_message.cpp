#include "../../include/core_language/static_assert_with_no_message.hpp"
#include <ciso646> // not
#include <type_traits> // std::is_const

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf

namespace cpp17
{
namespace core_language
{
void staticAssertWithNoMessageDemo()
{
    static_assert(std::is_const<const volatile int>::value);
    static_assert(not std::is_const<int>::value);
}
} // namespace core_language
} // namespace cpp17

