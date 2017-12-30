#include "../../include/core_language/generalized_ranged_for.hpp"
#include <ciso646> // not
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html

namespace cpp17
{
namespace core_language
{
namespace
{
class RangeOfThree
{
public:
    class iterator
    {
    public:
        explicit iterator(int curVal)
            : m_curVal{ curVal }
        {
        }

        iterator &operator++() noexcept
        {
            ++m_curVal;
            return *this;
        }

        int operator*() const noexcept
        {
            return m_curVal;
        }
        
    private:
        int m_curVal;
    };

    class EndType
    {
    public:
        explicit EndType(int endVal)
            : m_endVal{ endVal }
        {
        }

        friend bool operator==(iterator it, EndType end)
        {
            return *it == end.m_endVal;
        }

        friend bool operator!=(iterator it, EndType end)
        {
            return not (it == end);
        }
        
    private:
        int m_endVal;
    };

    explicit RangeOfThree(int startVal)
        : m_startVal{ startVal },
          m_endVal{ m_startVal + 3 }
    {
    }

    iterator begin() const noexcept
    {
        return iterator{ m_startVal };
    }

    EndType end() const noexcept
    {
        return EndType{ m_endVal };
    }

private:
    int m_startVal;
    int m_endVal;
};
} // anonymous namespace

void generalizedRangedForDemo()
{
    // different types returned by .begin() and .end(), legal since C++17.
    for (int i : RangeOfThree{ 5 }) {
        std::cout << i << ' ';
    }
}
} // namespace core_language
} // namespace cpp17
