#include "../../include/core_language/variadic_using.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0195r2.html

namespace cpp17
{
namespace core_language
{
namespace
{
// Compare this C++17 implementation to a C++14 implementation: https://github.com/CppPhil/philslib/blob/master/include/pl/overload.hpp
template <typename ...Lambdas>
class Overloaded
    : public Lambdas ...
{
public:
    using Lambdas::operator() ...;
};

template <typename ...Lambdas> 
Overloaded(Lambdas ...) -> Overloaded<Lambdas ...>;
} // anonymous namespace

void variadicUsingDemo()
{
    Overloaded overloaded{
        [](int i) { std::cout << "int: " << i; },
        [](double d) { std::cout << "double: " << d; }
    };

    overloaded(1);
    std::cout << '\n';

    overloaded(5.5);
}
} // namespace core_language
} // namespace cpp17
