#pragma once
#include "../template.h"
#include "UnitTest.h"
#include "TestInterface.h"
#include "Path.h"
#include "TestData.h"

class TestClass : public TestInterface {
public:
	TestClass(TestData td) : TestInterface(td) {}
	sharedptr<UnitTest> createUnitTest(string name, vector<Result>(*f)()) {
		m_testData.hasChildren = true;
		return std::make_shared<UnitTest>(TestData(Path(m_testData.path.moduleName, m_testData.path.testClassName, name)), f);
	}
};

