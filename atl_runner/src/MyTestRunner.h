#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"

class MyRunner : public AtlController {
public:
	MyRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}
	void addModules() {
		for (std::shared_ptr<UnitTestController> ut : getTestClasses_MyModule()) {
			addRunner(ut);
		}
	}
};