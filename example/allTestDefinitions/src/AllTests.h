#pragma once
#include "atl_includes.h" 
#include "ALibTest.h"

class AllTests  : public AllTestBuilder {
public:
	AllTests() {}
	void addModules() override {
		createModule<ALibTest>("My Module");
	}
};
