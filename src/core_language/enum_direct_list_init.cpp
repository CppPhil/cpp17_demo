#include "../../include/core_language/enum_direct_list_init.hpp"
#include <cstdint> // std::uint32_t, UINT32_C
#include <ostream> // std::ostream
#include <iostream> // std::cout
#include <type_traits> // std::underlying_type_t

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0138r2.pdf

namespace cpp17
{
namespace core_language
{
namespace
{
enum class Enum 
    : std::uint32_t
{ 
    a,
    b
};

std::ostream &operator<<(std::ostream &os, Enum enm)
{
    return os << static_cast<std::underlying_type_t<Enum>>(enm);
}
} // anonymous namespace

void enumDirectListInitDemo()
{
    const Enum e1{ Enum::a };

    // legal in C++17, compilation error in C++14
    const Enum e2{ UINT32_C(25) };

    std::cout << "e1: " << e1 << '\n'
              << "e2: " << e2;
}
} // namespace core_language
} // namespace cpp17
