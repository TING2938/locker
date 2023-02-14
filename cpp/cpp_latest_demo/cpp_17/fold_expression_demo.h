#pragma once

#include <string_view>

using namespace std::string_view_literals;

// https://cloud.tencent.com/developer/article/1347876
namespace cpp17::fold_expression
{
	/**
	 * 一元左折叠（unary left fold）
	 * ( ... op pack )
	 * 一元左折叠(... op E)展开之后变为 ((E1 op E2) op ...) op En
	 *
	 * 一元右折叠（unary right fold）
	 * ( pack op ... )
	 * 一元右折叠(E op ...)展开之后变为 E1 op (... op (EN-1 op En))
	 * 
	 * 二元左折叠（binary left fold）
	 * ( init op ... op pack )
	 * 二元左折叠(I op ... op E)展开之后变为 (((I op E1) op E2) op ...) op En
	 *
	 * 二元右折叠（binary right fold）
	 * ( pack op ... op init )
	 * 二元右折叠(E op ... op I)展开之后变为 E1 op (... op (EN−1 op (EN op I)))
	 * 
	 * 支持一下32种操作符：
	 * + - * / % ^ & | = < > << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*
	 */

	// 一元左/右折叠
	// 参数包...在操作符左边为左折叠
	template <typename... Args>
	constexpr auto sub_val_left(Args&&... args)
	{
		return (... - args);
	}

	template <typename... Args>
	constexpr auto sub_val_right(Args&&... args)
	{
		return (args - ...);
	}

	template <typename... Args> 
	constexpr auto sub_one_left(Args&&... args)
	{
		return (1 - ... - args);
	}

	template <typename... Args>
	constexpr auto sub_one_right(Args&&... args)
	{
		return (args - ... - 1);
	}

	template <typename... Args>
	auto printer1(Args&&... args)
	{
		((cout << args << " "), ...) << endl;
	}
	
	template <typename... Args>
	auto printer2(Args&&... args)
	{
		(cout << ... << args) << endl;
	}

	auto main()
	{
		constexpr auto r1 = sub_val_left(2, 3, 4); // ((2-3)-4) = -5
		constexpr auto r2 = sub_val_right(2, 3, 4); // (2-(3-4)) = 3
		constexpr auto r3 = sub_one_left(2, 3, 4); // (((1-2)-3)-4) = -8
		constexpr auto r4 = sub_one_right(2, 3, 4); // (2-(3-(4-1)) = 2

		printer1("name"sv, "yeting"sv, "age"sv, 18); // (cout << "name" << " "), ("yeting"), ("age"), (18)
		printer2("name"sv, "yeting"sv, "age"sv, 18);
	}
}
