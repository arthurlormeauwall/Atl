#pragma once
#include "../pch.h"
#include "TestResultContainer.h"
#include "TestContainer.h"


//struct UnitTestMinimalData { string name;
//	vector<sharedptr<Result>>(*unitTestRunnable)(Path);
//	UnitTestMinimalData(string n, vector<sharedptr<Result>>(*f)(Path)) : name(n), unitTestRunnable(f) {}
//};


class Test {
protected:
	TestData testData;
	TestInMemoryRepository<sharedptr<Test>> children;
public:
	Test(TestData data) : testData(data) {}
	Test(string moduleName) : testData(Path(moduleName)) {}
	Test(string modulName, string testClassName) : testData(Path(modulName, testClassName)) {}
	Test() {}
	void init() {
		addChildren();
		children.init();
	}
	virtual void addChildren() {};
	virtual void run() {
		if (testData.hasChildren) {
			children.run();
			computeChildrenResult();
		}
		updateResult();
	}
	virtual void updateResult() {
		if (!testData.childrenResult.pass) {
			testData.result.pass = false;
			testData.result.message ="Some tests failed";
		}
		else {
			testData.result.pass = true;
			testData.result.message = "Succeed";
		}
	}
	bool areChildrenPassing() {
		for (sharedptr<Test> t : children.getAllAsVector()) {
			if (!t->getData().result.pass) {
				return false;
			}
		}
		return true;
	}

	vector<string> getChildrenMessage() {
		vector<string> messages;
		for (sharedptr<Test> t : children.getAllAsVector()) {
			messages.push_back(t->getData().result.message);
		}
		return messages;
	}

	void computeChildrenResult() {
		testData.childrenResult.pass = areChildrenPassing();
		testData.childrenResult.message = getChildrenMessage();
	}

	void add(sharedptr<Test> t) {
		children.add(t);
	}

	sharedptr<Test> get(string name) {
		return children.getByOrder(children.getByName(name));
	}

	vector<sharedptr<Test>> getAll() {
		return children.getAllAsVector();
	}

	TestData getData() {
		return testData;
	}

	void runAll() {
		run();
		children.run();
	}
};

class UnitTest : public Test
{
	vector<sharedptr<Result>> assertResults;
	vector<sharedptr<Result>>(*unitTestRunnable)(Path);
public:
	UnitTest(TestData td, vector<sharedptr<Result>>(*runnable)(Path)) : Test(td) {
		unitTestRunnable = runnable;
	}
	bool areChildrenPassing(vector<sharedptr<Result>> assertResult) {
		for (sharedptr<Result> t : assertResult) {
			if (!t->pass) {
				return false;
			}
		}
		return true;
	}

	vector<string> getChildrenMessage(vector<sharedptr<Result>> assertResult) {
		vector<string> messages;
		for (sharedptr<Result> t : assertResult) {
			messages.push_back(t->message);
		}
		return messages;
	}
	void updateResult() {
		if (!testData.childrenResult.pass) {
			testData.result.pass = false;
			testData.result.message = "Some assertions failed";
		}
		else {
			testData.result.pass = true;
			testData.result.message = "UnitTest Succeed";
		}
	}
	void run() {
		assertResults = unitTestRunnable(Path(testData.path.moduleName, testData.path.testClassName, testData.path.unitTestName));
		testData.childrenResult.pass = areChildrenPassing(assertResults);
		testData.childrenResult.message = getChildrenMessage(assertResults);
		updateResult();
	}

	vector<sharedptr<Result>> getAssertResults() {
		return assertResults;
	}
};
class TestClass : public Test {
public:
	TestClass(TestData td) : Test(td) {}
	sharedptr<UnitTest> createUnitTest(string name, vector<sharedptr<Result>>(*f)(Path)) {
		testData.hasChildren = true;
		return std::make_shared<UnitTest>(TestData(Path(testData.path.moduleName, testData.path.testClassName, name)), f);
	}
};

class Module : public Test {
public:
	Module(TestData td) : Test(td) {}
	template<typename T>
	sharedptr<TestClass> createTestClass(string name) {
		testData.hasChildren = true;
		return std::make_shared<T>(TestData(Path(testData.path.moduleName, name)));
	}
};

class AllTest : public Test {
public:
	AllTest() {}
	template<typename T>
	sharedptr<T> createModule(string name) {
		testData.hasChildren = true;
		return std::make_shared<T>(TestData(Path(name)));
	}

};




