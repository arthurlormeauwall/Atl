#include "TestResultContainer.h"

void TestResultContainer::addUnitTestResult(vector<std::shared_ptr<UnitTestResult>> uts)
{
	for (std::shared_ptr<UnitTestResult> ut : uts) {
		Path path = ut->path;
		string utName = path.unitTestName;
		string testClassName = path.testClassName;
		string moduleName = path.moduleName;

		std::map<string, ModuleResult> newModules;
		std::map<string, TestClassResult> newTestClasses;
		std::map<string, std::shared_ptr<UnitTestResult>> newUnitTests;

		newUnitTests.emplace(utName, ut);
		TestClassResult newTestClass(testClassName, newUnitTests);
		newTestClasses.emplace(testClassName, newTestClass);
		ModuleResult newModule(moduleName, newTestClasses);

		std::map<string, ModuleResult>::iterator moduleIt = m_allTestResult.modules.find(moduleName);
		if (moduleIt != m_allTestResult.modules.end()) {
			std::map<string, TestClassResult>::iterator testClassIt = moduleIt->second.testClasses.find(testClassName);
			if (testClassIt != moduleIt->second.testClasses.end()) {
				testClassIt->second.unitTestResults.emplace(utName, ut);
			}
			else
			{
				moduleIt->second.testClasses.emplace(testClassName, newTestClass);
			}
		}
		else
		{
			m_allTestResult.modules.emplace(moduleName, newModule);
		}
	}
	setInterResult();
}


void TestResultContainer::setInterResult()
{
	for (std::map<string, ModuleResult>::iterator moduleIt = m_allTestResult.modules.begin(); moduleIt != m_allTestResult.modules.end(); moduleIt++) {
		for (std::map<string, TestClassResult>::iterator testClassIt = moduleIt->second.testClasses.begin(); testClassIt != moduleIt->second.testClasses.end(); testClassIt++) {
			for (std::map<string, std::shared_ptr<UnitTestResult>>::iterator utIt = testClassIt->second.unitTestResults.begin(); utIt != testClassIt->second.unitTestResults.end(); utIt++) {
				utIt->second->setResult();
			}
			testClassIt->second.setResult();
		}
		moduleIt->second.setResult();
	}
	m_allTestResult.setResult();
}

sharedptr<AllTestResult> TestResultContainer::getAllTestResult()
{
	return std::make_shared<AllTestResult>(m_allTestResult);
}
