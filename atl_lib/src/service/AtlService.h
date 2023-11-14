#pragma once
#include "../template.h"
#include "../presenter/Presenter.h"
#include "../presenter/output/ConsoleOutputWriter.h"
#include "../testBuilder/TestBuilder.h"
#include "TestRunner.h"

class AtlService {
public:
	AtlService(): m_outputWriter(std::make_shared<ConsoleOutputWriter>()){}
	AtlService(std::shared_ptr<OutputWriter> outputWriter): m_outputWriter(outputWriter) {}
	void runAllTests(TestData& allTests);
	void runSomeTests(TestData& allTests, vector<string>);

private:
	std::shared_ptr<OutputWriter> m_outputWriter;
	Presenter m_presenter;
	void write(const TestData& allTests); 
};