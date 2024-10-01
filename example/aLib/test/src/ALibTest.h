#pragma once
#include "ItemTest.h"

class ALibTest: public ModuleBuilder {
public:

	ALibTest(string name) : ModuleBuilder(name) {}
	virtual void addTestClasses() override {
		createTestClass<ItemTest>("Test of item class");
	}
};