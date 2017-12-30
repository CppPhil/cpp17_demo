#include "../../include/core_language/nested_namespace.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230.html

namespace cpp17::core_language
{
namespace a::b::c::d
{
int f(int i)
{
    return i * 2;
}
}

void nestedNamespaceDemo()
{
    std::cout << "a::b::c::d::f(2): " << a::b::c::d::f(2) << '\n';
}
}

