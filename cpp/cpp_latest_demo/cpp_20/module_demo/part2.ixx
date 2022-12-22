export module A.test:part2;

import :part1;

export namespace cpp20::module_demo::part2
{
	int mysum(int a, int b)
	{
		int c = part1::mysum(a, b);
		return a + 2 * b + c;
	}
}
