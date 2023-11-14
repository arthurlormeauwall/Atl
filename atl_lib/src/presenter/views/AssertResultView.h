#pragma once
#include "../../template.h"
#include "../../model/Model.h"

struct AssertResultView {
	bool pass;
	string message;
	AssertResultView(Result result) {
		pass = result.pass;
		message = result.message;
	}
};
