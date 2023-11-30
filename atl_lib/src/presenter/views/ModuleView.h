#pragma once
#include "../../template.h"
#include "../../model/Model.h"
#include "TestClassView.h"

struct ModuleView {
	Result result;
	string name;
	vector<TestClassView> children;
	ModuleView(const TestData& test) {
		result = test.result;
		name = test.name;
		for (auto testClassTestData : test.children.getAllAsVector()) {
			if(testClassTestData.result.executed)
				children.push_back(TestClassView(testClassTestData));
		}
	}
};

struct AllTestView {
	Result result;
	string name;
	vector<ModuleView> children;
	AllTestView(const TestData& test) {
		result = test.result;
		name = test.name;
		for (auto moduelTestData : test.children.getAllAsVector()) {
			if(moduelTestData.result.executed)
				children.push_back(ModuleView(moduelTestData));
		}
	}
};
