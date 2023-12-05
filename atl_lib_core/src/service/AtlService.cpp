#include "../template.h"
#include "AtlService.h"

void AtlService::runAllTests(TestData& allTests){
	TestRunner testRunner;
	testRunner.run(allTests);
	write(allTests);
}

void AtlService::runSomeTests(TestData& allTests, vector<string> name) {
	TestRunner testRunner;
	testRunner.runSomeTests(allTests, name);
	write(allTests);
}

void AtlService::write(const TestData& allTests) {
	m_outputWriter->write(allTests);
}
