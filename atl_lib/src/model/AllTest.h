#pragma once
#include "../template.h"
#include "TestInterface.h"
#include "TestData.h"
#include "Path.h"
#include "Module.h"

class AllTest : public TestInterface{
public:
	AllTest() {}
	template<typename T>
	sharedptr<Module> createModule(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(Path(name))); 
	}
};
