#include "../../include/library/invoke.hpp"
#include <iostream> // std::cout
#include <functional> // std::invoke, std::plus

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4169.html
// cppreference: http://en.cppreference.com/w/cpp/utility/functional/invoke

namespace cpp17
{
namespace library
{
namespace
{
int f(int i)
{
    return i * 2;
}

class MyType
{
public:
    explicit MyType(int i)
        : m_i{ i }
    {
    }

    double memFn(double d, float f) const noexcept
    {
        return d * f;
    }

    int m_i;
};
} // anonymous namespace

void invokeDemo()
{
    const MyType myType{ 7 };
    const MyType * const p{ &myType }; 

    // std::invoke offers a single unified interface to 'call' any Invocable.
    // It accounts for the different invocation syntaxes and is particularly
    // useful in templates where any type of Invocable may be passed.
    
    // calling a function pointer.
    std::cout << std::invoke(&f, 3) << '\n';
    std::cout << (&f)(3)            << '\n';

    std::cout << '\n';

    // calling a functor (function object).
    std::cout << std::invoke(std::plus<>{ }, 1, 2) << '\n';
    std::cout << std::plus<>{ }(1, 2)              << '\n';

    std::cout << '\n';

    // calling a closure created from a lambda expression (technically also a function object).
    std::cout << std::invoke([](int i) { return i - 1; }, 3) << '\n';
    std::cout << [](int i) { return i - 1; }(3)              << '\n';

    std::cout << '\n';

    // calling a member function pointer with a reference to the receiver object.
    std::cout << std::invoke(&MyType::memFn, myType, 2.0, 3.0F) << '\n';
    std::cout << (myType.*&MyType::memFn)(2.0, 3.0F)            << '\n';

    std::cout << '\n';

    // calling a member function pointer with a pointer to the receiver object.
    std::cout << std::invoke(&MyType::memFn, p, 2.0, 3.0F) << '\n';
    std::cout << (p->*&MyType::memFn)(2.0, 3.0F)           << '\n';

    std::cout << '\n';

    // 'calling' a member object pointer with a reference to the receiver object.
    std::cout << std::invoke(&MyType::m_i, myType) << '\n';
    std::cout << myType.*&MyType::m_i              << '\n';

    std::cout << '\n';

    // 'calling' a member object pointer with a pointer to the receiver object.
    std::cout << std::invoke(&MyType::m_i, p) << '\n';
    std::cout << p->*&MyType::m_i;
}
} // namespace library
} // namespace cpp17
