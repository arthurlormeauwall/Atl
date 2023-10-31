#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"

class MyTests : public AllTest {
	void addModules() {
		modules.push_back(std::make_shared<MyModule>("My Module"));
		modules.push_back(std::make_shared<AnotherModule>("Another Module"));
	}
};

class MyRunner : public AtlController {
public:
	MyRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}
};
