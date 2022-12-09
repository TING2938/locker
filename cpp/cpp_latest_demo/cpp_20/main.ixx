module;

#include <iostream>
#include <format>
#include <type_traits>
#include <numeric>
#include <algorithm>
#include <vector>

export module cpp20;

import ranges_demo;
import concept_demo;
import A.test;

export namespace cpp20 {
	void main()
	{
		std::cout << "\n\ncpp 20 demo begin =============================" << std::endl;

		std::vector<int> vec{ 3, 1, 7, 9 };

		std::cout << std::format("hello world {}, {}\n", vec.at(0), vector_sum(vec));
		vector_sum_v1(vec);
		ranges_demo();

		Secret aa = A::MyFunc(1, 2);

		std::cout << "MyFunc: " << aa._a << std::endl;

		std::cout << "cpp 20 demo end ===============================" << std::endl;
	}
}
