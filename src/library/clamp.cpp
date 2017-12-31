#include "../../include/library/clamp.hpp"
#include <iostream> // std::cout
#include <algorithm> // std::clamp

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0025r0.html
// cppreference: http://en.cppreference.com/w/cpp/algorithm/clamp

namespace cpp17
{
namespace library
{
void clampDemo()
{
    static constexpr int a{ 5 };
    static constexpr int b{ 7 };

    static constexpr int min1{ 6 };
    static constexpr int min2{ 4 };
    
    static constexpr int max1{ 8 };
    static constexpr int max2{ 6 };

    std::cout << std::clamp(a, min1, max1) << '\n'
              << std::clamp(b, min2, max2);
}
} // namespace library
} // namespace cpp17
