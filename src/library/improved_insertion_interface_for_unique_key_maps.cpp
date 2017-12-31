#include "../../include/library/improved_insertion_interface_for_unique_key_maps.hpp"
#include <iostream> // std::cout
#include <string> // std::string, std::literals::string_literals::operator""s
#include <unordered_map> // std::unordered_map

// paper: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4279.html
// cppreference: http://en.cppreference.com/w/cpp/container/map/try_emplace ,
//               http://en.cppreference.com/w/cpp/container/unordered_map/try_emplace ,
//               http://en.cppreference.com/w/cpp/container/map/insert_or_assign ,
//               http://en.cppreference.com/w/cpp/container/unordered_map/insert_or_assign

namespace cpp17
{
namespace library
{
void improvedInsertionInterfaceForUniqueKeyMapsDemo()
{
    using namespace std::literals::string_literals;

    std::unordered_map<int, std::string> map{ 
        { 1, "test"s },
        { 2, "text"s } 
    };

    const auto [it1, wasInserted1] = map.try_emplace(3, "Hello World"); 
    const auto &[key1, value1]     = *it1;

    std::cout << "wasInserted1: " << wasInserted1 << '\n'
              << key1 << " => " << value1 << '\n';

    std::cout << '\n';

    const auto [it2, wasInserted2] = map.try_emplace(1, "Won't be inserted.");
    const auto &[key2, value2]     = *it2;

    std::cout << "wasInserted2: " << wasInserted2 << '\n'
              << key2 << " => " << value2 << '\n';

    std::cout << '\n';

    auto asText = [](bool inserted) { 
        if (inserted) {
            return "inserted"s;
        }

        return "assigned"s;
    };

    const auto [it3, wasInserted3] = map.insert_or_assign(4, "New Text"s);
    const auto &[key3, value3]     = *it3;

    std::cout << asText(wasInserted3) << ":\n"
              << key3 << " => " << value3 << '\n';

    std::cout << '\n';

    const auto [it4, wasInserted4] = map.insert_or_assign(1, "Sample Text"s);
    const auto &[key4, value4]     = *it4;

    std::cout << asText(wasInserted4) << ":\n"
              << key4 << " => " << value4;
}
} // namespace library
} // namespace cpp17
