#pragma once
#include "../../template.h"
#include "../../model/Model.h"

struct ResultView {
	bool pass;
	string message;
	ResultView(Result result) {
		pass = result.pass;
		message = result.message;
	}
};
