#pragma once
#include "../../template.h"
#include <iostream> 
#include "../output/OutputWriter.h"
#include "ConsolePresenter.h"

class ConsoleOutputWriter : public OutputWriter{
	ConsoleAllTestPresenter m_presenter;
public: 
	ConsoleOutputWriter(bool ansiColorEnabled) : m_presenter(ConsoleAllTestPresenter(ansiColorEnabled))
	{}

	void write(const TestData& allTests);
};

