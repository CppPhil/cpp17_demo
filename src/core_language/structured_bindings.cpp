#include "../../include/core_language/structured_bindings.hpp"
#include <cstddef> // std::size_t
#include <iostream> // std::cout
#include <utility> // std::pair
#include <string> // std::string, std::to_string
#include <array> // std::array
#include <tuple> // std::tuple

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0217r3.html

namespace cpp17
{
namespace core_language
{
namespace
{
class MyClass
{
public:
    explicit MyClass(int i)
        : m_i{ i },
          m_s{ std::to_string(m_i) + " text" }
    {
    }

    int m_i;
    std::string m_s;
};

template <std::size_t Idx>
auto &get(MyClass &myClass) noexcept
{
    if constexpr (Idx == 0U) {
        return myClass.m_i;
    } else if constexpr (Idx == 1U) {
        return myClass.m_s;
    } 
}

template <std::size_t Idx>
const auto &get(const MyClass &myClass) noexcept
{
    return get<Idx>(const_cast<MyClass &>(myClass));
}

struct Structure
{
    int i;
    std::string s;
};

auto fArray() -> int(&)[2]
{
    static int array[2]{ 0, 1 };
    return array;
}

std::array<double, 3U> fStdArray()
{
    return { { 1.0, 1.1, 1.2 } };
}

std::pair<int, float> fPair()
{
    return { 1, 5.5F };
}

std::tuple<int, float, long> fTuple()
{
    return { 5, 1.1F, 3L };
}

Structure fStructure()
{
    return { 0, "Text" };
}

MyClass fCustomDecomposableType()
{
    return MyClass{ 5 };
}
} // anonymous namespace

void structuredBindingsDemo()
{
    const auto &[a1, b1] = fArray();

    auto [a2, b2, c2]    = fStdArray();

    const auto [a3, b3]  = fPair();

    auto [a4, b4, c4]    = fTuple();

    auto [a5, b5]        = fStructure();

    auto [a6, b6]        = fCustomDecomposableType(); 

    std::cout << "a1: \"" << a1 << "\" b1: \"" << b1                      << "\"\n"
              << "a2: \"" << a2 << "\" b2: \"" << b2 << "\" c2: \"" << c2 << "\"\n"
              << "a3: \"" << a3 << "\" b3: \"" << b3                      << "\"\n"
              << "a4: \"" << a4 << "\" b4: \"" << b4 << "\" c4: \"" << c4 << "\"\n"
              << "a5: \"" << a5 << "\" b5: \"" << b5                      << "\"\n"
              << "a6: \"" << a6 << "\" b6: \"" << b6                      << '"';
}
} // namespace core_language
} // namespace cpp17
