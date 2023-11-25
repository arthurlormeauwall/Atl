#include "MyTestClass.h"
#include "atl_includes.h"

void MyTestClass::addUnitTests() {
	createUnitTest("should add two number",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			float expected = 5.;
			float actual = 2.;
			assertions.push_back(IsEqualTo<float>(actual,expected).getResult());
			return assertions;
		}
	);
}
