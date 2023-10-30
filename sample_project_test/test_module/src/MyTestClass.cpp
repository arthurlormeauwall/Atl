#include "MyTestClass.h"

#include "MyClass.h"
#include "atl_includes.h"
#include "service/assertion/Assertion.h"

MyTestClass names_MyTestClass;
static std::string tcn = names_MyTestClass.MyTestClass_className;
static std::string mn = names_MyTestClass.MyTestClass_moduleName;
void MyTestClass_::addTests() {
	add(std::make_shared<UnitTest>(mn, tcn, "should add two number", [](Path path)->std::vector<std::shared_ptr<Result>>
		{ Assertions assertions;
	MyClass<float> fixture;
	float a = 3.F;
	float b = 2.F;
	float actual = fixture.add(a, b);
	float expected = 5.F; assertions.push_back(assertThat<float>(actual).isEqualTo(expected)->getResult(path));;
	return assertions; })
	);
}
