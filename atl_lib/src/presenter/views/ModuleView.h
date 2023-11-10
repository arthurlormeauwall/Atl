#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "../../model/Initialisation/TestInit.h"

class ModuleInitView {
public:
	Result result;
	string path;
	vector<sharedptr<TestInit>> children;
	ModuleInitView(sharedptr<TestInit> test) {
	}
};