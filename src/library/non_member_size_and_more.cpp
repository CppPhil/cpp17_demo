#include "../../include/library/non_member_size_and_more.hpp"
#include <iostream> // std::iostream
#include <initializer_list> // std::initializer_list
#include <iterator> // std::size, std::empty, std::data
#include <vector> // std::vector

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4280.pdf
// cppreference: http://en.cppreference.com/w/cpp/iterator/size , 
//               http://en.cppreference.com/w/cpp/iterator/empty ,
//               http://en.cppreference.com/w/cpp/iterator/data

namespace cpp17
{
namespace library
{
void nonMemberSizeAndMoreDemo()
{
    const std::vector v{ 1, 2, 3, 4, 5, 6 };
    const double a[]{ 1.2, 1.3, 1.4 };
    const std::initializer_list<const char *> initList{ "a", "b", "c", "d" };

    std::cout << "std::size(v):         " << std::size(v)         << '\n'
              << "std::size(a):         " << std::size(a)         << '\n'
              << "std::size(initList):  " << std::size(initList)  << '\n'
              << "std::empty(v):        " << std::empty(v)        << '\n'
              << "std::empty(a):        " << std::empty(a)        << '\n'
              << "std::empty(initList): " << std::empty(initList) << '\n'
              << "*std::data(v):        " << *std::data(v)        << '\n'
              << "*std::data(a):        " << *std::data(a)        << '\n'
              << "*std::data(initList): " << *std::data(initList);
}
} // namespace library
} // namespace cpp17
