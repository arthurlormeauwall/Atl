#pragma once
#include "../template.h"
#include "ChildrenResult.h"
#include "Path.h"
#include "Result.h"

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


