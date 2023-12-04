#pragma once
#include "atl_includes.h"
#include "ItemTest.h"
#include <string>
#include <memory>
#include <vector>

class MyModule: public ModuleBuilder {
public:

	MyModule(TestData td) : ModuleBuilder(td) {}
	virtual void addTestClasses() override {
		createTestClass<ItemTest>("Test of item class");
	}
};