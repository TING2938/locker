
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <vector>

#include <fmt/ostream.h>

template <typename T>
typename std::enable_if<std::is_enum<T>::value, std::ostream&>::type operator<<(std::ostream& os, const T& value)
{
    return os << static_cast<typename std::underlying_type<T>::type>(value);
}


enum class E
{
    AA,
    BB,
    CC,
};


int main()
{
    std::vector<int> vecc = {10, 20, 30};
    fmt::print("{::d}\n", vecc);

    fmt::print("E: {}\n", E::BB);

    std::vector<E> vec = {E::AA, E::CC};
    // fmt::print("aaa{}bbb\n", vec);
}