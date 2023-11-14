#pragma once
#include "../../template.h"
#include "../../model/Model.h"


struct ModuleView {
	Result result;
	string name;
	vector<TestData> children;
	ModuleView(const TestData& test) {
		result = test.result;
		name = test.name;
		children = test.children.getAllAsVector();
	}
};