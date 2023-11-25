#include "MyTestClass.h"
#include "atl_includes.h"



void MyTestClass::addUnitTests() {
	createUnitTest("should add two number",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			float expected = 5.;
			float actual = 2.;
			assertions.addAssertion(isEqualToCustomToString(float, actual, expected,
				[](float it)->string {return std::to_string(it); }));
			return assertions;
		}
	);
}
