#include "../template.h"
#include "Presenter.h"

struct ResultViewBuilder {
	virtual ResultView getResultView(Result result) = 0;
};

string format(string tab, bool pass) {
	string out;
	string resultToken = pass ? "[success]" : "[failed]";
	string blank = " ";
	out.append(tab).append(resultToken).append(blank);
	return out;
}

string ResultPresenter::getStringForAssert(ResultView assertResult) {
	string out;
	string tab = "                           ";
	out.append(format(tab, assertResult.pass));
	out.append(assertResult.message).append("\n");
	return out;
}

string ResultPresenter::getStringForResult(ResultView assertResult, string tab) {
	string out;
	out.append(format(tab, assertResult.pass));
	out.append(assertResult.message).append("\n");
	return out;
}

string findToken(MessageTokenType tokenType, map<MessageTokenType, string> messageTokens) {
	map<MessageTokenType, string>::iterator it = messageTokens.find(tokenType);
	string out;
	it == messageTokens.end() ?
		out = "token not found" :
		out = it->second;
	return out;
}

struct UnitTestResultViewBuilder {
	static ResultView getResultView(Result result) {
		return ResultView(result.pass, findToken(NAME, result.messageTokens));
	}
};

struct AssertResultViewBuilder {
	static ResultView getResultView(Result result) {
		string message;
		if (result.pass) {
			message = "assert pass";
		}
		else {
			string actual = findToken(ACTUAL, result.messageTokens);
			string expected = findToken(EXPECTED, result.messageTokens);
			message = string("expected : \"").append(actual)
			.append("\" to be equal to : \"").append(expected).append("\"");
		}
		return ResultView(result.pass, message);
	}
};
string UnitTestPresenter::getStringForAssert(UnitTestView unitTestView) {
	string out;
	string tab = "                  ";
	out.append(format(tab, unitTestView.result.pass));
	out.append(unitTestView.name).append("\n");

	if (!unitTestView.result.exist)
		out.append(m_resultPresenter.getStringForResult(
			UnitTestResultViewBuilder::getResultView(unitTestView.result),
			string("")));
	auto assertResults = unitTestView.childrenResult;
	for (auto assertResult : assertResults) {
		if (!assertResult.pass) {
			out.append(m_assertPresenter.getStringForAssert(
				AssertResultViewBuilder::getResultView(assertResult)));
		}
	}
	return out;
}


struct TestClassResultViewBuilder {
	static ResultView getResultView(Result result) {
		return ResultView(result.pass, findToken(NAME, result.messageTokens));
	}
};

string TestClassPresenter::getStringForAssert(TestClassView testClassView) {
	string out;
	string tab = "         ";
	out.append(format(tab, testClassView.result.pass));
	out.append(testClassView.name).append("\n");

	if (!testClassView.result.exist)
		out.append(m_resultPresenter.getStringForResult(
			TestClassResultViewBuilder::getResultView(testClassView.result),
			string("")));
	auto UnitTestInits = testClassView.children;
	for (auto ut : UnitTestInits) {
		if (ut.result.executed) {
			out.append(m_UnitTestInitPresenter.getStringForAssert(UnitTestView(ut)));
		}
	}
	return out;
}

struct ModuleResultViewBuilder {
	static ResultView getResultView(Result result) {
		return ResultView(result.pass, findToken(NAME, result.messageTokens));
	}
};

string ModulePresenter::getStringForAssert(ModuleView moduleView) {
	string out;
	string tab = "";
	out.append(format(tab, moduleView.result.pass));
	out.append(moduleView.name).append("\n");

	if (!moduleView.result.exist)
		out.append(m_resultPresenter.getStringForResult(
			ModuleResultViewBuilder::getResultView(moduleView.result),
			string("")));
	auto TestClassInit = moduleView.children;
	for (auto tc : TestClassInit) {
		if (tc.result.executed) {
			out.append(m_TestClassInitPresenter.getStringForAssert(TestClassView(tc)));
		}
	}
	out.append("\n");
	return out;
}

struct AllTestResultViewBuilder {
	static ResultView getResultView(Result result) {
		return ResultView(result.pass, findToken(NAME, result.messageTokens));
	}
};

string Presenter::getStringFromTestResult(const TestData& testData)
{
	string out;
	out.append(commonViews::welcome);

	if (!testData.result.exist)
		out.append(m_resultPresenter.getStringForResult(
			AllTestResultViewBuilder::getResultView(testData.result),
			string("")));
	auto module = testData.children.getAllAsVector();
	for (const TestData m : module) {
		if (m.result.executed) {
			out.append(m_ModuleInitPresenter.getStringForAssert(ModuleView(m)));
		}
	}
	out.append(commonViews::goodBye);
	return out;
}
