#include "TestClassDeclarations.h"

void AThirdTestClass::addUnitTests() {
	createUnitTest("A test that should fail",
		[]()->vector<Result> {
			vector<Result> assertions;
			assertions.push_back(IsEqualTo<string>("expected", "expected").getResult());
			return assertions;
		}
	);
	createUnitTest("Another test that should succeed",
		[]()->vector<Result>
		{
			vector<Result> assertions;
			assertions.push_back(IsEqualTo<int>(2, 2).getResult());
			return assertions;
		}
	);
}
