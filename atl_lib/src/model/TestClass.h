#pragma once
#include "../template.h"
#include "UnitTest.h"
#include "Test.h"
#include "Path.h"
#include "TestData.h"

class TestClass : public Test {
public:
	TestClass(TestData td) : Test(td) {}
	sharedptr<UnitTest> createUnitTest(string name, vector<Result>(*f)(Path)) {
		m_testData.hasChildren = true;
		return std::make_shared<UnitTest>(TestData(Path(m_testData.path.moduleName, m_testData.path.testClassName, name)), f);
	}
};

