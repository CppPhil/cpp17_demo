#include "../../include/core_language/constexpr_lambda.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1.pdf

namespace cpp17
{
namespace core_language
{
void constexprLambdaDemo()
{
    constexpr auto add = [](int a, int b) constexpr {
        return a + b;
    };

    static_assert(add(3, 4) == 7);

    std::cout << "add(3, 4): " << add(3, 4);
}
} // namespace core_language
} // namespace cpp17
