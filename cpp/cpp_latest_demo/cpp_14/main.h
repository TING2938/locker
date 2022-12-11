#include "feature.h"

namespace cpp14
{
	auto main()
	{
		std::cout << "\n\ncpp 14 demo begin =============================" << std::endl;
		auto ret = autoReturnFunc();
		auto f = autoLambda();
		std::cout << "autoLambda: " << f(1) << std::endl;

		varTemplate();

		constexpr auto fact_ret = factorial(165555);
		std::cout << "factorial(5): " << fact_ret << std::endl;

		std::cout << "deprecatedMark(2): " << deprecatedMark(2) << std::endl;

		binaryText();
		make_unique_demo();
		
		print_sequence(std::integer_sequence<int, 9, 4, 2, 3>{});
		exchange_demo();
		quoted_demo();
		std::cout << "cpp 14 demo end ===============================" << std::endl;
	}
}
