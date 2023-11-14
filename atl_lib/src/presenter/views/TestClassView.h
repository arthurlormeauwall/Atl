#pragma once
#include "../../template.h"
#include "../../model/Model.h"

class TestClassView {
public:
	Result result;
	string name;
	vector<TestData> children;
	TestClassView(const TestData& test) {
		result = test.result;
		name = test.name;
		children = test.children.getAllAsVector();
	}
};
