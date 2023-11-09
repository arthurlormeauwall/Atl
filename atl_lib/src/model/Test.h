#pragma once
#include "../template.h"
#include "StackMap.h"
#include "Path.h"
#include "TestData.h"

class Test : public TestInterface {
protected:
	TestData m_testData;
	TestStackMap m_children;

	virtual void addChildren() = 0;
	void add(sharedptr<TestInterface> t) ;

	void updateResult() ;
	bool areChildrenPassing() ;
	vector<Result> getChildrenResults() ;
	void computeChildrenResult() ;
	vector<sharedptr<TestInterface>> getAllChildren() ;

public:
	Test(TestData data) : m_testData(data) {}
	Test(string moduleName) : m_testData(Path(moduleName)) {}
	Test(string modulName, string testClassName) : m_testData(Path(modulName, testClassName)) {}
	Test() {}

	void init();
	virtual void run() ;
	TestData getData();

};






