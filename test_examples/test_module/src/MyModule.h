#pragma once
#include "atl_includes.h"
#include "ItemTest.h"
#include <string>
#include <memory>
#include <vector>

class MyModule: public ModuleBuilder {
public:

	MyModule(string name) : ModuleBuilder(name) {}
	virtual void addTestClasses() override {
		createTestClass<ItemTest>("Test of item class");
	}
};