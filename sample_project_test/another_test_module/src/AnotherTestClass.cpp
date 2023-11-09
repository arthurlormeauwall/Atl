#include "atl_includes.h"
#include "TestClassDeclarations.h"

void AnotherTestClass::addChildren() {
	add(createUnitTest("A test that should succeed",
		[](Path path)->std::vector<Result>
		{
			Assertions assertions;
			assertions.push_back(assertThat<float>(0.3F).isEqualTo(0.3F)->getResult(path));
			return assertions;
		}
	));
}
