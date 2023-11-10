#pragma once
#include "../../template.h"
#include "TestInit.h"
#include "../TestData.h"
#include "TestClassInit.h"

class ModuleInit : public TestInit {
public:
	ModuleInit(TestData td) : TestInit(td) {}
	template<typename T>
	sharedptr<TestClassInit> createTestClassInit(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(name));
	}
};