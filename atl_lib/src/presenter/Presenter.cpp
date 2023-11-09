#include "../template.h"
#include "Presenter.h"

string format(string tab, bool pass) {
	string out;
	string resultToken = pass ? "[success]" : "[failed]";
	string blank = " ";
	out.append(tab).append(resultToken).append(blank);
	return out;
}

string AssertPresenter::getString(Result assert) {
	string out;
	string tab = "                           ";
	out.append(format(tab, assert.pass));
	out.append(assert.message).append("\n");
	return out;
}
string UnitTestPresenter::getString(sharedptr<TestInterface> unitTest) {
	string out;
	string tab ="                  "; 
	out.append(format(tab, unitTest->getData().result.pass));
	out.append(unitTest->getData().path.unitTestName).append("\n");

	vector<Result> assertResults = unitTest->getData().childrenResult.result;
	for (Result assertMessage : assertResults) {
		if (!assertMessage.pass) {
			out.append(m_assertPresenter.getString(assertMessage));
		}
	}
	return out;
}
string TestClassPresenter::getString(sharedptr<TestInterface> testClass) {
	string out;
	string tab ="         "; 
	out.append(format(tab, testClass->getData().result.pass));
	out.append(testClass->getData().path.testClassName).append("\n");

	vector<sharedptr<TestInterface>> unitTests = testClass->getAllChildren();
	for (sharedptr<TestInterface> ut :  unitTests) {
		out.append(m_unitTestPresenter.getString(ut));
	}
	return out;
}


string ModulePresenter::getString(sharedptr<TestInterface> module) {
	string out;
	string tab =""; 
	out.append(format(tab, module->getData().result.pass));
	out.append(module->getData().path.moduleName).append("\n");

	vector<sharedptr<TestInterface>> testClass = module->getAllChildren();
	for (sharedptr<TestInterface> tc : testClass) {
		out.append(m_testClassPresenter.getString(tc));
	}
	out.append("\n");
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
