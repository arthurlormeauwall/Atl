#pragma once
#include "../template.h"
#include "UnitTestBuilder.h"
#include "TestTreeBuilder.h"

class TestClassBuilder : public TestTreeBuilder {
public:
	TestClassBuilder(string name);
	virtual void addUnitTests() = 0;
	void addChildren();
	void createUnitTest(string name, vector<Result>(*f)());
};

