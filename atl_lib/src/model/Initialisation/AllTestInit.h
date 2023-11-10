#pragma once
#include "../../template.h"
#include "TestInit.h"
#include "../TestData.h"
#include "ModuleInit.h"

class AllTestInit : public TestInit{
public:
	AllTestInit() {}
	template<typename T>
	sharedptr<ModuleInit> createModuleInit(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(name)); 
	}
};
