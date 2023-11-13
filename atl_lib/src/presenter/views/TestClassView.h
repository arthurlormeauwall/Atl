#pragma once
#include "../../template.h"
#include "../../model/Model.h"

class TestClassView {
public:
	Result result;
	string path;
	vector<TestData> children;
	TestClassView(const TestData& test) {
		result = test.result;
		path = test.path;
		children = test.children.getAllAsVector();
	}
};
