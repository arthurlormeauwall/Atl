#pragma once
#include "../template.h"
#include "UnitTestBuilder.h"
#include "TestTreeBuilder.h"

class TestClassBuilder : public TestTreeBuilder {
public:
	TestClassBuilder(TestData td) : TestTreeBuilder(td) {}
	sharedptr<UnitTestBuilder> createUnitTestBuilder(string name, vector<Result>(*f)()) {
		m_testData.hasChildren = true;
		return std::make_shared<UnitTestBuilder>(TestData(name), f);
	}
};

