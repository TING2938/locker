#include <iostream>
#include <format>
#include <type_traits>
#include <numeric>
#include <algorithm>
#include <vector>

#include "concept_demp.h"

int main()
{
	std::vector<int> vec{3, 1, 7, 9};
	
	std::cout << std::format("hello world {}, {}\n", vec.at(0), vector_sum(vec));
}


