#pragma once
#include "atl_includes.h" 
#include "ALibTest.h"

class MyTests  : public AllTestBuilder {
public:
	MyTests() {}
	void addModules() override {
		createModule<ALibTest>("My Module");
	}
};
