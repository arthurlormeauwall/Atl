#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

class MyModule: public ModuleBuilder {
public:

	MyModule(TestData td) : ModuleBuilder(td) {}
	virtual void addChildren() override {
		add(createTestClassBuilder<MyTestClass>("My Test class"));
	}
};