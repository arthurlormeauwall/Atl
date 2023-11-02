#include "AtlService.h"

void AtlService::runAllTests(sharedptr<AllTest> allTests)
{
    allTests->run();
	write(allTests);
}

void AtlService::write(sharedptr<AllTest> allTests) 
{
	string out = m_presenter.getStringFromTestResult(allTests);
	m_outputWriter->write(std::make_shared<string>(out));
}
