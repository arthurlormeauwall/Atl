#pragma once
#include "../template.h"
#include "StackMap.h"
#include "Path.h"
#include "TestData.h"


class TestInterface  {
protected:
	TestData m_testData;
	StackMap<TestInterface> m_children;

public:
	TestInterface(TestData data) : m_testData(data) {}
	TestInterface(string moduleName) : m_testData(Path(moduleName)) {}
	TestInterface(string modulName, string testClassName) : m_testData(Path(modulName, testClassName)) {}
	TestInterface() {}

	virtual void init();
	virtual void run() ;
	virtual void addChildren();

	TestData getData();
	void add(sharedptr<TestInterface> t) ;

	void updateResult() ;
	bool areChildrenPassing() ;
	vector<Result> getChildrenResults() ;
	void computeChildrenResult() ;
	vector<sharedptr<TestInterface>> getAllChildren() ;
};

void initChildrenTest(vector<sharedptr<TestInterface>> children) ;
void runChildrenTest(vector<sharedptr<TestInterface>> children);




