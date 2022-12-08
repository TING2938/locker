#include <iostream>
#include <format>
#include <type_traits>
#include <numeric>
#include <algorithm>
#include <vector>

#include "concept_demp.h"
#include "ranges_demo.h"

import A.test;

int main()
{
	std::vector<int> vec{3, 1, 7, 9};
	
	std::cout << std::format("hello world {}, {}\n", vec.at(0), vector_sum(vec));
	vector_sum_v1(vec);
	ranges_demo();

	Secret aa = A::MyFunc(1, 2);

	std::cout << "MyFunc: " << aa._a << std::endl;
}
