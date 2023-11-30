#pragma once
#include "../template.h"
#include "../model/Model.h"
#include "../testBuilder/TestBuilder.h"
#include "views/Views.h"
#include "ResultStringWriter.h"


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


class AllTestPresenter {
	ResultPresenter m_resultPresenter;
	ModulePresenter m_modulePresenter;
public:
	string getStringFromTestResult(const TestData&);
	void writeResult(const AllTestView&, ResultStringWriter&);
};

