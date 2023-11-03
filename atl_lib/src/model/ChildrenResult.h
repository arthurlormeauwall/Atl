#pragma once
#include "../template.h"

struct ChildrenResult
{
	bool pass;
	vector<string> message;
	ChildrenResult() : pass(false), message(vector<string> {"Not executed yet"}) {}
	ChildrenResult(bool p, string m) : pass(p), message(vector<string> {m}) {}
	ChildrenResult(bool p, vector<string> m) : pass(p), message(m) {}
};
