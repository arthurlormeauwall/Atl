#include "service/assertion/Assertion.h"
#include "MyClass.h"
#include "anotherTestClass.h"



template<typename T>
std::vector<std::shared_ptr<Result>> addAssert(std::vector<std::shared_ptr<Assertion<T>> (*)> assert) {

}

void MyTestClass::addTests() 
{
	add(std::make_shared<UnitTest>(path.moduleName, path.testClassName,
		"should", [](Path path) -> std::vector<std::shared_ptr<Result>> 
		{
			MyClass<float> fixture;
			float a = 3.F;
			float b = 2.F;
			float actual = fixture.add(a, b);
			float expected = 5.F;
			
			std::vector<std::shared_ptr<Result>> aresults;
			aresults.push_back(assertThat<float>(actual).isEqualTo(expected)->getResult(path));
			return aresults;
		}));
}

