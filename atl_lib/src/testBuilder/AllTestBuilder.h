#pragma once
#include "../model/Model.h"
#include "TestTreeBuilder.h"
#include "ModuleBuilder.h"

class AllTestBuilder : public TestTreeBuilder{
public:
	AllTestBuilder() {}
	template<typename T>
	sharedptr<ModuleBuilder> createModuleBuilder(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(name)); 
	}
};
