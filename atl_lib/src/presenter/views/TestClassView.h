#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "../../model/Initialisation/TestInit.h"

class TestClassInitView {
public:
	Result result;
	string path;
	vector<sharedptr<TestInit>> children;
	TestClassInitView(sharedptr<TestInit> test) {

	}
};
