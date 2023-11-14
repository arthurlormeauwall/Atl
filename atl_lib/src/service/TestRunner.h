#pragma once
#include "../model/TestData.h"

class TestRunner {
public:
	void run(TestData& tests);
	void runSomeTests(TestData& tests, vector<string> name);

private:
	void runChildrenTest(StackMap<TestData>* children);
	void updateResult(TestData& tests);
	bool areChildrenPassing(vector<TestData> children);
	bool areChildrenPassing(vector<Result> children);
	vector<Result> getChildrenResults(vector<TestData> children);
	void computeChildrenResult(TestData& tests);
};

