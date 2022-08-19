
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <vector>

int main()
{
    fmt::print("It is {}\n", 42);
    std::vector<char> vec{1, 3, 5, 6, 9};
    int cvec[] = {65, 69, 111, 125};
    fmt::print("vec is {}\n", vec);
    fmt::print("cvec is {}\n", cvec);
}