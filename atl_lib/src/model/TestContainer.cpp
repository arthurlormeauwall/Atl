#include "TestContainer.h"

void TestContainer::addUnitTest(sharedptr<UnitTest> ut)
{
	string utName = ut->path.unitTestName;
	string testClassName = ut->path.testClassName;
	string moduleName = ut->path.moduleName;

	testMap<TestClass> newTestClasses;
	testMap<sharedptr<UnitTest>> newUnitTests;

	newUnitTests.emplace(utName, ut);
	TestClass newTestClass(testClassName, newUnitTests);
	newTestClasses.emplace(testClassName, newTestClass);
	Module newModule(moduleName, newTestClasses);

	testMap<Module>::iterator moduleIt = m_allTest.modules.find(moduleName);
	if (moduleIt != m_allTest.modules.end()) {
		testMap<TestClass>::iterator testClassIt = moduleIt->second.testClasses.find(testClassName);
		if (testClassIt != moduleIt->second.testClasses.end()) {
			testClassIt->second.unitTests.emplace(utName, ut);
		}
		else
		{
			moduleIt->second.testClasses.emplace(testClassName, newTestClass);
		}
	}
	else
	{
		m_allTest.modules.emplace(moduleName, newModule);
	}
}

vector<sharedptr<UnitTest>> TestContainer::getAllUnitTest()
{
	vector<sharedptr<UnitTest>> ut;
	for (testMap<Module>::iterator moduleIt = m_allTest.modules.begin();
		moduleIt != m_allTest.modules.end();
		moduleIt++) {
		for (testMap<TestClass>::iterator testClassIt = moduleIt->second.testClasses.begin();
			testClassIt != moduleIt->second.testClasses.end();
			testClassIt++) {
			for (testMap<sharedptr<UnitTest>>::iterator utIt = testClassIt->second.unitTests.begin();
				utIt != testClassIt->second.unitTests.end();
				utIt++) {
				ut.push_back(utIt->second);
			}
		}
	}
	return ut;
}
