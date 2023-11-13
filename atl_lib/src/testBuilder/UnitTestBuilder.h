#pragma once
#include "../template.h"
#include "TestTreeBuilder.h"
#include "../model/Model.h"


class UnitTestBuilder : public TestTreeBuilder {
public:
	UnitTestBuilder(TestData td, vector<Result>(*runner)()) : TestTreeBuilder(td) {
		m_testData.runner = runner;
	}
	virtual void addChildren() {}
};
