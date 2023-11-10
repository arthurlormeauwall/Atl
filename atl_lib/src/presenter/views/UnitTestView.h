#pragma once
#include "../../model/Result.h"
#include "../../model/Initialisation/TestInit.h"

class UnitTestInitView {
public:
	Result result;
	string path;
	vector<Result> childrenResult;
	UnitTestInitView(sharedptr<TestInit> test) {
		}
};
