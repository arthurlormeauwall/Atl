#pragma once

#define DECLARE_RUNNER_WITH_CONSOLE_OUTPUT \
class MyTestRunner : public AtlController { \
public:\
	MyTestRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}\
	void addModules();\
};\

#define RUN_ALL_TEST \
MyTestRunner testRunner = MyTestRunner();\
testRunner.runAllTests();\

#define DEFINE_MODULES \
void MyTestRunner::addModules() {\

#define END_MODULES }

#define ADD_MODULE(moduleName) \
for (std::shared_ptr<UnitTestController> ut : moduleName){ \
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


#define END_TESTS  }

#define SPECIFY_MODULE(modulename) std::string moduleName = #modulename; 
#define DECLARE_MODULE(modulename) namespace modulename {\
std::vector<std::shared_ptr<UnitTestController>> getModuleTestClasses();\
std::vector<std::shared_ptr<UnitTestController>> getModule();}\


//std::vector<std::shared_ptr<UnitTestController>> getModuleTestClasses() { \
//	std::vector<std::shared_ptr<UnitTestController>> ut; \


#define START_ADDING_TEST_CLASS_TO_MODULE(modulename) namespace MyModule {\
std::vector<std::shared_ptr<UnitTestController>> getModuleTestClasses() {\
	std::vector<std::shared_ptr<UnitTestController>> ut;\

#define ADD_TEST_CLASS(testClassName) ut.push_back(std::make_shared<testClassName>()); \

#define END_ADDING_TEST_CLASS_TO_MODULE	return ut; }\
	std::vector<std::shared_ptr<UnitTestController>> getModule() {\
		return getModuleTestClasses(); } }\


