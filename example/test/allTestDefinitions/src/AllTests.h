#pragma once
#include "atl_includes.h" 
#include "someLibTest.h"

class AllTests  : public AllTestBuilder {
public:
	AllTests() {}
	void addModules() override {
		createModule<SomeLibTest>("SomeLib test");
	}
};
