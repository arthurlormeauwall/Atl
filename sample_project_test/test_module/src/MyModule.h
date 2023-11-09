#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

class MyModule : public Module {
public:

	MyModule(TestData td) : Module(td) {}
	void addChildren() {
		add(createTestClass<MyTestClass>("My Test class"));
	}
};