#pragma once
#include "../pch.h"
#include "../presenter/Presenter.h"
#include "../presenter/output/ConsoleOutputWriter.h"
#include "../model/TestContainer.h"
#include "../model/TestResultContainer.h"

class AtlService 
{
public:
	AtlService(): m_outputWriter(std::make_shared<ConsoleOutputWriter>()){}
	AtlService(std::shared_ptr<OutputWriter> outputWriter): m_outputWriter(outputWriter) {}

	void runAllTests();
	void addUnitTest(sharedptr<UnitTest> unitTest);
private:
	std::shared_ptr<OutputWriter> m_outputWriter;
	Presenter m_presenter;
	TestContainer m_allTest;
	TestResultContainer m_allTestResult;
	void runUnitTests(vector<std::shared_ptr<UnitTest>> unitTests);
	void write(); 
};