#pragma once
#include "../template.h"
#include "../model/Model.h"
#include "../testBuilder/TestBuilder.h"
#include "views/Views.h"

class ResultPresenter {
public:
	string getStringForAssert(ResultView);
	string getStringForResult(ResultView,string);
};

class UnitTestPresenter {
	ResultPresenter m_resultPresenter;
	ResultPresenter m_assertPresenter;
public:
	string getStringForAssert(UnitTestView);
};

class TestClassPresenter {
	ResultPresenter m_resultPresenter;
	UnitTestPresenter m_UnitTestInitPresenter;
public:
	string getStringForAssert(TestClassView);
};

class ModulePresenter {
	ResultPresenter m_resultPresenter;
	TestClassPresenter m_TestClassInitPresenter;
public:
	string getStringForAssert(ModuleView);
};


class Presenter {
	ResultPresenter m_resultPresenter;
	ModulePresenter m_ModuleInitPresenter;
public:
	string getStringFromTestResult(const TestData&);
};

