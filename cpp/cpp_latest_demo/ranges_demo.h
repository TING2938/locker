#include <ranges>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
namespace views = std::views;

struct Employee {
	std::string name;
	int id;
};

void ranges_demo()
{
	// 1.
	std::string str = "hello world";
	std::ranges::sort(str);
	std::cout << str << std::endl;

	// 2. pipeline
	std::vector vec = {0, 1, 2, 3, 4, 5};
	for (auto i : vec 
			      | std::views::filter([](int i) {return i % 2 == 0;})
				  | std::views::transform([](int i) {return i * i;}))
	{
		std::cout << i << std::endl;
	}

	// 3. Projection
	std::vector<Employee> employees = {
		{"name1", 1},
		{"name13", 13},
		{"name2", 2},
		{"name9", 9},
		{"name5", 5},
	};
	// std::ranges::sort(employees, std::ranges::less{}, [](const auto& a) {return a.id; });
	std::ranges::sort(employees, std::ranges::less{}, &Employee::id);
	for (auto&& e : employees)
	{
		std::cout << e.name << " " << e.id << std::endl;
	}
}