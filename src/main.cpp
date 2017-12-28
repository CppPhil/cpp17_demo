#include <iostream>

struct S
{
    int i;
    double d;
};

S f() noexcept
{
    return { 5, 1.0 };
}

int main()
{
   auto [i, d] = f();

   std::cout << i << '\n' << d << '\n';
}
