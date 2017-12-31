#include "../../include/library/as_const.hpp"
#include <iostream> // std::cout
#include <string> // std::string
#include <utility> // std::as_const

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0007r1.html
// cppreference: http://en.cppreference.com/w/cpp/utility/as_const

namespace cpp17
{
namespace library
{
namespace
{
class MyType
{
public:
    std::string f()
    {
        return "non-const";
    }

    std::string f() const
    {
        return "const";
    }

};
} // anonymous namespace

void asConstDemo()
{
    MyType myType{ };

    std::cout << "myType.f():                " << myType.f() << '\n'
              << "std::as_const(myType).f(): " << std::as_const(myType).f();
}
} // namespace library
} // namespace cpp17
