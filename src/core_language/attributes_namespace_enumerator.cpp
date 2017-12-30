#include "../../include/core_language/attributes_namespace_enumerator.hpp"
#include <ostream> // std::ostream
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html

namespace cpp17
{
namespace core_language
{
namespace 
{
enum class Enum
{
    enumerator1 [[deprecated("old")]],
    enumerator2
};

std::ostream &operator<<(std::ostream &os, Enum enm)
{
    switch (enm) {
    case Enum::enumerator1:
        os << "enumerator1 (deprecated)";
        break;
    case Enum::enumerator2:
        os << "enumerator2";
        break;
    }

    return os;
}

namespace [[deprecated("bad")]] nested_namespace
{
void f()
{
    std::cout << "This is in a deprecated namespace";
}
} // namespace nested_namespace
} // anonymous namspace

void attributesNamespaceEnumeratorDemo()
{
    static constexpr Enum a{ Enum::enumerator1 };
    static constexpr Enum b{ Enum::enumerator2 };
    
    std::cout << "a: " << a << '\n'
              << "b: " << b << '\n';
              
    nested_namespace::f();
}
} // namespace core_language
} // namespace cpp17

