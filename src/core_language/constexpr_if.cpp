#include "../../include/core_language/constexpr_if.hpp"
#include <ciso646> // not
#include <iostream> // std::cout
#include <string> // std::string
#include <utility> // std::forward
#include <type_traits> // std::remove_cv_t, std::remove_reference_t, std::is_same, std::enable_if_t

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0292r2.html

namespace cpp17
{
namespace core_language
{
namespace
{
namespace detail
{
template <typename Type>
struct remove_cvref
    : public std::remove_cv<std::remove_reference_t<Type>>
{
};

template <typename Type>
using remove_cvref_t = typename remove_cvref<Type>::type;
} // namespace detail

// In C++17 using constexpr if:
template <typename Ty>
auto f(Ty &&ty)
{
    // Note the different return types in the two compile time branches.
    if constexpr (std::is_same_v<detail::remove_cvref_t<Ty>, std::string>) {
        std::cout << "std::string: " << ty << '\n';
        return ty;
    } else {
        std::cout << "not std::string: " << ty << '\n';
        return 5;
    }
}

// In C++14 using tag dispatching:
namespace detail
{
// implementation template for the std::string case:
template <typename Ty>
auto fImpl(std::true_type, Ty &&ty)
{
    std::cout << "std::string: " << ty << '\n';
    return ty;
}

// implementation template for the non-std::strin case:
template <typename Ty>
auto fImpl(std::false_type, Ty &&ty)
{
    std::cout << "not std::string: " << ty << '\n';
    return 5;
}
} // namespace detail

template <typename Ty>
auto fTagDispatch(Ty &&ty) 
{
    return detail::fImpl(
        typename std::is_same<detail::remove_cvref_t<Ty>, std::string>::type{ },
        std::forward<Ty>(ty));
}

// In C++14 using enable_if based SFINAE:
// the std::string case:
template <typename Ty>
auto fSFINAE(Ty &&ty)
    -> std::enable_if_t<
        std::is_same<detail::remove_cvref_t<Ty>, std::string>::value, 
        std::string>
{
    std::cout << "std::string: " << ty << '\n';
    return ty;
}

// the non-std::string case:
template <typename Ty>
auto fSFINAE(Ty &&ty) 
    -> std::enable_if_t<
        not std::is_same<detail::remove_cvref_t<Ty>, std::string>::value,
        int>
{
    std::cout << "not std::string: " << ty << '\n';
    return 5;
}
} // anonymous namespace

void constexprIfDemo()
{
    static const std::string string{ "Text" };
    static constexpr double d{ 5.5 };

    const auto a1{ f(string) };
    std::cout << "f(string) retval:            " << a1 << '\n';

    const auto a2{ f(d) };
    std::cout << "f(d) retval:                 " << a2 << '\n';

    std::cout << '\n';

    const auto a3{ fTagDispatch(string) };
    std::cout << "fTagDispatch(string) retval: " << a3 << '\n';

    const auto a4{ fTagDispatch(d) };
    std::cout << "fTagDispatch(d) retval:      " << a4 << '\n';

    std::cout << '\n';

    const auto a5{ fSFINAE(string) };
    std::cout << "fSFINAE(string) retval:      " << a5 << '\n';

    const auto a6{ fSFINAE(d) };
    std::cout << "fSFINAE(d) retval:           " << a6;
}
} // namespace core_language
} // namespace cpp17
