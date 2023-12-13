#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "TestClassView.h"

struct ModuleView {
	Result result;
	string name;
	vector<TestClassView> children;
	ModuleView(const TestData& test);
};


