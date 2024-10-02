#pragma once
#include "../model/Model.h"
#include "TestTreeBuilder.h"
#include "ModuleBuilder.h"

class AllTestBuilder : public TestTreeBuilder{
public:
	AllTestBuilder() {}
	virtual void addModules()=0;
	void addChildren() override {
		addModules();
	}
	template<typename T>
	void createModule(string name) {
		m_testData.hasChildren = true;
		add(std::make_shared<T>(name)); 
	}
};
