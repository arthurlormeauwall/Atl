#include "atl_includes.h"
#include "TestClassDeclarations.h"

void AnotherTestClass::addUnitTests() {
	createUnitTest("A test that should succeed",
		[]()->Assertions {
			Assertions assertions;
			assertions.addAssertion(isEqualTo(float, 0.4F, 0.4F));
			return assertions;
		}
	);
}
