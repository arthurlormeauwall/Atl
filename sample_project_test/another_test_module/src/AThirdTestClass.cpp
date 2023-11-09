#include "TestClassDeclarations.h"

void AThirdTestClass::addChildren() {
	add(createUnitTest("A test that should fail",
		[](Path path)->std::vector<Result>
		{
			Assertions assertions;
			assertions.push_back(assertThat<float>(0.3F).isEqualTo(0.88F)->getResult(path));
			return assertions;
		}
	));
}
