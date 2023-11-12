#pragma once
#include "../../model/Result.h"
#include "../../model/Initialisation/TestInit.h"

class UnitTestView {
public:
	Result result;
	string path;
	vector<Result> childrenResult;
	UnitTestView(sharedptr<TestData> test) {
		}
};
