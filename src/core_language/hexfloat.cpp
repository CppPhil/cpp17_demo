#include "../../include/core_language/hexfloat.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1.html

namespace cpp17
{
namespace core_language
{
void hexfloatDemo()
{
    const double d{ 0x1ffp10 };

    std::cout << "d: " << d;
}
} // namespace core_language
} // namespace cpp17
