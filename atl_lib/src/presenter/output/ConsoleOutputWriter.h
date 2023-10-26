#pragma once
#include "../../pch.h"
#include "../output/OutputWriter.h"

class ConsoleOutputWriter : public OutputWriter
{
public: 
	void write(sharedptr<string> out);
};

