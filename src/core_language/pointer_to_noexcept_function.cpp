#include "../../include/core_language/pointer_to_noexcept_function.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0012r1.html

namespace cpp17
{
namespace core_language
{
namespace
{
void f() noexcept
{
    std::cout << "f() noexcept called";
}

void g()
{
    std::cout << "g() called";
}
} // anonymous namespace

void pointerToNoexceptFunctionDemo()
{
    // the exception specification is now part of the type system

    void (*fp1)() noexcept{ &f };
    
    // also ok:
    void (*fp2)() noexcept(false){ &g };

    fp1();
    std::cout << '\n';
    fp2();
}
} // namespace core_language
} // namespace cpp17
