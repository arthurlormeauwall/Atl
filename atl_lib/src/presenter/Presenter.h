#pragma once
#include "../template.h"
#include "../model/Model.h"
#include "../testBuilder/TestBuilder.h"
#include "views/Views.h"

class AssertPresenter {
public:
	string getString(AssertResultView);
};

class UnitTestPresenter {
	AssertPresenter m_assertPresenter;
public:
	string getString(UnitTestView);
};

class TestClassPresenter {
	UnitTestPresenter m_UnitTestInitPresenter;
public:
	string getString(TestClassView);
};

class ModulePresenter {
	TestClassPresenter m_TestClassInitPresenter;
public:
	string getString(ModuleView);
};


class Presenter {
	ModulePresenter m_ModuleInitPresenter;
public:
	string getStringFromTestResult(const TestData&);
};

