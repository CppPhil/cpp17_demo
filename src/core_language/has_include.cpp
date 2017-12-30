#include "../../include/core_language/has_include.hpp"
#include <iostream> // std::cout
#if __has_include(<optional>)
#   include <optional>
#   define HAS_OPTIONAL          (1)
#   define EXPERIMENTAL_OPTIONAL (0)
#elif __has_include(<experimental/optional>)
#   include <experimental/optional>
#   define HAS_OPTIONAL          (1)
#   define EXPERIMENTAL_OPTIONAL (1)
#else
#   define HAS_OPTIONAL          (0)
#   define EXPERIMENTAL_OPTIONAL (0)
#endif

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0061r1.html

namespace cpp17
{
namespace core_language
{
void hasIncludeDemo()
{
    std::cout << "HAS_OPTIONAL:          " << static_cast<bool>(HAS_OPTIONAL) << '\n'
              << "EXPERIMENTAL_OPTIONAL: " << static_cast<bool>(EXPERIMENTAL_OPTIONAL);
}
} // namespace core_language
} // namespace cpp17
