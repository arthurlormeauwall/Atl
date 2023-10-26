#pragma once
#include "atl_includes.h"

class MyTestClass : public UnitTestController {
public: 
	TestClassPath path{ "a module", "a test class name" }; 
	void addTests();
};

