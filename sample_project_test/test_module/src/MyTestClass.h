#pragma once
#include "atl_includes.h"


class MyTestClass_ : public UnitTestController {
public:
	void addTests();
};
struct MyTestClass {
	std::string MyTestClass_className = "MyTestClass"; 
	std::string MyTestClass_moduleName = "My Module";
};