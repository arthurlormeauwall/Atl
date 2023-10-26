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
addRunner(std::make_shared<moduleName> ()); 

#define DECLARE_TEST_CLASS(modulename, testclassname) \
struct Names {std::string moduleName = modulename ; \
std::string testclassName = #testclassname ;}; \
class testclassname : public UnitTestController { \
public:\
	void addTests();\
};\

#define DEFINE_TESTS(className) \
Names names; \
void className::addTests() \
{\

#define CREATE_UT(unitTestName) names.moduleName, names.testclassName, \
unitTestName, [](Path path)->std::vector<std::shared_ptr<Result>> \


#define END_TESTS  }
