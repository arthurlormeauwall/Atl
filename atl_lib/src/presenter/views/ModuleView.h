#pragma once
#include "../../template.h"
#include "../../model/Model.h"


class ModuleView {
public:
	Result result;
	string path;
	vector<TestData> children;
	ModuleView(const TestData& test) {
		result= test.result;
		path = test.path;
		children = test.children.getAllAsVector();
	}
};