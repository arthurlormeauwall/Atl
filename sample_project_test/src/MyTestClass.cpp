#include "service/assertion/Assertion.h"
#include "MyClass.h"
#include "MyTestClass.h"

DEFINE_TESTS(MyTestClass)
add(std::make_shared<UnitTest>(
	CREATE_UT("should add two numbers")
{
	MyClass<float> fixture;
	float a = 3.F;
	float b = 2.F;
	float actual = fixture.add(a, b);
	float expected = 5.F;

	std::vector<std::shared_ptr<Result>> aresults;
	aresults.push_back(assertThat<float>(actual).isEqualTo(expected)->getResult(path));
	return aresults;
}
));


add(std::make_shared<UnitTest>(
	CREATE_UT("A test that should fail")
{
	std::vector<std::shared_ptr<Result>> aresults;
	aresults.push_back(assertThat<float>(0.5F).isEqualTo(1.8F)->getResult(path));
	return aresults;
}
));


add(std::make_shared<UnitTest>(
	CREATE_UT("Another test that should fail")
{
	std::vector<std::shared_ptr<Result>> aresults;
	aresults.push_back(assertThat<std::string>("actual").isEqualTo("expected")->getResult(path));
	return aresults;
}
));
END_TESTS

