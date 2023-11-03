#pragma once
#include "../template.h"
#include "StackMap.h"
#include "Path.h"
#include "TestData.h"

class Test {
protected:
	TestData m_testData;
	StackMap<sharedptr<Test>> m_children;
public:
	Test(TestData data) : m_testData(data) {}
	Test(string moduleName) : m_testData(Path(moduleName)) {}
	Test(string modulName, string testClassName) : m_testData(Path(modulName, testClassName)) {}
	Test() {}
	void init();
	virtual void addChildren();
	virtual void run() ;
	virtual void updateResult() ;
	bool areChildrenPassing() ;

	vector<string> getChildrenMessage() ;

	void computeChildrenResult() ;

	void add(sharedptr<Test> t) ;

	sharedptr<Test> get(string name) ;

	vector<sharedptr<Test>> getAll() ;

	TestData getData();

	void runAll() ;
};










