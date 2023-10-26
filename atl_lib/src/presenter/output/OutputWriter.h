#pragma once
#include "../../pch.h"

class OutputWriter
{
public: 
	virtual void write(sharedptr<string> output) = 0;
};

