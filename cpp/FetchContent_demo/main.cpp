#include <fmt/format.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

int main(int, char**)
{
    fmt::print("hello world, {}\n", 42);
}
