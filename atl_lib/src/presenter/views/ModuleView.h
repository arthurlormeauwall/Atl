#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "../../model/Initialisation/TestInit.h"

class ModuleView {
public:
	Result result;
	string path;
	vector<sharedptr<TestData>> children;
	ModuleView(sharedptr<TestData> test) {
	}
};