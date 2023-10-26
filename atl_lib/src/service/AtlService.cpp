#include "AtlService.h"

vector<sharedptr<Result>> runUnitTest(sharedptr<UnitTest> ut) {
	vector<sharedptr<Result>> assertions = ut->unitTestRunnable(ut->path);
	return assertions;
}

vector<sharedptr<UnitTestResult>> runTests(vector<sharedptr<UnitTest>> unitTests) {
	vector<sharedptr<UnitTestResult>> utResult;
	for (sharedptr<UnitTest> ut : unitTests) {
		vector<sharedptr<Result>> results= runUnitTest(ut);
		utResult.push_back(std::make_shared<UnitTestResult>(results, ut->path));
	}
	return utResult;
}

void AtlService::
runUnitTests(vector<sharedptr<UnitTest>> unitTests)
{
	vector<sharedptr<UnitTestResult>> unitTestResults = runTests(unitTests);
	m_allTestResult.addUnitTestResult(unitTestResults);
}

void AtlService::runAllTests()
{
    runUnitTests(m_allTest.getAllUnitTest());
	write();
}

void AtlService::addUnitTest(sharedptr<UnitTest> unitTest)
{
	m_allTest.addUnitTest(unitTest);
}

void AtlService::write() 
{
	string out = m_presenter.getStringFromTestResult(m_allTestResult.getAllTestResult());
	m_outputWriter->write(std::make_shared<string>(out));
}
