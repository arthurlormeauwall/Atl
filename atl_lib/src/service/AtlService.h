#pragma once
#include "../template.h"
#include "../presenter/Presenter.h"
#include "../presenter/output/ConsoleOutputWriter.h"
#include "../model/AllTest.h"

class AtlService {
public:
	AtlService(): m_outputWriter(std::make_shared<ConsoleOutputWriter>()){}
	AtlService(std::shared_ptr<OutputWriter> outputWriter): m_outputWriter(outputWriter) {}
	void runAllTests(sharedptr<AllTest> allTests);

private:
	std::shared_ptr<OutputWriter> m_outputWriter;
	Presenter m_presenter;
	void write(sharedptr<AllTest> allTests); 
};