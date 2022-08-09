#include <vector>
#include "spdlog/fmt/fmt.h"
#include "spdlog/fmt/ranges.h"

int main()
{
    fmt::print("It is {}\n", 42);
    std::vector<char> vec{1, 3, 5, 6, 9};
    char cvec[] = {65, 69, 111, 125};
    fmt::print("vec is {{{:d}}}\n", fmt::join(vec, ", "));
    fmt::print("cvec is {}\n", cvec);
}