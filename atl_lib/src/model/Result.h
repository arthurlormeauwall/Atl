#pragma once

#include "../template.h"

struct Result {
	bool pass;
	string message;
	Result() :
		pass(false),
		message("Not executed yet") {}
	Result(bool p, string m) :
		pass(p),
		message(m) {}
	Result(const Result& result) {
		pass = result.pass;
		message = result.message;
	}
};

