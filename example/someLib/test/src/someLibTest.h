#pragma once
#include "ItemTest.h"

class SomeLibTest: public ModuleBuilder {
public:

	SomeLibTest(string name) : ModuleBuilder(name) {}
	virtual void addTestClasses() override {
		createTestClass<ItemTest>("Test of item class");
	}
};