#pragma once
#include "../pch.h"

struct Path
{
	string moduleName;
	string testClassName;
	string unitTestName;
	Path() : moduleName("Undefined"), testClassName("Undefined"), unitTestName("Undefined") {}
	Path(string m, string t, string u) : moduleName(m), testClassName(t), unitTestName(u) {}
	Path (string m) : moduleName(m), testClassName("Undefined"), unitTestName("Undefined"){}
	Path (string m, string t) : moduleName(m), testClassName(t), unitTestName("Undefined"){}
};

struct Result
{
	bool pass;
	string message;
	Result() : pass(false), message("Not executed yet") {}
	Result(bool p, string m) : pass(p), message(m) {}
};

struct ChildrenResult
{
	bool pass;
	vector<string> message;
	ChildrenResult() : pass(false), message(vector<string> {"Not executed yet"}) {}
	ChildrenResult(bool p, string m) : pass(p), message(vector<string> {m}) {}
	ChildrenResult(bool p, vector<string> m) : pass(p), message(m) {}
};




//struct TestResult {
//	Result result;
//	string name;
//	TestResult(string n) : name(n) {}
//	TestResult(string n, Result r) : name(n), result(r) {}
//	TestResult() {}
//};
//Result getChildrenResult(vector<TestResult> testResult);
//
//struct UnitTestResult
//{
//	sharedptr<Result> result;
//	vector<sharedptr<Result>> assertResult;
//	Path path;
//	UnitTestResult(vector<sharedptr<Result>> result, Path path) :
//		assertResult(result), path(path) {}
//	vector<TestResult> getAllUnitTestResults() {
//		vector<TestResult> allResult;
//		for (vector<sharedptr<Result>>::iterator it = assertResult.begin(); it != assertResult.end(); it++) {
//			allResult.push_back(TestResult(path.unitTestName, (**it)));
//		}
//		return allResult;
//	}
//	void setResult() {
//		Result test =  getChildrenResult(getAllUnitTestResults());
//		result = std::make_shared<Result>(test.pass, test.message);
//	}
//};

//struct TestClassResult
//{
//	TestResult testResult;
//	string name;
//	testMap<sharedptr<UnitTestResult>> unitTestResults;
//	TestClassResult(string name, testMap<sharedptr<UnitTestResult>> unitTestResults) :
//		name(name), unitTestResults(unitTestResults) {}
//	vector<TestResult> getAllUnitTestResults() {
//		vector<TestResult> allResult;
//		for (testMap<sharedptr<UnitTestResult>>::iterator it = unitTestResults.begin(); it != unitTestResults.end(); it++) {
//			allResult.push_back(TestResult(name, *it->second->result));
//		}
//		return allResult;
//	}
//	void setResult() {
//		testResult.result = getChildrenResult(getAllUnitTestResults());
//	}
//};
//
//struct ModuleResult
//{
//	TestResult testResult;
//	testMap<TestClassResult> testClasses;
//	ModuleResult(string name, testMap<TestClassResult> testClasses) :
//		testClasses(testClasses) {
//		testResult = TestResult(name);
//	}
//	vector<TestResult> getAllUnitTestResults() {
//		vector<TestResult> allResult;
//		for (testMap<TestClassResult>::iterator it = testClasses.begin(); it != testClasses.end(); it++) {
//			allResult.push_back(it->second.testResult);
//		}
//		return allResult;
//	}
//	void setResult() {
//		testResult.result = getChildrenResult(getAllUnitTestResults());
//	}
//};
//
//
//struct AllTestResult
//{
//	Result result;
//	testMap<ModuleResult> modules;
//	vector<TestResult> getAllUnitTestResults() {
//		vector<TestResult> allResult;
//		for (testMap<ModuleResult>::iterator it = modules.begin(); it != modules.end(); it++) {
//			allResult.push_back(it->second.testResult);
//		}
//		return allResult;
//	}
//	void setResult() {
//		result = getChildrenResult(getAllUnitTestResults());
//	}
//};

