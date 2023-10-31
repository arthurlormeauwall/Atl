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

vector<sharedptr<UnitTest>> getAllUnitTest(sharedptr<AllTest> test)
{
	vector<sharedptr<UnitTest>> ut;
	for (vector<sharedptr<Module>>::iterator moduleIt = test->modules.begin();
		moduleIt != test->modules.end();
		moduleIt++) {
		for (vector<sharedptr<TestClass>>::iterator testClassIt = (*moduleIt)->testClasses.begin();
			testClassIt !=(*moduleIt)->testClasses.end();
			testClassIt++) {
			for (vector<sharedptr<UnitTest>>::iterator utIt = (*testClassIt)->unitTests.begin();
				utIt != (*testClassIt)->unitTests.end();
				utIt++) {
				ut.push_back(*utIt);
			}
		}
	}
	return ut;
}
void AtlService::runAllTests(sharedptr<AllTest> allTests)
{
    runUnitTests(getAllUnitTest(allTests));
	write();
}

//void AtlService::addUnitTest(sharedptr<UnitTest> unitTest)
//{
//	m_allTest.addUnitTest(unitTest);
//}

void AtlService::write() 
{
	string out = m_presenter.getStringFromTestResult(m_allTestResult.getAllTestResult());
	m_outputWriter->write(std::make_shared<string>(out));
}
