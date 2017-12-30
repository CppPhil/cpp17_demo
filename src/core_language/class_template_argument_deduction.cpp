#include "../../include/core_language/class_template_argument_deduction.hpp"
#include <ostream> // std::ostream
#include <iostream> // std::cout
#include <string> // std::string
#include <iterator> // std::iterator_traits, std::begin, std::end
#include <utility> // std::move
#include <deque> // std::deque
#include <vector> // std::vector

// papers: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0091r3.html ,
//         http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0512r0.pdf
// cppreference: http://en.cppreference.com/w/cpp/language/class_template_argument_deduction

namespace cpp17
{
namespace core_language
{
namespace
{
template <typename Ty>
class T1
{
public:
    explicit T1(Ty ty)
        : m_ty{ std::move(ty) } 
    {
    }

    Ty &getTy() noexcept
    {
        return m_ty;
    }

    const Ty &getTy() const noexcept
    {
        return const_cast<T1 *>(this)->getTy();
    }

private:
    Ty m_ty;
};

template <typename Ty>
class T2
{
public:
    template <typename It>
    T2(It begin, It end) 
        : m_cont(begin, end)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const T2 &t2) 
    {
        for (const auto &e : t2.m_cont) {
            os << e << ' ';
        }

        return os;
    }

private:
    std::vector<Ty> m_cont;
};

// deduction guide (since C++17)
template <typename It>
T2(It begin, It end) -> T2<typename std::iterator_traits<It>::value_type>;
} // anonymous namespace

void classTemplateArgumentDeductionDemo()
{
    // deduced to T1<std::string>
    const T1 a{ std::string{ "text" } };

    std::cout << a.getTy() << '\n';

    // deduced to std::deque<int>
    const std::deque deque{ 1, 2, 3, 4, 5, 6 };

    // deduced through user defined deduction guide to T2<int>
    const T2 b(std::begin(deque), std::end(deque));

    std::cout << b;
}
} // namespace core_language
} // namespace cpp17
