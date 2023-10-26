#pragma once

#define DECLARE_RUNNER(outputWriter) \
class MyTestRunner : public AtlController { \
public:\
	MyTestRunner() : AtlController(std::make_shared<outputWriter>()) {}\
	void addModules();\
};\

#define RUN_ALL_TEST \
MyTestRunner testRunner = MyTestRunner();\
testRunner.runAllTests();\

#define DEFINE_MODULES \
void MyTestRunner::addModules() {\

#define END_MODULES }

#define ADD_MODULE(moduleName) \
addRunner(std::make_shared<moduleName> ()); 



#define DECLARE_TEST_CLASS(modulename, testclassname, className) \
class className : public UnitTestController \
{ \
public: \
	names path {modulename, testclassname};\
	void addTests(); \
}; \

#define DEFINE_TESTS(className) \
void className::addTests() \
{\

#define ADD_UNIT_TEST(unitTestName, test) \
add(std::make_shared<UnitTest>(path.moduleName, path.testClassName, unitTestName,\
[](Path path) -> std::vector<std::shared_ptr<Result>> {\
	std::vector<std::shared_ptr<Result>> aresults;\
		test \

#define UNIT_TEST_END  return aresults;\
	}));\


#define ASSERT(assert) aresults.push_back(assert->getResult(path));

#define END_UNIT_TEST \
	for (std::shared_ptr<Assertion<float>> a : m_assertResults) { \
		aresults.push_back(a->getResult(path)); \
	} \
	return aresults; \
	}));\

#define END_TESTS  }
