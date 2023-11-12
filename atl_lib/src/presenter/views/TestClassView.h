#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "../../model/Initialisation/TestInit.h"

class TestClassView {
public:
	Result result;
	string path;
	vector<sharedptr<TestData>> children;
	TestClassView(sharedptr<TestData> test) {

	}
};
