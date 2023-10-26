#pragma once
#include "../pch.h"

struct Path
{
	string moduleName;
	string testClassName;
	string unitTestName;
	Path() : moduleName("Undefined"), testClassName("Undefined"), unitTestName("Undefined") {}
	Path(string m, string t, string u) : moduleName(m), testClassName(t), unitTestName(u) {}
};

struct Result
{
	bool pass;
	string message;
	Result() : pass(false), message("Not executed yet") {}
	Result(bool p, string m) : pass(p), message(m) {}
};

struct UnitTestResult
{
	sharedptr<Result> result;
	vector<sharedptr<Result>> assertResult;
	Path path;
	UnitTestResult(vector<sharedptr<Result>> result, Path path) :
		assertResult(result), path(path) {}
	void setResult() {
		bool pass = true;
		string message;
		string beginingMessage;

		for (sharedptr<Result> result : assertResult) {
			if (!result->pass) {
				pass = false;
				message.append(result->message).append("\n");
			}
		}
		if (pass) {
			beginingMessage = "All is good \n";
		}
		else {
			beginingMessage = "There are test failures : \n";
			beginingMessage.append(message);
		}

		result = std::make_shared<Result>(pass, message);
	}
};

struct TestClassResult
{
	Result result;
	string name;
	testMap<sharedptr<UnitTestResult>> unitTestResults;
	TestClassResult(string name, testMap<sharedptr<UnitTestResult>> unitTestResults) :
		name(name), unitTestResults(unitTestResults) {}
	vector<sharedptr<UnitTestResult>> getAllUnitTestResults() {
		vector<sharedptr<UnitTestResult>> allResult;
		for (testMap<sharedptr<UnitTestResult>>::iterator it = unitTestResults.begin(); it != unitTestResults.end(); it++) {
			allResult.push_back(it->second);
		}
		return allResult;
	}
	void setResult() {
		bool pass = true;
		string message;
		string beginingMessage;

		for (sharedptr<UnitTestResult> utr : getAllUnitTestResults()) {
			sharedptr<Result> utResult = utr->result;
			if (!utResult->pass) {
				pass = false;
				message.append(utr->path.unitTestName).append(" : Failed");
			}
		}
		if (pass) {
			beginingMessage = "All is good \n";
		}
		else {
			beginingMessage = "There are test failures : \n";
			beginingMessage.append(message);
		}
		result = Result(pass, message);
	}
};

struct ModuleResult
{
	Result result;
	string name;
	testMap<TestClassResult> testClasses;
	ModuleResult(string name, testMap<TestClassResult> testClasses) :
		name(name), testClasses(testClasses) {}
	vector<TestClassResult> getAllUnitTestResults() {
		vector<TestClassResult> allResult;
		for (testMap<TestClassResult>::iterator it = testClasses.begin(); it != testClasses.end(); it++) {
			allResult.push_back(it->second);
		}
		return allResult;
	}
	void setResult() {
		bool pass = true;
		string message;
		string beginingMessage;

		for (TestClassResult utr : getAllUnitTestResults()) {
			Result utResult = utr.result;
			if (!utResult.pass) {
				pass = false;
				message.append(utr.name).append(" : Failed");
			}
		}
		if (pass) {
			beginingMessage = "All is good \n";
		}
		else {
			beginingMessage = "There are test failures : \n";
			beginingMessage.append(message);
		}
		result = Result(pass, message);
	}
};

struct AllTestResult
{
	Result result;
	testMap<ModuleResult> modules;
	vector<ModuleResult> getAllUnitTestResults() {
		vector<ModuleResult> allResult;
		for (testMap<ModuleResult>::iterator it = modules.begin(); it != modules.end(); it++) {
			allResult.push_back(it->second);
		}
		return allResult;
	}
	void setResult() {
		bool pass = true;
		string message;
		string beginingMessage;

		for (ModuleResult utr : getAllUnitTestResults()) {
			Result utResult = utr.result;
			if (!utResult.pass) {
				pass = false;
				message.append(utr.name).append(" : Failed");
			}
		}
		if (pass) {
			beginingMessage = "All is good \n";
		}
		else {
			beginingMessage = "There are test failures : \n";
			beginingMessage.append(message);
		}
		result = Result(pass, message);
	}
};


class TestResultContainer
{
	AllTestResult m_allTestResult;
	void setInterResult();
public:
	void addUnitTestResult(vector<sharedptr<UnitTestResult>>);
	sharedptr<AllTestResult> getAllTestResult();
};

