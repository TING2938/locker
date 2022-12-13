module;

#include <string>
#include <string_view>
#include <iostream>
#include <format>

export module feature;

using namespace std;
using namespace std::string_literals;
using namespace std::string_view_literals;

// https://blog.csdn.net/qq811299838/article/details/105153096
export namespace cpp20::feature
{
	// 1. typename. 较多场合不需要写typename指定为类型名
	
	// 2. explicit. 新增bool参数，表示是否启用 
	struct A
	{
		explicit(true) A(int) {}
		explicit(false) A(string_view) {}
	};
	// A a = "10"sv; // ok
	// A aa = 1;     // error

	// 3. constexpr. 新增对虚函数的支持

	// 4. char8_t
	auto char8_t_demo()
	{
		char8_t c = 0;
	}

	// 5. consteval. 强制在编译器计算
	consteval int func(int a)
	{
		return a * 2 + 1;
	}
	auto consteval_demo()
	{
		const int a = 1;
		int* b = const_cast<int*>(&a);
		*b = 2;
		constexpr int ret = func(a);
		cout << format("ret = {}\n", ret);
	}

	auto main()
	{
		A a = "10"sv;
		char8_t_demo();
		consteval_demo();
	}
}
