#include "../../include/core_language/auto_non_type_template_parameter.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0127r2.html

namespace cpp17
{
namespace core_language
{
namespace
{
// like std::integral_constant<typename Ty, Ty Value>
// Value is a non-type template parameter
// the type of Value is deduced from the expression of the supplied template argument
template <auto Value>
struct integral_constant
{
    using value_type = decltype(Value);
    using type       = integral_constant;

    static constexpr value_type value = Value;

    constexpr operator value_type() const noexcept
    {
        return value;
    }

    constexpr value_type operator()() const noexcept
    {
        return value;
    }
};

using true_type  = integral_constant<true>;
using false_type = integral_constant<false>;
} // anonymous namespace

void autoNonTypeTemplateParameterDemo()
{
    std::cout << integral_constant<25>::value;
}
} // namespace core_language
} // namespace cpp17
