#include "MyTestClass.h"
#include "MyClass.h"
#include "atl_includes.h"

DEFINE_UNIT_TESTS(MyTestClass)
ADD_UNIT_TEST("Should add two numbers")
{
	Assertions assertions;
	MyClass<float> obj;
	float expected = 5.;
	float actual = obj.add(2., 3.);
	assertions.add_build_in_assert(assertThat(actual).isEqualTo(expected));
	return assertions;
}
END_UT

ADD_UNIT_TEST("should fail")
{
	Assertions assertions;
	MyClass<float> obj;
	float expected = 5.;
	float actual = obj.add(2., 3.);
	assertions.add_build_in_assert(assertThat(3.).isEqualTo(5.));
	return assertions;
}
END_UT
END
