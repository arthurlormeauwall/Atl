#pragma once

#define DECLARE_RUNNER_WITH_CONSOLE_OUTPUT(runnername) class runnername : public AtlController { \
public:\
	runnername() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}\
	void addModules();\
};\

#define ADDING_TEST_CLASS_TO_RUNNER(runnername) void runnername::addModules() {

#define RUN_ALL_TEST(runnername) runnername testRunner = runnername();\
testRunner.runAllTests();\

#define DEFINE_MODULES \
void MyTestRunner::addModules() {\

#define ADD_MODULE(moduleName) \
for (std::shared_ptr<UnitTestController> ut : moduleName::getTestClasses()){ \
	addRunner(ut); \
}\

#define DECLARE_TEST_CLASS(testclassname) \
class testclassname : public UnitTestController {\
public:\
	void addTests();\
};\

#define DEFINE_TESTS(className) \
static std::string testClassName = #className ;\
void className::addTests() \
{\

#define CREATE_UT(unitTestName) moduleName, testClassName, unitTestName,\
[](Path path)->std::vector<std::shared_ptr<Result>> \


#define END  }

#define SPECIFY_MODULE(modulename) std::string moduleName = #modulename; 
#define DECLARE_MODULE(modulename) namespace modulename {\
std::vector<std::shared_ptr<UnitTestController>> getTestClasses();}\


#define START_ADDING_TEST_CLASS_TO_MODULE(modulename) namespace MyModule {\
std::vector<std::shared_ptr<UnitTestController>> getTestClasses() {\
	std::vector<std::shared_ptr<UnitTestController>> ut;\

#define ADD_TEST_CLASS(testClassName) ut.push_back(std::make_shared<testClassName>()); \

#define END_ADDING_TEST_CLASS_TO_MODULE	return ut; }}\


