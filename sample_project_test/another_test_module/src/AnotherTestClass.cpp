#include "atl_includes.h"
#include "TestClassDeclarations.h"

void AnotherTestClass::addUnitTests() {
	createUnitTest("A test that should succeed",
		[]()->Assertions {
			Assertions assertions;
			//assertions.addAssertion(IsEqualTo<float>(1,1).getResult());
			return assertions;
		}
	);
}
