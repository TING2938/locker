#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <charconv>
#include <variant>
#include <optional>
#include <any>

using namespace std;

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

	// 2. if (init; condition)
	auto if_init_demo()
	{
		vector vec{2, 1, 4};
		if (auto size = vec.size(); size < 4)
		{
			cout << size << endl;
		}
	}

	// 3. inline 变量 
	struct AA_inline {
		inline static int value = 10;
	};

	// 4. constexpr lambda
	auto constexpr_lambda_demo()
	{
		constexpr auto f = [](auto val) {return val + 2; };
		constexpr auto ret = f(3);
		return ret;
	}

	// 5. namespace可以嵌套
	namespace AA::BB::CC
	{
		auto func()
		{
			return 1;
		}
	}

	// 6. __has_include预处理器，判断头文件是否存在
#if defined __has_include
#if __has_include(<string_view>)
#define has_string_view 1
#include <string_view>
#else 
#define has_string_view 0
#endif
#endif

	// 7. lambda捕获*this，持有对象的拷贝
	struct A {
		int a;
		void func()
		{
			auto f = [*this] {
				cout << a << endl;
			};
			f();
		}
	};

	// 7. 新增attribute
	/**
	* [[carries_dependency]] 让编译器跳过不必要的内存栅栏指令
	* [[noreturn]] 函数不会返回
	* [[deprecated]] 函数弃用警告
	* [[fallthrough]] 在switch语句中提示可以直接落下，不需要break
	* [[nodiscard]] 修饰的内容不能被忽略
	* [[maybe_unused]] 提示编译器修饰的内容可能暂时没用到
	*/
	namespace attr
	{
		[[nodiscard]] int func1() { return 1; }
		[[noreturn]] void terminate() {}
		[[deprecated("use new func instead")]] void func() {}
		auto fallthrough_demo()
		{
			int i = 1;
			switch (i)
			{
			case 0:
				cout << "i=0" << endl;
				break;
			case 1:
				cout << "i=1" << endl;
				[[fallthrough]];
			default:
				break;
			}
		}

		auto maybe_unused_demo() {
			int x = 1;
			[[maybe_unused]] int y = 2;
		}

		auto main()
		{
			terminate();
			auto ret = func1();
			func();
			fallthrough_demo();
			maybe_unused_demo();
		}
	}

	// 8. from_chars/to_chars函数
	auto from_to_chars_demo()
	{
		cout << __FUNCTION__ << endl;
		string str{ "123456098" };
		int value = 0;
		auto res = from_chars(str.data(), str.data() + 4, value);
		if (res.ec == std::errc())
		{
			cout << value << ", distance " << res.ptr - str.data() << endl;
		}
		else if (res.ec == std::errc::invalid_argument)
		{
			cout << "invalid" << endl;
		}

		str = "12.34";
		double val = 0;
		res = from_chars(str.data(), str.data() + str.size(), val);
		cout << "val: " << val << endl;

		str = "xxxxxxxx";
		int v = 1234;
		auto res1 = to_chars(str.data(), str.data() + str.size(), v);
		cout << str << ", filled " << res.ptr - str.data() << " characters\n";
	}

	// 9. std::variant, 类似union功能，但更强大，可以支持任意类型
	auto variant_demo()
	{
		cout << __FUNCTION__ << endl;

		variant<int, string_view> var{"hello"};
		cout << var.index() << endl;
		var = 3;
		cout << var.index() << endl;

		var = "world";
		auto& str = get<string_view>(var);
		cout << "str: " << str << endl;
		var = 4;
		auto i = get<0>(var);
		cout << "i: " << i << endl;
	}

	// 10. std::optional
	optional<int> myStoI(const string& str)
	{
		try {
			return std::stoi(str);
		}
		catch (...)
		{
			return std::nullopt;
		}
	}
	auto optional_demo()
	{
		cout << __FUNCTION__ << endl;
		auto ret = myStoI("b12b35a");
		if (ret) {
			cout << *ret << endl;
		}
		else {
			cout << "error" << endl;
		}
	}

	// 11. std::any 可以存储任意类型的单个值 
	auto any_demo()
	{
		cout << __FUNCTION__ << endl;
		std::any a = 1;
		cout << a.type().name() << " " << any_cast<int>(a) << endl;

		a = 1.2;
		cout << a.type().name() << " " << any_cast<double>(a) << endl;

		a = "hello world"sv;
		cout << a.type().name() << " " << any_cast<string_view>(a) << endl;

		a = 2.3f;
		if (a.has_value()) {
			cout << a.type().name() << endl;
		}
	}

	// 12. std::apply
	constexpr auto apply_demo()
	{
		constexpr auto ret = std::apply([](auto msg, auto age) {
			return msg.size() / age;
		}, make_tuple("hello world"sv, 18.));
		return ret;
	}

	// 13. string_view
	auto string_view_demo()
	{
		cout << __FUNCTION__ << endl;
		string str{ "hello world" };
		string s("hello"sv);
		string_view str_view(str);
		cout << str_view << endl;
	}

	// 14. as_const 将左值转化成const类型
	auto as_const_demo()
	{
		cout << __FUNCTION__ << endl;
		string str{ "hello" };
		auto& constStr = std::as_const(str);
		cout << constStr << endl;
		str = "world";
		cout << constStr << endl;
	}
}
