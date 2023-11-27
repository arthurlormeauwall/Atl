#pragma once

#include "../template.h"

enum MessageTokenType {
	NAME,
	MESSAGE,
	ACTUAL,
	EXPECTED
};

struct Result {
	bool exist = true;
	bool executed;
	bool pass;
	map<MessageTokenType, string> messageTokens;
	Result() :
		executed(false),
		pass(false){}
	Result(bool p, map<MessageTokenType, string> m) :
		executed(true),
		pass(p),
		messageTokens(m) {}
	Result(const Result& result) {
		executed = result.executed;
		pass = result.pass;
		messageTokens = result.messageTokens;
	}
};

