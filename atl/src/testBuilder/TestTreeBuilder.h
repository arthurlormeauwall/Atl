#pragma once
#include "../template.h"
#include "../model/Model.h"


class TestTreeBuilder {
protected:
	TestData m_testData;
	StackMap<sharedptr<TestTreeBuilder>> m_children;

public:
	TestTreeBuilder(string name) : m_testData(name) {}
	TestTreeBuilder() {}

	virtual sharedptr<TestData> init();
	virtual void addChildren();
	void initChildrenTest(vector<sharedptr<TestTreeBuilder>> children);
	void add(sharedptr<TestTreeBuilder> t);
};





