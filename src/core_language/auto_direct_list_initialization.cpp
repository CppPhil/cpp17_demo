#include "../../include/core_language/auto_direct_list_initialization.hpp"
#include <iostream> // std::cout
#include <type_traits> // std::is_same

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3922.html

namespace cpp17
{
namespace core_language
{
void autoDirectListInitializationDemo()
{
    // deduces to int in C++17
    // would deduce to std::initializer_list<int> in C++14
    auto i{ 5 };
    
    static_assert(
        std::is_same<decltype(i), int>::value, 
        "You are not compiling as C++17.");

    std::cout << "i: " << i;
}
} // namespace core_language
} // namespace cpp17

