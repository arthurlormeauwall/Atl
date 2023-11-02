#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"

class MyTests  : public AllTest {
public:
	MyTests() {}
	void addChildren() {
		add(createModule<MyModule>("My module"));
	}
};

class MyRunner : public AtlController {
public:
	MyRunner() : AtlController(std::make_shared<ConsoleOutputWriter>()) {}
};
