#pragma once
#include "../../template.h"
#include "../../model/Model.h"

struct ResultView {
	bool pass;
	string message;
	ResultView(bool pass, string message) {
		this->pass = pass;
		this->message = message;
	}
};
