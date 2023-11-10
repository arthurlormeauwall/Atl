#pragma once
#include "../template.h"
#include "TestInterface.h"
#include "Result.h"
#include "TestData.h"



class UnitTest : public TestInterface {
	vector<Result> assertResults;
	vector<Result>(*unitTestRunnable)();
public:
	UnitTest(TestData td, vector<Result>(*runnable)()) : TestInterface(td) {
		unitTestRunnable = runnable;
	}
	bool areChildrenPassing(vector<Result> assertResult) ;
	vector<string> getChildrenMessage(vector<Result> assertResult) ;
	void run() ;
	vector<Result> getAssertResults();
	void addChildren() {}
};