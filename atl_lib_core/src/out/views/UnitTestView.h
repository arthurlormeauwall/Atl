#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "ResultView.h"

struct UnitTestView {
	Result result;
	string name;
	vector<ResultView> children;
	UnitTestView(const TestData& test);
};
