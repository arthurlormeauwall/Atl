#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "UnitTestView.h"

struct TestClassView {
	Result result;
	string name;
	vector<UnitTestView> children;
	TestClassView(const TestData& test);
};
