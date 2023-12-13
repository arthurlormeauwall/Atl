#pragma once
#include "../../model/Model.h"
#include "ModuleView.h"

struct AllTestView {
	Result result;
	string name;
	vector<ModuleView> children;
	AllTestView(const TestData& test);
};
