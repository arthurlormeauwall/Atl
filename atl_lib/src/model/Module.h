#pragma once
#include "../template.h"
#include "Test.h"
#include "TestData.h"
#include "TestClass.h"
#include "Path.h"

class Module : public Test {
public:
	Module(TestData td) : Test(td) {}
	template<typename T>
	sharedptr<TestClass> createTestClass(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(Path(m_testData.path.moduleName, name)));
	}
};