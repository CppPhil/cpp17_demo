#include "../../include/core_language/fold_expression.hpp"
#include <ciso646> // and, or
#include <iostream> // std::cout
#include <utility> // std::forward

// papers: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html , 
//         http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0.pdf
// cppreference: http://en.cppreference.com/w/cpp/language/fold

namespace cpp17
{
namespace core_language
{
namespace 
{
template <typename ...Args>
bool unaryRightFold(Args &&...args)
{
    return (std::forward<Args>(args) and ...);
}

template <typename ...Args>
bool unaryLeftFold(Args &&...args)
{
    return (... or std::forward<Args>(args));
}

template <typename ...Args>
auto binaryRightFold(Args &&...args)
{
    return (std::forward<Args>(args) - ... - 0);
}

template <typename ...Args>
auto binaryLeftFold(Args &&...args)
{
    return (1 * ... * std::forward<Args>(args));
}
} // anonymous namespace

void foldExpressionDemo()
{
    // right fold parenthesizes from the right: (true and (true and false))
    const bool unaryRightFoldResult{ unaryRightFold(true, true, false) };
    
    // left fold parenthesizes from the left: ((true or true) or false)
    const bool unaryLeftFoldResult{ unaryLeftFold(true, true, false) };
    
    std::cout << "unaryRightFold:  " << unaryRightFoldResult << '\n'
              << "unaryLeftFold:   " << unaryLeftFoldResult  << '\n';
   
    // (10 - (20 - (33 - (1 - (2 - 0)))))
    const int binaryRightFoldResult{ binaryRightFold(10, 20, 33, 1, 2) };
    
    // ((((1 * 2) * 3) * 4) * 5)
    const int binaryLeftFoldResult{ binaryLeftFold(2, 3, 4, 5) };
    
    std::cout << "binaryRightFold: " << binaryRightFoldResult << '\n'
              << "binaryLeftFold:  " << binaryLeftFoldResult;      
}
} // namespace core_language
} // namespace cpp17

