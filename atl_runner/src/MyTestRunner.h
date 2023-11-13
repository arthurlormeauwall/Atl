#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"
#include "AnotherModule.h"

class MyTests  : public AllTestBuilder {
public:
	MyTests() {}
	void addChildren() override {
		add(createModuleBuilder<MyModule>("My Module"));
		add(createModuleBuilder<AnotherModule>("Another ModuleInit"));
	}
};

class MyRunner : public AtlController {
public:
	MyRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}
};
