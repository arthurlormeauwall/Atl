#pragma once
#include "../template.h"
#include "../model/Model.h"
#include "views/Views.h"
#include "views/CommonViews.h"
#include "ResultStringWriter.h"
#include "color/colorHelpers.h"


class ResultPresenter {
public:
	void writeResult(const ResultView&, ResultStringWriter&);
};

class AssertPresenter {
public:
	void writeResult(const ResultView&, ResultStringWriter&);
};
class UnitTestPresenter {
	ResultPresenter m_resultPresenter;
	AssertPresenter m_assertPresenter;
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

