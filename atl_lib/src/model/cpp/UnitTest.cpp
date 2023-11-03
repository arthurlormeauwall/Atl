#include "../UnitTest.h"
#include "../../template.h"

bool UnitTest::areChildrenPassing(vector<Result> assertResult) {
	for (Result t : assertResult) {
		if (!t.pass) {
			return false;
		}
	}
	return true;
}

vector<string> UnitTest::getChildrenMessage(vector<Result> assertResult) {
	vector<string> messages;
	for (Result t : assertResult) {
		messages.push_back(t.message);
	}
	return messages;
}

void UnitTest::updateResult() {
	if (!m_testData.childrenResult.pass) {
		m_testData.result.pass = false;
		m_testData.result.message = "Some assertions failed";
	}
	else {
		m_testData.result.pass = true;
		m_testData.result.message = "UnitTest Succeed";
	}
}

void UnitTest::run() {
	assertResults = unitTestRunnable(Path(m_testData.path.moduleName, m_testData.path.testClassName, m_testData.path.unitTestName));
	m_testData.childrenResult.pass = areChildrenPassing(assertResults);
	m_testData.childrenResult.message = getChildrenMessage(assertResults);
	updateResult();
}

vector<Result> UnitTest::getAssertResults() {
	return assertResults;
}
