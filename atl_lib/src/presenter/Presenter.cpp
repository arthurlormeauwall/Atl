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
string UnitTestInitPresenter::getString(UnitTestView UnitTestInit) {
	string out;
	string tab ="                  "; 
	out.append(format(tab, UnitTestInit.result.pass));
	out.append(UnitTestInit.path).append("\n");

	vector<Result> assertResults = UnitTestInit.childrenResult;
	for (Result assertResult : assertResults) {
		if (!assertResult.pass) {
			out.append(m_assertPresenter.getString(AssertResultView(assertResult)));
		}
	}
	return out;
}
string TestClassInitPresenter::getString(TestClassView TestClassInit) {
	string out;
	string tab ="         "; 
	out.append(format(tab, TestClassInit.result.pass));
	out.append(TestClassInit.path).append("\n");

	vector<sharedptr<TestData>> UnitTestInits = TestClassInit.children;
	for (sharedptr<TestData> ut :  UnitTestInits) {
		out.append(m_UnitTestInitPresenter.getString(UnitTestView(ut)));
	}
	return out;
}


string ModuleInitPresenter::getString(ModuleView moduleView) {
	string out;
	string tab =""; 
	out.append(format(tab, moduleView.result.pass));
	out.append(moduleView.path).append("\n");

	vector<sharedptr<TestData>> TestClassInit = moduleView.children;
	for (sharedptr<TestData> tc : TestClassInit) {
		out.append(m_TestClassInitPresenter.getString(TestClassView(tc)));
	}
	out.append("\n");
	return out;
}

string Presenter::getStringFromTestResult(sharedptr<TestData> testData)
{
	string out;
	out.append(commonViews::welcome);

	//vector<sharedptr<TestData>> ModuleInits = allTest->getAllChildren();
	//for (sharedptr<TestData> m : ModuleInits) {
	//	out.append(m_ModuleInitPresenter.getString(ModuleInitView(m)));
	//}
	out.append(commonViews::goodBye);
	return out;
}
