#include "../template.h"
#include "Presenter.h"
#include "../service/assertion/IsEqualTo.h"



struct ResultViewBuilder {
	virtual ResultView getResultView(Result result) = 0;
};


string addSuccessOrFail(bool pass, string content) {
	string out;
	string resultToken = pass ? "[success]" : "[failed]";
	string blank = " ";
	out.append(resultToken).append(blank).append(content);
	return out;
}

//string ResultPresenter::getString(ResultView assertResult) {
//	string out;
//	out.append(assertResult.message);
//	return out;
//}
//
//struct UnitTestResultViewBuilder {
//	static ResultView getResultView(string name, Result result) {
//		return ResultView(result.pass, name);
//	}
//};
//
//struct AssertResultViewBuilder {
//	ResultStringWriter stringWriter;
//	static ResultView getResultView(string tab, Result result) {
//		ResultStringWriter stringWriter;
//		stringWriter.setTab(tab);
//		stringWriter.writeSingleLine(addSuccessOrFail(result.pass, result.messages.at(0)));
//		for (int i = 1; i < result.messages.size(); i++) {
//			stringWriter.writeSingleLine(result.messages.at(i));
//		}
//		return ResultView(result.pass, stringWriter.getStringResult());
//	}
//};
//
//string UnitTestPresenter::getString(UnitTestView unitTestView) {
//	string tab = "                  ";
//	m_resultStringWriter.reset();
//	m_resultStringWriter.setTab(tab);
//	m_resultStringWriter.writeSingleLine(addSuccessOrFail(unitTestView.result.pass, unitTestView.name));
//
//	if (!unitTestView.result.exist)
//		m_resultStringWriter.writeSingleLine(m_resultPresenter.getString(
//			UnitTestResultViewBuilder::getResultView(unitTestView.name, unitTestView.result)));
//	auto assertResults = unitTestView.childrenResult;
//	for (auto assertResult : assertResults) {
//		if (!assertResult.pass) {
//			m_resultStringWriter.writeSingleLine(m_assertPresenter.getString(
//				AssertResultViewBuilder::getResultView(tab, assertResult)));
//		}
//	}
//	return m_resultStringWriter.getStringResult();
//}
//
//
//struct TestClassResultViewBuilder {
//	static ResultView getResultView(string name, Result result) {
//		return ResultView(result.pass, name);
//	}
//};
//
//string TestClassPresenter::getString(TestClassView testClassView) {
//	m_resultStringWriter.reset();
//	m_resultStringWriter.setTab("         ");
//	m_resultStringWriter.writeSingleLine(addSuccessOrFail(testClassView.result.pass, testClassView.name));
//
//	if (!testClassView.result.exist)
//		m_resultStringWriter.writeSingleLine(m_resultPresenter.getString(
//			TestClassResultViewBuilder::getResultView(testClassView.name, testClassView.result)));
//	auto unitTests = testClassView.children;
//	for (auto ut : unitTests) {
//		if (ut.result.executed) {
//			m_resultStringWriter.addNext(m_UnitTestInitPresenter.getString(UnitTestView(ut)));
//		}
//	}
//	return m_resultStringWriter.getStringResult();
//}
//
//struct ModuleResultViewBuilder {
//	static ResultView getResultView(string name, Result result) {
//		auto message = name.append(result.messages.at(0));
//		return ResultView(result.pass, message);
//	}
//};

//string ModulePresenter::getString(ModuleView moduleView) {
//	m_resultStringWriter.reset();
//	m_resultStringWriter.setTab("");
//	m_resultStringWriter.writeSingleLine(addSuccessOrFail(moduleView.result.pass, moduleView.name));
//
//	if (!moduleView.result.exist)
//		m_resultStringWriter.writeSingleLine(m_resultPresenter.getString(
//			ModuleResultViewBuilder::getResultView(moduleView.name, moduleView.result)));
//
//	auto testClasses = moduleView.children;
//	for (auto tc : testClasses) {
//		if (tc.result.executed) {
//			m_resultStringWriter.addNext(m_TestClassInitPresenter.getString(TestClassView(tc)));
//		}
//	}
//	return m_resultStringWriter.getStringResult();
//}

//struct AllTestResultViewBuilder {
//	static const ResultView getResultView(string name, Result result) {
//		return ResultView(result.pass, result.messages.at(0));
//	}
//};

string Presenter::getStringFromTestResult(const TestData& testData)
{
	ResultStringWriter stringWriter;

	stringWriter.writeSingleLine(commonViews::welcome);

	writeResult(AllTestView(testData), stringWriter);

	stringWriter.writeSingleLine(commonViews::goodBye);
	return stringWriter.getStringResult();
}

void ResultPresenter::writeResultWithoutFormatedFirstLine(const ResultView& resultView, ResultStringWriter& stringWriter) {
	vector<string> messages = resultView.messages;
	int messagesSize = messages.size();
	if (messagesSize > 0) {
		stringWriter.writeBloc(messages);
	}
}
void ResultPresenter::writeResult(const ResultView& resultView, ResultStringWriter& stringWriter) {
	vector<string> messages = resultView.messages;
	int messagesSize = messages.size();
	if (messagesSize > 0) {
		stringWriter.writeSingleLine(addSuccessOrFail(resultView.pass, messages.at(0)));
	}
	if (messagesSize > 1) {
		vector<string> messages_minus_first = { messages.begin() + 1, messages.end() };
		stringWriter.writeBloc(messages_minus_first);
	}
}

void UnitTestPresenter::writeResult(const UnitTestView& testData, ResultStringWriter& resultWriter)
{
	resultWriter.setTab("              ");
	resultWriter.writeSingleLine(addSuccessOrFail(testData.result.pass, testData.name));
	if (!testData.result.exist)
		m_resultPresenter.writeResult(ResultView(testData.result.pass, testData.result.messages), resultWriter);

	resultWriter.setTab("                        ");
	for (const ResultView m : testData.children) {
		m_assertPresenter.writeResultWithoutFormatedFirstLine(m, resultWriter);
	}
}
void TestClassPresenter::writeResult(const TestClassView& testData, ResultStringWriter& resultWriter)
{
	resultWriter.setTab("      ");
	resultWriter.writeSingleLine(addSuccessOrFail(testData.result.pass, testData.name));
	if (!testData.result.exist)
		m_resultPresenter.writeResult(ResultView(testData.result.pass, testData.result.messages), resultWriter);

	for (const UnitTestView m : testData.children) {
		m_UnitTestPresenter.writeResult(m, resultWriter);
	}
}
void ModulePresenter::writeResult(const ModuleView& testData, ResultStringWriter& resultWriter)
{
	resultWriter.setTab("");
	resultWriter.writeSingleLine(addSuccessOrFail(testData.result.pass, testData.name));

	if (!testData.result.exist)
		m_resultPresenter.writeResult(ResultView(testData.result.pass, testData.result.messages), resultWriter);

	for (const TestClassView m : testData.children) {
		m_testClassPresenter.writeResult(m, resultWriter);
	}
	resultWriter.breakLine();
}

void Presenter::writeResult(const AllTestView& testData, ResultStringWriter& resultWriter)
{
	resultWriter.setTab("");
	if (!testData.result.exist)
		m_resultPresenter.writeResult(ResultView(testData.result.pass, testData.result.messages), resultWriter);

	for (const ModuleView m : testData.children) {
		if (m.result.executed) {
			m_modulePresenter.writeResult(m, resultWriter);
		}
	}
}
