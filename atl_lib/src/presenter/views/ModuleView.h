#pragma once
#include "../../template.h"
#include "../../model/StackMap.h"

class ModuleView {
public:
	Result result;
	Path path;
	vector<sharedptr<TestInterface>> children;
	ModuleView(sharedptr<TestInterface> test) {
		result = test->getData().result;
		path = test->getData().path;
		children = test->getAllChildren();
	}
};