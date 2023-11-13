#pragma once
#include "../../template.h"
#include "../../model/Model.h"

class UnitTestView {
public:
	Result result;
	string path;
	vector<Result> childrenResult;
	UnitTestView(const TestData& test) {
		result = test.result;
		path = test.path;
		childrenResult = test.childrenResult.result;
	}
};
