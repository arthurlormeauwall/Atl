#pragma once
#include "../template.h"
#include "Test.h"
#include "Result.h"
#include "TestData.h"



class UnitTest : public Test
{
	vector<sharedptr<Result>> assertResults;
	vector<sharedptr<Result>>(*unitTestRunnable)(Path);
public:
	UnitTest(TestData td, vector<sharedptr<Result>>(*runnable)(Path)) : Test(td) {
		unitTestRunnable = runnable;
	}
	bool areChildrenPassing(vector<sharedptr<Result>> assertResult) ;
	vector<string> getChildrenMessage(vector<sharedptr<Result>> assertResult) ;
	void updateResult() ;
	void run() ;
	vector<sharedptr<Result>> getAssertResults();
};
