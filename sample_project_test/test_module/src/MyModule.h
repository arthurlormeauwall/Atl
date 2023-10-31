#pragma once
#include "atl_includes.h"
#include "MyTestClass.h"
#include <string>
#include <memory>
#include <vector>

class MyModule : public Module {
public:
	MyModule(const string& n) : Module(n) {}
	void addTestClasses() {
		addTestClass(std::make_shared<MyTestClass>("My test class"));
	}
};