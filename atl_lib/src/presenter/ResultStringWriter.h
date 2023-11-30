#pragma once
#include "../template.h"

class ResultStringWriter {

	string m_stringResult;
	string m_currentTab;

	void writeLine(string content) {
		m_stringResult.append(m_currentTab).append(content);
	}

public:
	ResultStringWriter() {
		m_stringResult = "";
		m_currentTab = "";
	}
	void breakLine() {
		m_stringResult.append("\n");
	}
	void setTab(string tab) {
		m_currentTab = tab;
	}
	void writeSingleLine(string lineContent) {
		writeLine(lineContent);
		breakLine();
	}
	void writeBloc(vector<string> lineContents) {
		for (string lineContent : lineContents) {
			writeLine(lineContent);
			breakLine();
		}
	}
	void addNext(string next) {
		m_stringResult.append(next);
		breakLine();
	}
	string getStringResult() {
		return m_stringResult;
	}
};
