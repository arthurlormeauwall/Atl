#pragma once
#include "../template.h"
#include "TestInterface.h"
#include "TestData.h"
#include "TestClass.h"
#include "Path.h"

class Module : public TestInterface {
public:
	Module(TestData td) : TestInterface(td) {}
	template<typename T>
	sharedptr<TestClass> createTestClass(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(Path(m_testData.path.moduleName, name)));
	}
};