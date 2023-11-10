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
string UnitTestInitPresenter::getString(UnitTestInitView UnitTestInit) {
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
string TestClassInitPresenter::getString(TestClassInitView TestClassInit) {
	string out;
	string tab ="         "; 
	out.append(format(tab, TestClassInit.result.pass));
	out.append(TestClassInit.path).append("\n");

	vector<sharedptr<TestInit>> UnitTestInits = TestClassInit.children;
	for (sharedptr<TestInit> ut :  UnitTestInits) {
		out.append(m_UnitTestInitPresenter.getString(UnitTestInitView(ut)));
	}
	return out;
}


string ModuleInitPresenter::getString(ModuleInitView ModuleInit) {
	string out;
	string tab =""; 
	out.append(format(tab, ModuleInit.result.pass));
	out.append(ModuleInit.path).append("\n");

	vector<sharedptr<TestInit>> TestClassInit = ModuleInit.children;
	for (sharedptr<TestInit> tc : TestClassInit) {
		out.append(m_TestClassInitPresenter.getString(TestClassInitView(tc)));
	}
	out.append("\n");
	return out;
}

string Presenter::getStringFromTestResult(sharedptr<TestInit> allTest)
{
	string out;
	out.append(commonViews::welcome);

	//vector<sharedptr<TestInit>> ModuleInits = allTest->getAllChildren();
	//for (sharedptr<TestInit> m : ModuleInits) {
	//	out.append(m_ModuleInitPresenter.getString(ModuleInitView(m)));
	//}
	out.append(commonViews::goodBye);
	return out;
}
