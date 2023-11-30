#pragma once
#include "../../template.h"
#include "../../model/Model.h"

struct ResultView {
	bool pass;
	vector<string> messages;
	ResultView(bool pass, vector<string> messages) {
		this->pass = pass;
		this->messages = messages;
	}
};
