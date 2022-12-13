#pragma once

#include <tuple>
#include <map>
#include <array>
#include <iostream>
#include <string_view>

using namespace std;
using namespace std::string_view_literals;

// 自定义类型，需实现tuple_size和tuple_element和get<N>方法
class Entry
{
public:
	Entry(const string& Name, int Age) : name(Name), age(Age) {}

	auto getName() const { return name; }
	auto getAge() const { return age; }
private:
	string name;
	int age;
};

template <size_t I>
auto get(const Entry& e) {
	if constexpr (I == 0)
		return e.getName();
	else if constexpr (I == 1)
		return e.getAge();
}

template<> struct std::tuple_size<Entry> : integral_constant<size_t, 2> {};
template<> struct std::tuple_element<0, Entry> { using type = string; };
template<> struct std::tuple_element<1, Entry> { using type = int; };

namespace cpp17::struct_binding
{
	struct Point
	{
		int x;
		int y;
	};

	auto basic()
	{
		{
			auto [i, v] = std::tuple{ 1, "a"sv };
			std::cout << i << " " << v << std::endl;
		}
		{
			std::map<int, std::string_view> m{
				{32, "agv"sv},
				{54, "6433ds"sv},
				{76, "d5e"sv},
			};
			for (auto& [key, value] : m)
			{
				std::cout << key << ": " << value << std::endl;
			}
		}
		{
			Point p{ 1, 2 };
			auto [x, y] = p;
		}
		{
			int arr[3]{ 2,1, 4 };
			auto& [x, y, z] = arr;
			y = 10;
			cout << "arr: "  << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		}
		{
			array arr{ 3, 5, 1, 7};
			auto& [x, y, z, w] = arr;
			y *= 2;
			for (auto&& a : arr) {
				cout << a << " ";
			}
			cout << endl;
		}
	}

	
	auto main()
	{
		basic();

		Entry e("yeting", 18);
		auto& [name, age] = e;

	}
}
