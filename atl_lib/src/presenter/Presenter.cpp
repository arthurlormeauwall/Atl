#include "../template.h"
#include "Presenter.h"

string AssertPresenter::getString(sharedptr<Result> assert) {
	string out;
	//out.append("Inside assert presenter \n");
	return out;
}
string UnitTestPresenter::getString(sharedptr<TestInterface> unitTest) {
	string out;
	out.append("Inside unit Test presenter \n");
	out.append("module name : ").append(unitTest->getData().path.moduleName).append("\n");
	out.append("Test class name : ").append(unitTest->getData().path.testClassName).append("\n");
	out.append("unit Test name : ").append(unitTest->getData().path.unitTestName).append("\n");
	return out;
}
string TestClassPresenter::getString(sharedptr<TestInterface> testClass) {
	string out;
	out.append("Inside Test class presenter \n");
	out.append("module name : ").append(testClass->getData().path.moduleName).append("\n");
	out.append("Test class name : ").append(testClass->getData().path.testClassName).append("\n");

	vector<sharedptr<TestInterface>> unitTests = testClass->getAllChildren();
	for (sharedptr<TestInterface> ut :  unitTests) {
		out.append(m_unitTestPresenter.getString(ut));
	}
	return out;
}

string ModulePresenter::getString(sharedptr<TestInterface> module) {
	string out;
	out.append("Inside module presenter \n");
	out.append("module name : ").append(module->getData().path.moduleName).append("\n");

	vector<sharedptr<TestInterface>> testClass = module->getAllChildren();
	for (sharedptr<TestInterface> tc : testClass) {
		out.append(m_testClassPresenter.getString(tc));
	}
	return out;
}

string Presenter::getStringFromTestResult(sharedptr<TestInterface> allTest)
{
	string out;
	out.append(commonViews::welcome);

	vector<sharedptr<TestInterface>> modules = allTest->getAllChildren();
	for (sharedptr<TestInterface> m : modules) {
		out.append(m_modulePresenter.getString(m));
	}

	out.append(commonViews::goodBye);
	return out;
}
