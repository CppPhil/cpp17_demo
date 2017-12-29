#include "../../include/core_language/typename_in_template_template_parameter.hpp"
#include <iostream> // std::cout
#include <vector> // std::vector

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4051.html

namespace cpp17
{
namespace core_language
{
namespace 
{
// In C++14 the template template parameter can only be declared using the class keyword.
// So the line would look like: template <typename ...Args, template <typename ...> class Cont>
template <typename ...Args, template <typename ...> typename Cont>
decltype(auto) f(const Cont<Args ...> &cont) noexcept
{
    return cont.size();
}
} // anonymous namespace

void typenameInTemplateTemplateParameterDemo()
{   
    const std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
    
    std::cout << "size of v: " << f(v);    
}
} // namespace core_language
} // namespace cpp17

