#include "libtest.h"
#include <iostream>
#include <cstring>

int main()
{
    auto ret = Foo(1, 2);
    std::cout << ret << std::endl;

    const char* str = "hello world";
    GoString gostr;
    gostr.p = str;
    gostr.n = strlen(str);
    Bar(gostr);


}