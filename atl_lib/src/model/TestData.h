#pragma once
#include "../template.h"
#include "ChildrenResult.h"
#include "StackMap.h"
#include "Result.h"

class TestData {
public:
	string path;
	StackMap<TestData> children;
	vector<Result> (*runner)();
	Result result;
	ChildrenResult childrenResult;
	bool hasChildren, hasParent;
	TestData(string p) : childrenResult(ChildrenResult()), result(Result()), hasChildren(false), hasParent(true) {
		path = p;
	}
	TestData() : childrenResult(ChildrenResult()), result(Result()), hasChildren(true), hasParent(false) {}
	TestData(const TestData& td) {
		path = td.path;
		children = td.children;
		runner = td.runner;
		result = td.result;
		childrenResult = td.childrenResult;
		hasChildren = td.hasChildren;
		hasParent = td.hasParent;
	}
};


