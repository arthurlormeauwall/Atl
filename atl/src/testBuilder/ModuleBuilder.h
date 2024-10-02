#pragma once
#include "../template.h"
#include "TestTreeBuilder.h"
#include "TestClassBuilder.h"
#include "../model/Model.h"

class ModuleBuilder : public TestTreeBuilder {
public:
	ModuleBuilder(string name) : TestTreeBuilder(name) {}
	void addChildren() override {
		addTestClasses();
	}
	virtual void addTestClasses() = 0;
	template<typename T>
	void createTestClass(string name) {
		m_testData.hasChildren = true;
		add(std::make_shared<T>(name));
	}
};