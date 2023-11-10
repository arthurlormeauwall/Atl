#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

class MyModule: public ModuleInit {
public:

	MyModule(TestData td) : ModuleInit(td) {}
	void addChildren() {
		add(createTestClassInit<MyTestClass>("My Test class"));
	}
};