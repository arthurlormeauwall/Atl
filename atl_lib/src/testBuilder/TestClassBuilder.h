#pragma once
#include "../template.h"
#include "UnitTestBuilder.h"
#include "TestTreeBuilder.h"

class TestClassBuilder : public TestTreeBuilder {
public:
	TestClassBuilder(TestData td) : TestTreeBuilder(td) {}
	virtual void addUnitTests()=0;
	void addChildren() {
		addUnitTests();
	}
	void createUnitTest(string name, vector<Result>(*f)()) {
		m_testData.hasChildren = true;
		add(std::make_shared<UnitTestBuilder>(TestData(name), f));
	}
};

