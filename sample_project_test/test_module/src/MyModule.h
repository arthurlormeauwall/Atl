#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

class MyModule: public ModuleBuilder {
public:

	MyModule(TestData td) : ModuleBuilder(td) {}
	virtual void addTestClasses() override {
		createTestClass<MyTestClass>("My Test class");
	}
};