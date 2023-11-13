#pragma once
#include "atl_includes.h"
#include "TestClassDeclarations.h"
#include <string>
#include <vector>

class AnotherModule : public ModuleBuilder {
public:

	AnotherModule(TestData td) : ModuleBuilder(td) {}
	void addChildren() {
		add(createTestClassBuilder<AnotherTestClass>("Another test class"));
		add(createTestClassBuilder<AThirdTestClass>("A third test class"));
	}
};
