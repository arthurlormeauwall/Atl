#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"
#include "AnotherModule.h"

class MyTests  : public AllTestBuilder {
public:
	MyTests() {}
	void addModules() override {
		createModule<MyModule>("My Module");
		//createModule<AnotherModule>("Another Module");
	}
};

class MyRunner : public AtlController {
public:
	MyRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}
};
