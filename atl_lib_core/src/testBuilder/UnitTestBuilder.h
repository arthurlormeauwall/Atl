#pragma once
#include "../template.h"
#include "TestTreeBuilder.h"
#include "../model/Model.h"


class UnitTestBuilder : public TestTreeBuilder {
public:
	UnitTestBuilder(string name, vector<Result>(*runner)()) : TestTreeBuilder(name) {
		m_testData.runner = runner;
	}
	virtual void addChildren() {}
};
