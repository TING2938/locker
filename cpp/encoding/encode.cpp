// TINGCODE method

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

union Buffer
{
    char c;
    struct
    {
        bool b0 : 1;  // low
        bool b1 : 1;
        bool b2 : 1;
        bool b3 : 1;
        bool b4 : 1;
        bool b5 : 1;
        bool b6 : 1;
        bool b7 : 1;  // high
    } b;
};

#define SWAP_BITS(buffer, m, n)        \
    do {                               \
        bool tmp      = buffer.b.b##m; \
        buffer.b.b##m = buffer.b.b##n; \
        buffer.b.b##n = tmp;           \
    } while (0)

void encode(const std::string& input_fnm)
{
    int mask        = std::time(nullptr);
    auto output_fnm = input_fnm + "." + std::to_string(mask);

    std::ifstream is(input_fnm, std::ios::binary);
    std::ofstream os(output_fnm, std::ios::binary);

    Buffer buffer;
    bool tmp;
    while (is.read(&buffer.c, sizeof(buffer))) {
        buffer.b.b0 = !buffer.b.b0;
        buffer.b.b2 = !buffer.b.b2;
        buffer.b.b6 = !buffer.b.b6;
        SWAP_BITS(buffer, 0, 5);
        SWAP_BITS(buffer, 2, 7);
        SWAP_BITS(buffer, 6, 4);
        SWAP_BITS(buffer, 1, 3);
        buffer.c ^= mask;
        os.write(&buffer.c, sizeof(buffer));
    }
    is.close();
    os.close();
}

void decode(const std::string& input_fnm, const std::string& output_fnm, int mask)
{
    mask -= 5;
    std::ifstream is(input_fnm, std::ios::binary);
    std::ofstream os(output_fnm, std::ios::binary);

    Buffer buffer;
    bool tmp;
    while (is.read(&buffer.c, sizeof(buffer))) {
        buffer.c ^= mask;
        SWAP_BITS(buffer, 1, 3);
        SWAP_BITS(buffer, 6, 4);
        SWAP_BITS(buffer, 2, 7);
        SWAP_BITS(buffer, 0, 5);
        buffer.b.b0 = !buffer.b.b0;
        buffer.b.b2 = !buffer.b.b2;
        buffer.b.b6 = !buffer.b.b6;
        os.write(&buffer.c, sizeof(buffer));
    }
    is.close();
    os.close();
}

void test()
{
    auto now = std::time(nullptr);

    Buffer buffer;
    buffer.c = now;
    std::cout << buffer.b.b7 << buffer.b.b6 << buffer.b.b5 << buffer.b.b4 << buffer.b.b3 << buffer.b.b2 << buffer.b.b1
              << buffer.b.b0 << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 3 || !(argv[1] == std::string("encode") || argv[1] == std::string("decode"))) {
        std::cout << R"(encode or decode a file
Usage: encode input_fnm
       decode input_fnm output_fnm mask)"
                  << std::endl;
        return -1;
    }

    if (argv[1] == std::string("encode")) {
        encode(argv[2]);
    } else {
        decode(argv[2], argv[3], std::atoi(argv[4]));
    }
}
