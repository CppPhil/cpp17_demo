#include "../../include/core_language/dynamic_memory_alignment.hpp"
#include <new> // operator new

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0035r4.html

namespace cpp17
{
namespace core_language
{
namespace
{
class alignas(16) vec4 
{
    float x, y, z, w;
};
} // anonymous namespace

void dynamicMemoryAlignmentDemo()
{
    // calls the new 
    // void* operator new[](std::size_t, std::align_val_t); 
    // since C++17
    auto pVectors = new vec4[1000];

    // calls the new
    // void operator delete[](void*, std::size_t, std::align_val_t);
    // since C++17
    delete[] pVectors;

    // non-array versions are supported in the same manner.
}
} // namespace core_language
} // namespace cpp17
