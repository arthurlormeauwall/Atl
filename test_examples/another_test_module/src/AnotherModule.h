#pragma once
#include "atl_includes.h"
#include "TestClassDeclarations.h"
#include <string>
#include <vector>

class AnotherModule : public ModuleBuilder {
public:

	AnotherModule(string name) : ModuleBuilder(name) {}
	void addTestClasses() {
		createTestClass<AnotherTestClass>("Another test class");
		createTestClass<AThirdTestClass>("A third test class");
	}
};
