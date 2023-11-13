#pragma once
#include "../model/TestData.h"

class TestRunner {
	void runChildrenTest(StackMap<TestData>* children) {
		auto test = children->getAllAsVector();
		for (auto i = 0; i < test.size(); i++) {
			TestRunner runner;
			runner.run(test.at(i));
		}
	}

	void updateResult(TestData& tests) {
		if (!tests.childrenResult.pass) {
			tests.result.pass = false;
			tests.result.message = "Some tests failed";
		}
		else {
			tests.result.pass = true;
			tests.result.message = "Succeed";
		}
	}

	bool areChildrenPassing(vector<TestData> children) {
		for (TestData t : children) {
			if (!t.result.pass) {
				return false;
			}
		}
		return true;
	}

	bool areChildrenPassing(vector<Result> children) {
		for (Result t : children) {
			if (!t.pass) {
				return false;
			}
		}
		return true;
	}

	vector<Result> getChildrenResults(vector<TestData> children) {
		vector<Result> results;
		for (TestData t : children) {
			results.push_back(Result(t.result));
		}
		return results;
	}

	void computeChildrenResult(TestData& tests) {
		tests.childrenResult = ChildrenResult(
			areChildrenPassing(tests.children.getAllAsVector()),
			getChildrenResults(tests.children.getAllAsVector())
		);
	}

public:
	void run(TestData& tests) {
		if (tests.hasChildren) {
			tests.children.doForEach(
				[](TestData* data) {
					TestRunner runner;
					runner.run(*data);
				}
			);
			computeChildrenResult(tests);
		}
		else {
			tests.childrenResult.result = tests.runner();
			tests.childrenResult.pass = areChildrenPassing(tests.childrenResult.result);
		}
		updateResult(tests);
	}
};

