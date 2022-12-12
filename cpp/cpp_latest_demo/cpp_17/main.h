#include "feature.h"
#include "struct_binding_demo.h"

namespace cpp17
{
	auto main()
	{
		std::cout << "\n\ncpp 17 demo begin =============================" << std::endl;
		
		class_template_type_decl();

		struct_binding::main();

		std::cout << "cpp 17 demo end ===============================" << std::endl;
	}
}
