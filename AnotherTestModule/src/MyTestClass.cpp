#include "atl_includes.h"
#include "MyTestClass.h"

SPECIFY_MODULE(AnotherModule)
DEFINE_TESTS(AnotherTestClass)

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
END

