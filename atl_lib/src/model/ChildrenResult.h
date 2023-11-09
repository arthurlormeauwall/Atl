#pragma once
#include "../template.h"
#include "Result.h"

struct ChildrenResult
{
	bool pass;
	vector<Result> result;
	ChildrenResult() : pass(false), result(vector<Result> {Result()}) {}
	ChildrenResult(bool p, Result result) : pass(p), result(vector<Result> {result}) {}
	ChildrenResult(bool p, vector<Result> results) : pass(p), result(results) {}
};
