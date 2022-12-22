export module A.test:part3;

import :part2;

export namespace cpp20::module_demo::part3
{
	int mysum(int a, int b)
	{
		int c = part2::mysum(a, b);
		return a + 3 * b + c;
	}
}
