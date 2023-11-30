#pragma once
#include "../template.h"
#include "../model/Model.h"
#include "../testBuilder/TestBuilder.h"
#include "views/Views.h"
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
	void reset() {
		m_currentTab="";
		m_stringResult="";
	}
	string getStringResult() {
		return m_stringResult;
	}
};

class ResultPresenter {
public:
	void writeResult(const ResultView&, ResultStringWriter&);
	void writeResultWithoutFormatedFirstLine(const ResultView&, ResultStringWriter&);
};

class UnitTestPresenter {
	ResultPresenter m_resultPresenter;
	ResultPresenter m_assertPresenter;
public:
	void writeResult(const UnitTestView&, ResultStringWriter&);
};

class TestClassPresenter {
	ResultPresenter m_resultPresenter;
	UnitTestPresenter m_UnitTestPresenter;
public:
	void writeResult(const TestClassView&, ResultStringWriter&);
};

class ModulePresenter {
	ResultPresenter m_resultPresenter;
	TestClassPresenter m_testClassPresenter;
public:
	void writeResult(const ModuleView&, ResultStringWriter&);
};


class Presenter {
	ResultPresenter m_resultPresenter;
	ModulePresenter m_modulePresenter;
public:
	Presenter() {
	}
	string getStringFromTestResult(const TestData&);
	void writeResult(const AllTestView&, ResultStringWriter&);
};

