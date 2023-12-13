#pragma once
#include "../../template.h"
#include "style/color/ConsolecolorHelpers.h"

class ConsoleResultStringWriter {

	string m_stringResult;
	string m_currentTab;
	void writeLine(string content);

public:
	ConsoleResultStringWriter();
	void breakLine();
	void setTab(int tab);
	void writeSingleLine(string lineContent);
	void writeBloc(vector<string> lineContents);
	void writeBlocWithColor(vector<string> lineContents, string c);
	void addNext(string next);
	string getStringResult();
};
