#include "../template.h"
#include "Presenter.h"



string addSucceedOrFailed(bool pass, string content) {
	string out;
	string succeed = color(F_GREEN, "[succeed]");
	string failed = color(F_RED, "[failed]");
	string resultToken = pass ? succeed : failed;
	string blank = " ";
	out.append(resultToken).append(blank).append(content);
	return out;
}

void AssertPresenter::writeResult(const ResultView& resultView,
	ResultStringWriter& stringWriter) {
	vector<string> messages = vector<string>({ "* failed assertion : " });
	vector<string> resultMessages = resultView.messages;
	int resultMessagesSize = resultMessages.size();
	if (resultMessagesSize > 0) {
		for (string m : resultMessages) {
			messages.push_back(m);
		}
	}
	else {
		messages = resultMessages;
	}
	stringWriter.writeBloc(messages);
}

void ResultPresenter::writeResult(const ResultView& resultView, ResultStringWriter& stringWriter) {
	vector<string> messages = resultView.messages;
	int messagesSize = messages.size();
	if (messagesSize > 0) {
		stringWriter.writeSingleLine(addSucceedOrFailed(resultView.pass, messages.at(0)));
	}
	if (messagesSize > 1) {
		vector<string> messages_minus_first = { messages.begin() + 1, messages.end() };
		stringWriter.writeBloc(messages_minus_first);
	}
}

void UnitTestPresenter::writeResult(const UnitTestView& unitTestView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab(5);
	stringWriter.writeSingleLine(addSucceedOrFailed(unitTestView.result.pass, unitTestView.name));
	if (!unitTestView.result.exist)
		m_resultPresenter.writeResult(ResultView(unitTestView.result.pass, unitTestView.result.messages), stringWriter);

	stringWriter.setTab(7);
	for (const ResultView assertView : unitTestView.children) {
		m_assertPresenter.writeResult(assertView, stringWriter);
	}
}
void TestClassPresenter::writeResult(const TestClassView& testClassView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab(2);
	stringWriter.writeSingleLine(addSucceedOrFailed(testClassView.result.pass, testClassView.name));
	if (!testClassView.result.exist)
		m_resultPresenter.writeResult(ResultView(testClassView.result.pass, testClassView.result.messages), stringWriter);

	if (!testClassView.result.pass) {
		for (const UnitTestView unitTestView : testClassView.children) {
			m_UnitTestPresenter.writeResult(unitTestView, stringWriter);
		}
	}
}

void ModulePresenter::writeResult(const ModuleView& moduleView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab(0);
	stringWriter.writeSingleLine(addSucceedOrFailed(moduleView.result.pass, moduleView.name));

	if (!moduleView.result.exist)
		m_resultPresenter.writeResult(ResultView(moduleView.result.pass, moduleView.result.messages), stringWriter);

	if (!moduleView.result.pass) {
		for (const TestClassView testClassView : moduleView.children) {
			m_testClassPresenter.writeResult(testClassView, stringWriter);
		}
	}

	// break line at the end of each module to separate each module results with blanck line
	stringWriter.breakLine();
}

void AllTestPresenter::writeResult(const AllTestView& allTestView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab(6);
	stringWriter.writeSingleLine(commonViews::welcome);
	stringWriter.setTab(0);
	stringWriter.writeBloc(commonViews::atl_ascii);
	stringWriter.setTab(6);
	stringWriter.breakLine();
	stringWriter.writeSingleLine(commonViews::presentation);
	stringWriter.setTab(0);
	stringWriter.breakLine();
	stringWriter.breakLine();
	for (const ModuleView moduleView : allTestView.children) {
		if (moduleView.result.executed) {
			m_modulePresenter.writeResult(moduleView, stringWriter);
		}
	}
	stringWriter.writeSingleLine(commonViews::goodBye);
}

string AllTestPresenter::getStringFromTestResult(const TestData& testData)
{
	ResultStringWriter stringWriter;

	writeResult(AllTestView(testData), stringWriter);

	return stringWriter.getStringResult();
}
