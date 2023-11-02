#include "MyTestClass.h"

#include "MyClass.h"
#include "atl_includes.h"
#include "service/assertion/Assertion.h"

void MyTestClass::addChildren() {
	add(createUnitTest("should add two number",
		[](Path path)->std::vector<std::shared_ptr<Result>>
		{
			Assertions assertions;
			MyClass<float> fixture;
			float a = 3.F;
			float b = 2.F;
			float actual = fixture.add(a, b);
			float expected = 5.F; assertions.push_back(assertThat<float>(actual).isEqualTo(3.0F)->getResult(path));;
			return assertions;
		}
	));
}
