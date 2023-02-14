module;

#include <iostream>
#include <format>
#include <type_traits>
#include <numeric>
#include <algorithm>
#include <vector>

export module concept_demo;

export namespace cpp20::concept_demo {
	template <typename T>
	concept signed_number = std::is_arithmetic_v<T> && std::is_signed_v<T>;

	template <signed_number T>
	T mysum(T a, T b)
	{
		return a + b;
	}

	template <typename T>
	concept draft = requires (T v)
	{
		{v.abs()} -> std::same_as<bool>;
	};

	template <typename T>
	concept vector_type = requires(T v) {
		requires !draft<T>;
	v.size();
	v.begin();
	v.end();
	std::convertible_to<decltype(v[0]), int>;
	};

	template <vector_type T>
	auto vector_sum(const T& vec)
	{
		return std::accumulate(vec.begin(), vec.end(), 0);
	}

	template <typename T>
	auto vector_sum_v1(const T& vec) requires vector_type<T>
	{
		return std::accumulate(vec.begin(), vec.end(), 0);
	}
}
