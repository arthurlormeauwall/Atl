#pragma once
#include "../template.h"
#include "../out/consoleOutput/ConsoleOutputWriter.h"
#include "../testBuilder/TestBuilder.h"
#include "TestRunner.h"

class AtlService {
public:
	AtlService(std::shared_ptr<OutputWriter> outputWriter): m_outputWriter(outputWriter) {}
	void runAllTests(TestData& allTests);
	void runSomeTests(TestData& allTests, vector<string>);

private:
	std::shared_ptr<OutputWriter> m_outputWriter;
	void write(const TestData& allTests); 
};