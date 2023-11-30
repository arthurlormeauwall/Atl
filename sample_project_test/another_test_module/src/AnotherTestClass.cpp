#include "atl_includes.h"
#include "TestClassDeclarations.h"

void AnotherTestClass::addUnitTests() {
	createUnitTest("A test that should succeed",
		[]()->vector<Result> {
			vector<Result> assertions;
			assertions.push_back(IsEqualTo<float>(1,1).getResult());
			return assertions;
		}
	);
}
