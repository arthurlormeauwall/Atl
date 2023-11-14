#pragma once

#include "../template.h"

struct Result {
	bool executed;
	bool pass;
	string message;
	Result() :
		executed(false),
		pass(false),
		message("Not executed yet") {}
	Result(bool p, string m) :
		executed(true),
		pass(p),
		message(m) {}
	Result(const Result& result) {
		executed = result.executed;
		pass = result.pass;
		message = result.message;
	}
};

