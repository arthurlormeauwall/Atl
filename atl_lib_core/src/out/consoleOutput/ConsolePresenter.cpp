#include "../../template.h"
#include "ConsolePresenter.h"
#include "style/color/ConsolecolorHelpers.h"



string addSucceedOrFailed(bool pass, string content, bool m_ansiColorEnabled) {
	string out;
	string succeed = color(F_GREEN, "[succeed]", m_ansiColorEnabled);
	string failed = color(F_RED, "[failed]", m_ansiColorEnabled);
	string resultToken = pass ? succeed : failed;
	string blank = " ";
	out.append(resultToken).append(blank).append(content);
	return out;
}

void ConsoleAssertPresenter::addResultToStringWriter(const ResultView& resultView,
	ConsoleResultStringWriter& stringWriter) {
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

void ConsoleResultPresenter::addResultToStringWriter(const ResultView& resultView, ConsoleResultStringWriter& stringWriter) {
	vector<string> messages = resultView.messages;
	int messagesSize = messages.size();
	if (messagesSize > 0) {
		stringWriter.writeSingleLine(addSucceedOrFailed(resultView.pass, messages.at(0), m_ansiColorEnabled));
	}
	if (messagesSize > 1) {
		vector<string> messages_minus_first = { messages.begin() + 1, messages.end() };
		stringWriter.writeBloc(messages_minus_first);
	}
}

void ConsoleUnitTestPresenter::addResultToStringWriter(const UnitTestView& unitTestView, ConsoleResultStringWriter& stringWriter)
{
	stringWriter.setTab(5);
	stringWriter.writeSingleLine(addSucceedOrFailed(unitTestView.result.pass, unitTestView.name, m_ansiColorEnabled));
	if (!unitTestView.result.exist)
		m_consoleResultPresenter.addResultToStringWriter(ResultView(unitTestView.result.pass, unitTestView.result.messages), stringWriter);

	stringWriter.setTab(7);
	for (const ResultView assertView : unitTestView.children) {
		m_consoleAssertPresenter.addResultToStringWriter(assertView, stringWriter);
	}
}
void ConsoleTestClassPresenter::addResultToStringWriter(const TestClassView& testClassView, ConsoleResultStringWriter& stringWriter)
{
	stringWriter.setTab(2);
	stringWriter.writeSingleLine(addSucceedOrFailed(testClassView.result.pass, testClassView.name, m_ansiColorEnabled));
	if (!testClassView.result.exist)
		m_consoleResultPresenter.addResultToStringWriter(ResultView(testClassView.result.pass, testClassView.result.messages), stringWriter);

	if (!testClassView.result.pass) {
		for (const UnitTestView unitTestView : testClassView.children) {
			m_consoleUnitTestPresenter.addResultToStringWriter(unitTestView, stringWriter);
		}
	}
}

void ConsoleModulePresenter::addResultToStringWriter(const ModuleView& moduleView, ConsoleResultStringWriter& stringWriter)
{
	stringWriter.setTab(0);
	stringWriter.writeSingleLine(addSucceedOrFailed(moduleView.result.pass, moduleView.name, m_ansiColorEnabled));

	if (!moduleView.result.exist)
		m_consoleResultPresenter.addResultToStringWriter(ResultView(moduleView.result.pass, moduleView.result.messages), stringWriter);

	if (!moduleView.result.pass) {
		for (const TestClassView testClassView : moduleView.children) {
			m_consoleTestClassPresenter.addResultToStringWriter(testClassView, stringWriter);
		}
	}

	// break line at the end of each module to separate each module results with blanck line
	stringWriter.breakLine();
}

void ConsoleAllTestPresenter::addResultToStringWriter(const AllTestView& allTestView, ConsoleResultStringWriter& stringWriter)
{
	stringWriter.setTab(6);
	stringWriter.writeSingleLine(color(F_YELLOW, commonViews::welcome, m_ansiColorEnabled));
	stringWriter.setTab(0);
	if (m_ansiColorEnabled) {

	stringWriter.writeBlocWithColor(commonViews::atl_ascii, F_YELLOW);
	}
	else {
		stringWriter.writeBloc(commonViews::atl_ascii);
	}
	stringWriter.setTab(6);
	stringWriter.breakLine();
	stringWriter.writeSingleLine(color(F_YELLOW, commonViews::presentation, m_ansiColorEnabled));
	stringWriter.setTab(0);
	stringWriter.breakLine();
	stringWriter.breakLine();
	for (const ModuleView moduleView : allTestView.children) {
		if (moduleView.result.executed) {
			m_consoleModulePresenter.addResultToStringWriter(moduleView, stringWriter);
		}
	}
	stringWriter.writeSingleLine(color(F_YELLOW, commonViews::goodBye, m_ansiColorEnabled));
}

string ConsoleAllTestPresenter::getStringFromTestResult(const TestData& testData)
{
	ConsoleResultStringWriter stringWriter;

	addResultToStringWriter(AllTestView(testData), stringWriter);

	return stringWriter.getStringResult();
}
