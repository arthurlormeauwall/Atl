#include "../template.h"
#include "Presenter.h"
#include "views/ModuleView.h"

string format(string tab, bool pass) {
	string out;
	string resultToken = pass ? "[success]" : "[failed]";
	string blank = " ";
	out.append(tab).append(resultToken).append(blank);
	return out;
}

string AssertPresenter::getString(AssertResultView assertResult) {
	string out;
	string tab = "                           ";
	out.append(format(tab, assertResult.pass));
	out.append(assertResult.message).append("\n");
	return out;
}
string UnitTestPresenter::getString(UnitTestView unitTest) {
	string out;
	string tab ="                  "; 
	out.append(format(tab, unitTest.result.pass));
	out.append(unitTest.path.unitTestName).append("\n");

	vector<Result> assertResults = unitTest.childrenResult;
	for (Result assertResult : assertResults) {
		if (!assertResult.pass) {
			out.append(m_assertPresenter.getString(AssertResultView(assertResult)));
		}
	}
	return out;
}
string TestClassPresenter::getString(TestClassView testClass) {
	string out;
	string tab ="         "; 
	out.append(format(tab, testClass.result.pass));
	out.append(testClass.path.testClassName).append("\n");

	vector<sharedptr<TestInterface>> unitTests = testClass.children;
	for (sharedptr<TestInterface> ut :  unitTests) {
		out.append(m_unitTestPresenter.getString(UnitTestView(ut)));
	}
	return out;
}


string ModulePresenter::getString(ModuleView module) {
	string out;
	string tab =""; 
	out.append(format(tab, module.result.pass));
	out.append(module.path.moduleName).append("\n");

	vector<sharedptr<TestInterface>> testClass = module.children;
	for (sharedptr<TestInterface> tc : testClass) {
		out.append(m_testClassPresenter.getString(TestClassView(tc)));
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
		out.append(m_modulePresenter.getString(ModuleView(m)));
	}
	out.append(commonViews::goodBye);
	return out;
}
