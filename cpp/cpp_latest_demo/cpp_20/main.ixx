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
import feature;
import A.test;

export namespace cpp20 {
	void main()
	{
		std::cout << "\n\ncpp 20 demo begin =============================" << std::endl;

		std::vector<int> vec{ 3, 1, 7, 9 };

		std::cout << std::format("hello world {}, {}\n", vec.at(0), concept_demo::vector_sum(vec));
		concept_demo::vector_sum_v1(vec);
		range_demo::ranges_demo();

		Secret aa = module_demo::MyFunc(1, 2);
		std::cout << "MyFunc: " << aa._a  << " " << module_demo::part1::mysum(1, 2) << std::endl;
		
		feature::main();

		std::cout << "cpp 20 demo end ===============================" << std::endl;
	}
}
