#pragma once

#include "../template.h"

struct Result {
	bool exist = true;
	bool executed;
	bool pass;
	vector<string> messages;
	Result() :
		executed(false),
		pass(false) {}

	Result(bool p, vector<string> msgs) :
		executed(true),
		pass(p),
		messages(msgs) {}

	Result(const Result& result) {
		executed = result.executed;
		pass = result.pass;
		messages = result.messages;
	}
};

