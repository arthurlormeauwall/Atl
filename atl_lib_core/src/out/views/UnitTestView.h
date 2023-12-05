#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "ResultView.h"

struct UnitTestView {
	Result result;
	string name;
	vector<ResultView> children;
	UnitTestView(const TestData& test) {
		result = test.result;
		name = test.name;
		for (auto assertResult : test.childrenResult.result) {
			if(assertResult.executed)
				children.push_back(ResultView(assertResult.pass, assertResult.messages));
		}
	}
};
