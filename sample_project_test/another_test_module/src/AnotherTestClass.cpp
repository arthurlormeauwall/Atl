#include "atl_includes.h"
#include "TestClassDeclarations.h"

Unit_Test_Definition(AnotherTestClass,

create_unit_test("A test that should fail",
		declare_assertion(assertThat<float>(0.8F).isEqualTo(0.9F))
	)

	create_unit_test("Another test that should fail",
		declare_assertion(assertThat<std::string>("actual").isEqualTo("expected"))
	)
)

