#pragma once
#include "atl_includes.h"


class ItemTest: public TestClassBuilder {
public:
	ItemTest(string name) : TestClassBuilder(name) {}
	virtual void addUnitTests() override;
};