#include "TestClassDeclarations.h"

void AThirdTestClass::addUnitTests() {
	createUnitTest("A test that should fail",
		[]()->Assertions		{
			Assertions assertions;
			assertions.addAssertion(isEqualToString("actual", "expected"));
			return assertions;
		}
	);
	createUnitTest("Another test that should fail",
		[]()->Assertions
		{
			Assertions assertions;
			assertions.addAssertion(isEqualTo(int, 10,5));
			return assertions;
		}
	);
}
