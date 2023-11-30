#include "../template.h"
#include "Presenter.h"
#include "../service/assertion/IsEqualTo.h"
#include "color/colorHelpers.h"

string addSuccessOrFail(bool pass, string content) {
	string out;
	string resultToken = pass ? color(F_GREEN, "[succeed]") : color(F_RED, "[failed]");
	string blank = " ";
	out.append(resultToken).append(blank).append(content);
	return out;
}

void ResultPresenter::writeResultWithoutFormatedFirstLine(const ResultView& resultView,
	ResultStringWriter& stringWriter) {
	vector<string> messages = resultView.messages;
	int messagesSize = messages.size();
	stringWriter.writeBloc(messages);
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

void UnitTestPresenter::writeResult(const UnitTestView& unitTestView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab("              ");
	stringWriter.writeSingleLine(addSuccessOrFail(unitTestView.result.pass, unitTestView.name));
	if (!unitTestView.result.exist)
		m_resultPresenter.writeResult(ResultView(unitTestView.result.pass, unitTestView.result.messages), stringWriter);

	stringWriter.setTab("                        ");
	for (const ResultView m : unitTestView.children) {
		m_assertPresenter.writeResultWithoutFormatedFirstLine(m, stringWriter);
	}
}
void TestClassPresenter::writeResult(const TestClassView& testClassView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab("      ");
	stringWriter.writeSingleLine(addSuccessOrFail(testClassView.result.pass, testClassView.name));
	if (!testClassView.result.exist)
		m_resultPresenter.writeResult(ResultView(testClassView.result.pass, testClassView.result.messages), stringWriter);

	for (const UnitTestView m : testClassView.children) {
		m_UnitTestPresenter.writeResult(m, stringWriter);
	}
}

void ModulePresenter::writeResult(const ModuleView& moduleView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab("");
	stringWriter.writeSingleLine(addSuccessOrFail(moduleView.result.pass, moduleView.name));

	if (!moduleView.result.exist)
		m_resultPresenter.writeResult(ResultView(moduleView.result.pass, moduleView.result.messages), stringWriter);

	for (const TestClassView m : moduleView.children) {
		m_testClassPresenter.writeResult(m, stringWriter);
	}
	stringWriter.breakLine();
}

void AllTestPresenter::writeResult(const AllTestView& allTestView, ResultStringWriter& stringWriter)
{
	stringWriter.setTab("");
	if (!allTestView.result.exist)
		m_resultPresenter.writeResult(ResultView(allTestView.result.pass, allTestView.result.messages), stringWriter);

	for (const ModuleView m : allTestView.children) {
		if (m.result.executed) {
			m_modulePresenter.writeResult(m, stringWriter);
		}
	}
}

string AllTestPresenter::getStringFromTestResult(const TestData& testData)
{
	ResultStringWriter stringWriter;

	stringWriter.writeSingleLine(commonViews::welcome);

	writeResult(AllTestView(testData), stringWriter);

	stringWriter.writeSingleLine(commonViews::goodBye);
	return stringWriter.getStringResult();
}
