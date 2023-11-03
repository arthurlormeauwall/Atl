#pragma once
#include "../../template.h"

class OutputWriter{
public: 
	virtual void write(sharedptr<string> output) = 0;
};

