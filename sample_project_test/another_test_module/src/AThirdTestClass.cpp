#include "TestClassDeclarations.h"

void AThirdTestClass::addUnitTests() {
	createUnitTest("A test that should fail",
		[]()->Assertions {
			Assertions assertions;
			assertions.addAssertion(IsEqualTo<string>("actual", "expected").getResult());
			return assertions;
		}
	);
	createUnitTest("Another test that should succeed",
		[]()->Assertions
		{
			Assertions assertions;
			assertions.addAssertion(IsEqualTo<int>(2, 2).getResult());
			return assertions;
		}
	);
}
