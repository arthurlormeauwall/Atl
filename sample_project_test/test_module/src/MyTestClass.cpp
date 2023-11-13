#include "MyTestClass.h"
#include "MyClass.h"
#include "atl_includes.h"

void MyTestClass::addChildren() {
	add(createUnitTestBuilder("should add two number",
		[]()->std::vector<Result>
		{
			Assertions assertions;
			MyClass<float> obj;
			float expected = 5.;
			float actual = obj.add(2., 3.);
			assertions.push_back(assertThat<float>(actual).isEqualTo(expected)->getResult());
			return assertions;
		}
	));
}
