#pragma once
#include "../template.h"
#include "TestTreeBuilder.h"
#include "TestClassBuilder.h"
#include "../model/Model.h"

class ModuleBuilder : public TestTreeBuilder {
public:
	ModuleBuilder(TestData td) : TestTreeBuilder(td) {}
	template<typename T>
	sharedptr<TestClassBuilder> createTestClassBuilder(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(name));
	}
};