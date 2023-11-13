#include "../template.h"
#include "AtlService.h"

void AtlService::runAllTests(TestData& allTests){
	TestRunner testRunner;
	testRunner.run(allTests);
	write(allTests);
}

void AtlService::write(const TestData& allTests) {
	string out = m_presenter.getStringFromTestResult(allTests);
	m_outputWriter->write(out);
}
