#include "spdlog/sinks/basic_file_sink.h"
// add support for logging of std::vector
#include "spdlog/fmt/ostr.h"  // must be included

#include <fstream>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << '{';
    if (vec.size() > 0)
        os << vec[0];
    for (int i = 0; i < vec.size(); i++)
        os << ", " << vec[i];
    os << '}';
    return os;
}

void spdlog_example()
{
    std::vector<int> vec = {1, 3, 5, 67};

    auto logger = spdlog::basic_logger_mt("ln", "logs/ln.dat");
    logger->info("vector print: {}", vec);
}

int main()
{
    spdlog_example();
}