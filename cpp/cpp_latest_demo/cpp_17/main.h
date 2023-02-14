#pragma once

#include "feature.h"
#include "struct_binding_demo.h"
#include "fold_expression_demo.h"
#include "file_system_demo.h"

namespace cpp17
{
	auto main()
	{
		std::cout << "\n\ncpp 17 demo begin =============================" << std::endl;
		
		class_template_type_decl();
		if_init_demo();
		AA_inline::value = 12;
		constexpr_lambda_demo();
		AA::BB::CC::func();
		attr::main();
		from_to_chars_demo();
		variant_demo();
		optional_demo();
		any_demo();
		apply_demo();
		string_view_demo();
		as_const_demo();

		struct_binding::main();

		fold_expression::main();

		filesystem::main();

		std::cout << "cpp 17 demo end ===============================" << std::endl;
	}
}
