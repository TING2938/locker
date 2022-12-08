module;

#include <iostream>

export module A.test;

export class Secret
{
public:
	Secret(int a) : _a(a) {}
	int _a;
};

export using Secret_alias = Secret;

export namespace A
{
	Secret MyFunc(int a, int b)
	{
		std::cout << "in MyFunc: " << a << " " << b << std::endl;
		return a + 2 * b;
	}
}
