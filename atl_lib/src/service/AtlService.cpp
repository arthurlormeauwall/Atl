#include "../template.h"
#include "AtlService.h"

void AtlService::runAllTests(sharedptr<TestData> allTests){
	TestRunner testRunner;
	sharedptr<TestData> t = testRunner.run(allTests);
	//write(allTests);
}

void AtlService::write(sharedptr<TestData> allTests) {
	//string out = m_presenter.getStringFromTestResult(allTests);
	//m_outputWriter->write(out);
}
