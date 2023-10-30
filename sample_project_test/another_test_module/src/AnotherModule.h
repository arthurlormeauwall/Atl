#pragma once
#include "atl_includes.h"
#include "TestClassDeclarations.h"
#include <string>
#include <vector>

class AnotherModule : public Module {
public:
	AnotherModule(const string& n) : Module(n) {}
	void addTestClasses() {
		addTestClass(std::make_shared<AnotherTestClass>("Another test class"));
		addTestClass(std::make_shared<AThirdTestClass>("A third test class"));
	}
};
