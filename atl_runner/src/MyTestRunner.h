#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"

class MyTests  : public AllTestInit {
public:
	MyTests() {}
	void addChildren() {
		add(createModuleInit<MyModule>("My ModuleInit"));
		//add(createModuleInit<AnotherModuleInit>("Another ModuleInit"));
	}
};

class MyRunner : public AtlController {
public:
	MyRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}
};
