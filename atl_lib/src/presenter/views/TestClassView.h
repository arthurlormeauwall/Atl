#pragma once
#include "../../template.h"
#include "../../model/StackMap.h"

class TestClassView {
public:
	Result result;
	Path path;
	vector<sharedptr<TestInterface>> children;
	TestClassView(sharedptr<TestInterface> test) {
		result = test->getData().result;
		path = test->getData().path;
		children = test->getAllChildren();

	}
};
