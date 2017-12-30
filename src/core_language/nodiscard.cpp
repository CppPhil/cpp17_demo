#include "../../include/core_language/nodiscard.hpp"
#include <ostream> // std::ostream
#include <iostream> // std::cout

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0189r1.pdf

namespace cpp17
{
namespace core_language
{
namespace
{
class [[nodiscard]] ErrorCode
{
public:
    explicit ErrorCode(int i)
        : m_i{ i }
    {
    }

    friend std::ostream &operator<<(std::ostream &os, ErrorCode errorCode)
    {
        return os << "error code: " << errorCode.m_i;
    }

private:
    int m_i;
};

ErrorCode criticalFunction() noexcept
{
    return ErrorCode{ 20 };
}

[[nodiscard]] bool isStatusOk() noexcept
{
    return false;
}
} // anonymous namespace

void nodiscardDemo()
{
    // should warn
    criticalFunction();

    // ok
    const ErrorCode errorCode{ criticalFunction() };
    std::cout << "errorCode: " << errorCode << '\n';

    // should warn
    isStatusOk();

    const bool status{ isStatusOk() };
    std::cout << "status: " << status;
}
} // namespace core_language
} // namespace cpp17
