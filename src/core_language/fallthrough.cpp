#include "../../include/core_language/fallthrough.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r1.pdf

namespace cpp17
{
namespace core_language
{
void fallthroughDemo()
{
    enum class E
    {
        a, b, c
    };

    const E e{ E::b };

    switch (e) {
    case E::a:
        std::cout << "E::a, breaking.";
        break;
    case E::b:
        std::cout << "E::b, falling through...\n";
        [[fallthrough]];
    case E::c:
        std::cout << "E::c";
        break;
    }
}
} // namespace core_language
} // namespace cpp17
