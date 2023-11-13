#include "atl_includes.h"
#include "TestClassDeclarations.h"

void AnotherTestClass::addChildren() {
	add(createUnitTestBuilder("A test that should succeed",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			assertions.push_back(assertThat<float>(0.3F).isEqualTo(0.3F)->getResult());
			return assertions;
		}
	));
}
