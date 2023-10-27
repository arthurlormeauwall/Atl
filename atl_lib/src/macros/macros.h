#pragma once
#include <memory>
#include <vector>
#include "model/TestResultContainer.h"

using Assertions = std::vector<std::shared_ptr<Result>>;

#define Runner_Declaration_With_Console_Output(runnername, content) class runnername : public AtlController { \
public:\
	runnername() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}\
	void addModules() {\
	content\
	}\
};\

#define Runner_Modules(runnername, content) void runnername::addModules() {\
content\
}\

#define Run_All_Tests(runnername) runnername testRunner = runnername();\
testRunner.runAllTests();\

#define DEFINE_MODULES \
void MyTestRunner::addModules() {\

#define Add_Module(moduleName) \
for (std::shared_ptr<UnitTestController> ut : getTestClasses_##moduleName()){ \
	addRunner(ut); \
}\

#define Test_Class_Declaration(modulename, testclassname) class testclassname##_ : public UnitTestController {\
public:\
	void addTests();\
};\
struct testclassname {\
std::string testclassname##_className = #testclassname;\
std::string testclassname##_moduleName = modulename;\
};


#define Unit_Test_Definition(className, content) className names_##className ;\
static std::string tcn = names_##className.className##_className ;\
static std::string mn = names_##className.className##_moduleName ;\
void className##_::addTests() { content }\

#define create_unit_test(unitTestName, test) add(std::make_shared<UnitTest>( \
mn, tcn, unitTestName,\
[](Path path)->std::vector<std::shared_ptr<Result>> { \
Assertions assertions;\
test \
return assertions; }));\

#define Module_Declaration(modulename, content) std::vector<std::shared_ptr<UnitTestController>> getTestClasses_##modulename() {\
	std::vector<std::shared_ptr<UnitTestController>> ut; \
	content \
return ut; }\


#define Module_Test_Classes(modulename, content) namespace modulename {\
std::vector<std::shared_ptr<UnitTestController>> getTestClasses() {\
	std::vector<std::shared_ptr<UnitTestController>> ut; content \
return ut; }}\

#define add_test_class(testClassName) ut.push_back(std::make_shared<testClassName##_>()); \


#define add_assertion(assert) push_back(assert->getResult(path))



#define declare_assertion(assertion) assertions.add_assertion(assertion);\

#define declare_code if (true==true) 
