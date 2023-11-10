#pragma once
#include "../../template.h"
#include "../StackMap.h"
#include "../TestData.h"


class TestInit {
protected:
	TestData m_testData;
	StackMap<TestInit> m_children;

public:
	TestInit(TestData data) : m_testData(data) {}
	TestInit(string name) : m_testData(name) {}
	TestInit() {}

	virtual sharedptr<TestData> init();
	virtual void addChildren();
	void initChildrenTest(vector<sharedptr<TestInit>> children);
	void add(sharedptr<TestInit> t);
};





