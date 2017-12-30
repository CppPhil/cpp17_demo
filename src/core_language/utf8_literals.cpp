#include "../../include/core_language/utf8_literals.hpp"
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html

namespace cpp17
{
namespace core_language
{
void utf8LiteralsDemo()
{
    // new in C++17
    static constexpr char c{ u8'a' };
    
    // since C++11
    static constexpr char arr[]{ u8"Как посеешь, так и пожнешь" };
    
    std::cout << "c:   " << c << '\n'
              << "arr: " << arr;
}
} // namespace core_language
} // namespace cpp17
 
