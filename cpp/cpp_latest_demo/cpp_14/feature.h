#include <iostream>
#include <string>
#include <vector>
#include <memory>

// https://segmentfault.com/a/1190000023441427
namespace cpp14
{
	// 1. auto return type
	auto autoReturnFunc()
	{
		return std::vector<int>{1, 2, 4, 6, 8};
	}

	// 2. auto lambda
	auto autoLambda()
	{
		auto f = [](auto a) { return a+1; };
		return f;
	}

	// 3. 变量模版
	template<typename T>
	constexpr T pi = T(3.141592353L);
	auto varTemplate()
	{
		std::cout << "pi<int>" << pi<int> << std::endl;
		std::cout << "pi<double>" << pi<double> << std::endl;
	}

	// 4. 模版别名
	template <typename T, typename S>
	struct AA {
		T t;
		S s;
	};
	template <typename T>
	using BB = AA<T, int>;

	// 5. constexpr函数内，可以使用局部变量和循环
	constexpr long long factorial(long long n)
	{
		long long ret = 0;
		for (long long i = 0; i < n; ++i)
		{
			ret += i;
		}
		return ret;
	}

	// 6. [[deprecated]]标记，可以修饰类，变量，函数等
	[[deprecated("deprecated test")]]
	auto deprecatedMark(int a) {
		return a + 1;
	}

	// 7. 二进制字面量，分隔符
	auto binaryText()
	{
		int a = 0b0001'0010'1110;
		double b = 3.14'159'263;
	}

	// 8. make_unique
	auto make_unique_demo()
	{
		return std::make_unique<int>();
	}
}
