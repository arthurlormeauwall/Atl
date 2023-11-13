#include "../template.h"
#include "Presenter.h"

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

string UnitTestPresenter::getString(UnitTestView UnitTestInit) {
	string out;
	string tab ="                  "; 
	out.append(format(tab, UnitTestInit.result.pass));
	out.append(UnitTestInit.path).append("\n");

	auto assertResults = UnitTestInit.childrenResult;
	for (auto assertResult : assertResults) {
		if (!assertResult.pass) {
			out.append(m_assertPresenter.getString(AssertResultView(assertResult)));
		}
	}
	return out;
}

string TestClassPresenter::getString(TestClassView TestClassInit) {
	string out;
	string tab ="         "; 
	out.append(format(tab, TestClassInit.result.pass));
	out.append(TestClassInit.path).append("\n");

	auto UnitTestInits = TestClassInit.children;
	for (auto ut :  UnitTestInits) {
		out.append(m_UnitTestInitPresenter.getString(UnitTestView(ut)));
	}
	return out;
}

string ModulePresenter::getString(ModuleView moduleView) {
	string out;
	string tab =""; 
	out.append(format(tab, moduleView.result.pass));
	out.append(moduleView.path).append("\n");

	auto TestClassInit = moduleView.children;
	for (auto tc : TestClassInit) {
		out.append(m_TestClassInitPresenter.getString(TestClassView(tc)));
	}
	out.append("\n");
	return out;
}

string Presenter::getStringFromTestResult(const TestData& testData)
{
	string out;
	out.append(commonViews::welcome);

	auto module = testData.children.getAllAsVector();
	for (const TestData m : module) {
		out.append(m_ModuleInitPresenter.getString(ModuleView(m)));
	}
	out.append(commonViews::goodBye);
	return out;
}
