#include "../../include/core_language/constant_non_type_template_parameter_evaluation.hpp"

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268.html

namespace cpp17
{
namespace core_language
{
namespace
{
template <int *Ptr>
class Type
{
};

struct S
{
    static int s;
} s;
} // anonymous namespace

void constantNonTypeTemplateParameterEvaluationDemo()
{
    Type<&s.s> a{ };  // OK since C++17, error in C++14
    Type<&S::s> b{ }; // OK in both C++17 and C++14
}
} // namespace core_language
} // namespace cpp17
