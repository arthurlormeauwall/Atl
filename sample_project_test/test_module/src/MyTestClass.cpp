#include "MyTestClass.h"
#include "atl_includes.h"

#define isEqualTo(T, actual, expected) IsEqualTo<T>(actual, expected).getResult(\
				[](T a, T e)->bool { return a == e; },\
				[](T it)->string { return std::to_string(it); })\

#define isEqualToCustomToString(T, actual, expected, toString) IsEqualTo<T>(actual, expected).getResult(\
				[](T a, T e)->bool { return a == e; },\
				toString)\

#define addAssertion push_back 

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
