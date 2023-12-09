#pragma once
#include "../../template.h"
#include "../views/Views.h"

class OutputWriter{
public: 
	virtual void write(const TestData& allTests) = 0;
};

