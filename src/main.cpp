#include "../include/core_language/static_assert_with_no_message.hpp" // cpp17::core_language::staticAssertWithNoMessageDemo
#include "../include/core_language/typename_in_template_template_parameter.hpp" // cpp17::core_language::typenameInTemplateTemplateParameterDemo
#include "../include/core_language/auto_direct_list_initialization.hpp" // cpp17::core_language::autoDirectListInitializationDemo
#include "../include/core_language/fold_expression.hpp" // cpp17::core_language::foldExpressionDemo
#include "../include/core_language/utf8_literals.hpp" // cpp17::core_language::utf8LiteralsDemo
#include "../include/core_language/nested_namespace.hpp" // cpp17::core_language::nestedNamespaceDemo
#include "../include/core_language/attributes_namespace_enumerator.hpp" // cpp17::core_language::attributesNamespaceEnumeratorDemo
#include "../include/core_language/constant_non_type_template_parameter_evaluation.hpp" // cpp17::core_language::constantNonTypeTemplateParameterEvaluationDemo
#include "../include/core_language/pointer_to_noexcept_function.hpp" // cpp17::core_language::pointerToNoexceptFunctionDemo
#include "../include/core_language/has_include.hpp" // cpp17::core_language::hasIncludeDemo
#include "../include/core_language/fallthrough.hpp" // cpp17::core_language::fallthroughDemo
#include "../include/core_language/nodiscard.hpp" // cpp17::core_language::nodiscardDemo
#include "../include/core_language/maybe_unused.hpp" // cpp17::core_language::maybeUnusedDemo
#include "../include/core_language/aggregate_initialization_with_bases.hpp" // cpp17::core_language::aggregateInitializationWithBasesDemo
#include "../include/core_language/constexpr_lambda.hpp" // cpp17::core_language::constexprLambdaDemo
#include "../include/core_language/generalized_ranged_for.hpp" // cpp17::core_language::generalizedRangedForDemo
#include "../include/core_language/lambda_deref_this.hpp" // cpp17::core_language::lambdaDerefThisDemo
#include "../include/core_language/enum_direct_list_init.hpp" // cpp17::core_language::enumDirectListInitDemo
#include <ios> // std::boolalpha
#include <iostream> // std::cout

#define CPP17_CALL_DEMO_FUNCTION(demoFunction) \
    ::cpp17::detail::callDemoFunctionImpl(demoFunction, #demoFunction)

namespace cpp17
{
namespace detail
{
namespace
{
template <typename NullaryCallable>
void callDemoFunctionImpl(
    NullaryCallable nullaryCallable, 
    const char *functionName) noexcept
{
    std::cout << "BEGIN demo: "   << functionName << '\n';
    nullaryCallable();
    std::cout << "\nEND demo:   " << functionName << "\n\n"; 
}
} // anonymous namespace
} // namespace detail
} // namespace cpp17

int main()
{
    std::cout << std::boolalpha;

    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::staticAssertWithNoMessageDemo);    
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::typenameInTemplateTemplateParameterDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::autoDirectListInitializationDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::foldExpressionDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::utf8LiteralsDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::nestedNamespaceDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::attributesNamespaceEnumeratorDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::constantNonTypeTemplateParameterEvaluationDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::pointerToNoexceptFunctionDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::hasIncludeDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::fallthroughDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::nodiscardDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::maybeUnusedDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::aggregateInitializationWithBasesDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::constexprLambdaDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::generalizedRangedForDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::lambdaDerefThisDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::enumDirectListInitDemo);
}
