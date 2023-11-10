#pragma once
#include "../../template.h"
#include "TestInit.h"
#include "../Result.h"
#include "../TestData.h"



class UnitTestInit : public TestInit {
public:
	UnitTestInit(TestData td, vector<Result>(*runner)()) : TestInit(td) {
		m_testData.runner = runner;
	}
	void addChildren() {}
};
