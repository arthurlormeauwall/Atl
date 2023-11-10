#pragma once
#include "../../template.h"
#include "UnitTestInit.h"
#include "TestInit.h"
#include "../TestData.h"

class TestClassInit: public TestInit {
public:
	TestClassInit(TestData td) : TestInit(td) {}
	sharedptr<UnitTestInit> createUnitTestInit(string name, vector<Result>(*f)()) {
		m_testData.hasChildren = true;
		return std::make_shared<UnitTestInit>(TestData(name), f);
	}
};

