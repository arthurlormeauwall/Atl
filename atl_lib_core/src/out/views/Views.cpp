#include "Views.h"

AllTestView::AllTestView(const TestData& test) {
	result = test.result;
	name = test.name;
	for (auto moduelTestData : test.children.getAllAsVector()) {
		if (moduelTestData.result.executed)
			children.push_back(ModuleView(moduelTestData));
	}
}

ModuleView::ModuleView(const TestData& test) {
	result = test.result;
	name = test.name;
	for (auto testClassTestData : test.children.getAllAsVector()) {
		if (testClassTestData.result.executed)
			children.push_back(TestClassView(testClassTestData));
	}
}

TestClassView::TestClassView(const TestData& test) {
	result = test.result;
	name = test.name;
	for (auto unitTestTestData : test.children.getAllAsVector()) {
		if (unitTestTestData.result.executed)
			children.push_back(UnitTestView(unitTestTestData));
	}
}
UnitTestView::UnitTestView(const TestData& test) {
		result = test.result;
		name = test.name;
		for (auto assertResult : test.childrenResult.result) {
			if(assertResult.executed)
				children.push_back(ResultView(assertResult.pass, assertResult.messages));
		}
	}