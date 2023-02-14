#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <mutex>
#include <shared_mutex>
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
		auto f = [](auto a) { return a + 1; };
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

	// 9. std::shared_mutex
	// - shared_lock是read lock，搭配std::shared_mutex使用，被锁后仍可以被其他线程用同样的shared_lock使用
	// - lock_guard或unique_lock是write lock，被锁后不允许其他线程的shared_lock访问
	struct ThreadSafe {
		using ReadLock = std::shared_lock<std::shared_mutex>;
		using WriteLock = std::unique_lock<std::shared_mutex>;

		mutable std::shared_mutex mutex_;
		int value_ = 0;

		int get_value() const
		{
			ReadLock lock(mutex_);
			return value_;
		}

		void increase_value()
		{
			WriteLock lock(mutex_);
			value_++;
		}
	};

	// 10. std::integer_sequence
	template <typename T, T... ints>
	void print_sequence(std::integer_sequence<T, ints...> int_seq)
	{
		std::cout << "The sequence of size: " << int_seq.size() << std::endl;
		((std::cout << ints << ' '), ...);
		std::cout << std::endl;
	}


	// 11. std::exchange
	// 仅仅把新值移动给当前，当前值未移动给新值
	//
	auto exchange_demo()
	{
		std::vector<int> vec;
		std::exchange(vec, { 1, 2, 3 });
		for (auto v : vec)
		{
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}

	// 12. std::quoted 给字符串加引号
	// 
	auto quoted_demo()
	{
		std::string str{ "hello world" };
		std::cout << str << std::endl;
		std::cout << std::quoted(str) << std::endl;
	}
}
