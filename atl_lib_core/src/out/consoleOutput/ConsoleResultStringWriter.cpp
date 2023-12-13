#pragma once
#include "../../template.h"
#include "ConsoleResultStringWriter.h"


void ConsoleResultStringWriter::writeLine(string content) {
	m_stringResult.append(m_currentTab).append(content);
}

ConsoleResultStringWriter::ConsoleResultStringWriter() {
	m_stringResult = "";
	m_currentTab = "";
}
void ConsoleResultStringWriter::breakLine() {
	m_stringResult.append("\n");
}
void ConsoleResultStringWriter::setTab(int tab) {
	string tabstr_template = "    ";
	string tabstr = "";
	for (int i = 0; i < tab; i++) {
		tabstr.append(tabstr_template);
	}
	m_currentTab = tabstr;
}

void ConsoleResultStringWriter::writeSingleLine(string lineContent) {
	writeLine(lineContent);
	breakLine();
}

void ConsoleResultStringWriter::writeBloc(vector<string> lineContents) {
	for (string lineContent : lineContents) {
		writeLine(lineContent);
		breakLine();
	}
}

void ConsoleResultStringWriter::writeBlocWithColor(vector<string> lineContents, string c) {
	for (string lineContent : lineContents) {
		writeLine(color(c, lineContent, true));
		breakLine();
	}
}
void ConsoleResultStringWriter::addNext(string next) {
	m_stringResult.append(next);
	breakLine();
}
string ConsoleResultStringWriter::getStringResult() {
	return m_stringResult;
}
