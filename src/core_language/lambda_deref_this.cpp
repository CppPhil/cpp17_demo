#include "../../include/core_language/lambda_deref_this.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html

namespace cpp17
{
namespace core_language
{
namespace
{
class Type
{
public:
    explicit Type(int i)
        : m_i{ i } 
    {
    }

    int f() const noexcept
    {
        // captures a copy of the *this object in C++17
        // in C++14 captures a reference to *this
        return [*this] {
            return m_i + 1;
        }();
    }

private:
    int m_i;    
};
} // anonymous namespace

void lambdaDerefThisDemo()
{
    const Type type{ 5 };

    std::cout << "type.f(): " << type.f();
}
} // namespace core_language
} // namespace cpp17
