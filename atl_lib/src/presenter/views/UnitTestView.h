#pragma once
#include "../../template.h"
#include "../../model/Model.h"

struct UnitTestView {
	Result result;
	string name;
	vector<Result> childrenResult;
	UnitTestView(const TestData& test) {
		result = test.result;
		name = test.name;
		childrenResult = test.childrenResult.result;
	}
};
