#include "TestRunner.h"

void TestRunner::runChildrenTest(StackMap<TestData>* children) {
	auto test = children->getAllAsVector();
	for (auto i = 0; i < test.size(); i++) {
		TestRunner runner;
		runner.run(test.at(i));
	}
}

void TestRunner::updateResult(TestData& tests) {
	if (!tests.childrenResult.pass) {
		tests.result.executed = true;
		tests.result.pass = false;
		tests.result.message = "Some tests failed";
	}
	else {
		tests.result.executed = true;
		tests.result.pass = true;
		tests.result.message = "Succeed";
	}
}

bool TestRunner::areChildrenPassing(vector<TestData> children) {
	for (TestData t : children) {
		if (!t.result.pass) {
			return false;
		}
	}
	return true;
}

bool TestRunner::areChildrenPassing(vector<Result> children) {
	for (Result t : children) {
		if (!t.pass) {
			return false;
		}
	}
	return true;
}

vector<Result> TestRunner::getChildrenResults(vector<TestData> children) {
	vector<Result> results;
	for (TestData t : children) {
		results.push_back(Result(t.result));
	}
	return results;
}

void TestRunner::computeChildrenResult(TestData& tests) {
	tests.childrenResult = ChildrenResult(
		areChildrenPassing(tests.children.getAllAsVector()),
		getChildrenResults(tests.children.getAllAsVector())
	);
}

void TestRunner::run(TestData& tests) {
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

void TestRunner::runSomeTests(TestData& tests, vector<string> name) {
	if (tests.hasChildren == true) {
		TestData* targetedTest = tests.children.getByOrder(tests.children.getByName(name[0]));
		TestRunner runner;
		if (name.size() > 1) {
			vector<string> newPath;
			for (int i = 0; i < name.size() - 1; i++) {
				newPath.push_back(name.at(i + 1));
			}
			runner.runSomeTests(*targetedTest, newPath);
		}
		else {
			runner.run(*targetedTest);
		}
		computeChildrenResult(tests);
	}
	else {
		tests.childrenResult.result = tests.runner();
		tests.childrenResult.pass = areChildrenPassing(tests.childrenResult.result);
	}
	updateResult(tests);
}