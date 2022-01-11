#include "hi.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include "test.pb.h"


std::string str = "";

Gostr hi2() {
    
    test::helloworld hw;
    hw.set_id(32);
    hw.set_str("hello, world");
    hw.set_wow(42);

    hw.SerializeToString(&str);

    std::cout << "Hello Cgo!, s=" << str << std::endl;

    return {(void*) str.data(), str.size()};
}
