#pragma once
#include "../model/TestData.h"

class TestRunner {
	void runChildrenTest(vector<sharedptr<TestData>> children) {
		for (sharedptr<TestData> t : children) {
			TestRunner runner;
			runner.run(t);
		}
	}

	void updateResult(sharedptr<TestData> tests) {
		if (!tests->childrenResult.pass) {
			tests->result.pass = false;
			tests->result.message = "Some tests failed";
		}
		else {
			tests->result.pass = true;
			tests->result.message = "Succeed";
		}
	}

	bool areChildrenPassing(vector<sharedptr<Result>> children) {
		for (sharedptr<Result> t : children) {
			if (!t->pass) {
				return false;
			}
		}
		return true;
	}

	bool areChildrenPassing1(vector<sharedptr<TestData>> children) {
		for (sharedptr<TestData> t : children) {
			if (!t->result.pass) {
				return false;
			}
		}
		return true;
	}

	bool areChildrenPassing3(vector<Result> children) {
		for (Result t : children) {
			if (!t.pass) {
				return false;
			}
		}
		return true;
	}

	vector<Result> getChildrenResults(vector<sharedptr<TestData>> children) {
		vector<Result> results;
		for (sharedptr<TestData> t : children) {
			results.push_back(Result(t->result));
		}
		return results;
	}

	void computeChildrenResult(sharedptr<TestData> tests) {
		tests->childrenResult = ChildrenResult(
			areChildrenPassing1(tests->children.getAllAsVector()),
			getChildrenResults(tests->children.getAllAsVector())
		);
	}

public:
	sharedptr<TestData> run(sharedptr<TestData> tests) {
		if (tests->hasChildren) {
			runChildrenTest(tests->children.getAllAsVector());
			computeChildrenResult(tests);
		}
		else {
			tests->childrenResult.result = tests->runner();
			bool test = areChildrenPassing3(tests->childrenResult.result);
			tests->childrenResult.pass = test;
		}
		updateResult(tests);
		return tests;
	}
};
