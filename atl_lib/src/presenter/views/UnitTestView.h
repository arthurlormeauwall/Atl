#pragma once
#include "../../model/Result.h"
#include "../../model/Path.h"
#include "../../model/TestInterface.h"

class UnitTestView {
public:
	Result result;
	Path path;
	vector<Result> childrenResult;
	UnitTestView(sharedptr<TestInterface> test) {
		result = test->getData().result;
		path = test->getData().path;
		childrenResult = test->getData().childrenResult.result;
	}
};
