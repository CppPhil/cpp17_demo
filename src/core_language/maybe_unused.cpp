#include "../../include/core_language/maybe_unused.hpp"
#include <ciso646> // not
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0212r1.pdf

namespace cpp17
{
namespace core_language
{
namespace
{
// no warning if f is unused
[[maybe_unused]] void f()
{

}

bool f2()
{
    // if A is not defined b will be unused -> don't issue a warning.
    [[maybe_unused]] bool b{ true };
#ifdef A 
    return not b;
#endif // A

    return true;
}
} // anonymous namespace

void maybeUnusedDemo()
{
    std::cout << "f2(): " << f2();
}
} // namespace core_language
} // namespace cpp17
