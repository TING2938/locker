
#include <functional>
#include <iostream>

class Foo
{
    int age = 0;

public:
    Foo() = default;
    Foo(int age) : age(age) {}

    void print()
    {
        std::cout << this->age << std::endl;
    }
};

int main()
{
    Foo foo(4);
    auto func = std::mem_fn(&Foo::print);

    func(foo);
}
