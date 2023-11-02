#pragma once
#include "../pch.h"
#include "../presenter/Presenter.h"
#include "../presenter/output/ConsoleOutputWriter.h"
#include "../model/TestContainer.h"
#include "../model/TestResultContainer.h"
#include "../model/AllTests.h"
#include "ResultService.h"

class AtlService 
{
public:
	AtlService(): m_outputWriter(std::make_shared<ConsoleOutputWriter>()){}
	AtlService(std::shared_ptr<OutputWriter> outputWriter): m_outputWriter(outputWriter) {}
	void runAllTests(sharedptr<AllTest> allTests);

private:
	ResultService m_resultService;
	std::shared_ptr<OutputWriter> m_outputWriter;
	Presenter m_presenter;
	//sharedptr<AllTestResult> m_allTestResult;
	void write(sharedptr<AllTest> allTests); 
};