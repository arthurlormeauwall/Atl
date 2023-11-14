#pragma once
#include "atl_includes.h" 
#include "AnotherModule.h"
#include "MyModule.h"
#include "AnotherModule.h"

#define ADD_MODULE(name) add(createModuleBuilder<name>(#name))
#define DECLARE_TEST_BUILDER(name, content) class name  : public AllTestBuilder {\
public:\
	name() {}\
	void addChildren() override {\
		content\
	}\
}\

#define DECLARE_CONTROLLER(name, output) class name : public AtlController {\
public:\
	name() : AtlController(std::make_shared<output>()) {}\
}\

DECLARE_TEST_BUILDER(MyTests,
	ADD_MODULE(MyModule);
    ADD_MODULE(AnotherModule);
);

DECLARE_CONTROLLER(MyRunner, ConsoleOutputWriter);

