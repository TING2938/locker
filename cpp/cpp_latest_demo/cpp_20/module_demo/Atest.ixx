module;

#include <iostream>

export module A.test;

export import :part1;
import :part2;
import :part3;

export class Secret
{
public:
	Secret(int a) : _a(a) {}
	int _a;
};

export using Secret_alias = Secret;

export namespace cpp20::module_demo
{
	Secret MyFunc(int a, int b)
	{
		int c = part2::mysum(a, b);
		std::cout << "in MyFunc: " << a << " " << b << c <<  std::endl;
		return a + 2 * b;
	}
}
