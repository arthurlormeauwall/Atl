#pragma once
#include "../template.h"
#include "Test.h"
#include "Result.h"
#include "TestData.h"



class UnitTest : public Test {
	vector<Result> assertResults;
	vector<Result>(*unitTestRunnable)(Path);
public:
	UnitTest(TestData td, vector<Result>(*runnable)(Path)) : Test(td) {
		unitTestRunnable = runnable;
	}
	bool areChildrenPassing(vector<Result> assertResult) ;
	vector<string> getChildrenMessage(vector<Result> assertResult) ;
	void run() ;
	vector<Result> getAssertResults();
	void addChildren() {}
};
