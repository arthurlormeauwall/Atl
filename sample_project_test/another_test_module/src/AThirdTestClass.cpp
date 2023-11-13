#include "TestClassDeclarations.h"

void AThirdTestClass::addChildren() {
	add(createUnitTestBuilder("A test that should fail",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			assertions.push_back(assertThat<float>(0.3F).isEqualTo(49.0F)->getResult());
			return assertions;
		}
	));
}
