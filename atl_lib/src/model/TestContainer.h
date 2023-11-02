#pragma once
#include "TestResultContainer.h"

class TestData {
public:
	Result result;
	ChildrenResult childrenResult;
	Path path;
	bool hasChildren, hasParent;
	TestData(Path p) : childrenResult(ChildrenResult()), result(Result()), hasChildren(false), hasParent(true) {
		path = p;
	}
	TestData() : childrenResult(ChildrenResult()), result(Result()), hasChildren(true), hasParent(false) {}
};


