#include "../include/core_language/static_assert_with_no_message.hpp" // cpp17::core_language::staticAssertWithNoMessageDemo
#include "../include/core_language/typename_in_template_template_parameter.hpp" // cpp17::core_language::typenameInTemplateTemplateParameterDemo
#include "../include/core_language/auto_direct_list_initialization.hpp" // cpp17::core_language::autoDirectListInitializationDemo
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
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::staticAssertWithNoMessageDemo);    
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::typenameInTemplateTemplateParameterDemo);
    CPP17_CALL_DEMO_FUNCTION(cpp17::core_language::autoDirectListInitializationDemo);
}

