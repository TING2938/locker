#include <iostream>
#include <string>
#include <vector>


// https://segmentfault.com/a/1190000023456766?utm_source=sf-similar-article
namespace cpp17
{
	// 1. 类模板类型推导 
	auto class_template_type_decl()
	{
		std::vector vec{1, 3, 2};
		for (auto v : vec)
			std::cout << v << " ";
		std::cout << std::endl;
	}
}
