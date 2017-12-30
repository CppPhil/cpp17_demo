#include "../../include/core_language/aggregate_initialization_with_bases.hpp"
#include <string> // std::string
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html

namespace cpp17
{
namespace core_language
{
namespace
{
struct Base
{
    int i;
    double d;
};

struct Derived 
    : public Base
{
    std::string s;
};
} // anonymous namespace
void aggregateInitializationWithBasesDemo()
{
    const Derived derived{ { 1, 5.5 }, "Hello World" };

    std::cout << "derived.i: " << derived.i << '\n'
              << "derived.d: " << derived.d << '\n'
              << "derived.s: " << derived.s;
}
} // namespace core_language
} // namespace cpp17
