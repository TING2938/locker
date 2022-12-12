#include <tuple>
#include <map>
#include <iostream>
#include <string_view>

using namespace std::string_view_literals;

namespace cpp17::struct_binding
{
	struct Point
	{
		int x;
		int y;
	};

	auto basic()
	{
		auto [i, v] = std::tuple{1, "a"sv};
		std::cout << i << " " << v << std::endl;

		std::map<int, std::string_view> m{
			{32, "agv"sv},
			{54, "6433ds"sv},
			{76, "d5e"sv},
		};
		for (auto& [key, value] : m)
		{
			std::cout << key << ": " << value << std::endl;
		}

		Point p{1, 2};
		auto [x, y] = p;
	}

	auto main()
	{
		basic();
	}
}
