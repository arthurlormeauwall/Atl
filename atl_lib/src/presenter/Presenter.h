#pragma once
#include "../template.h"
#include "../model/Result.h"
#include "../model/Initialisation/UnitTestInit.h"
#include "../model/Initialisation/TestClassInit.h"
#include "../model/Initialisation/ModuleInit.h"
#include "../model/Initialisation/TestInit.h"
#include "../model/Initialisation/AllTestInit.h"
#include "views/CommonViews.h"
#include "views/ModuleView.h"
#include "views/TestClassView.h"
#include "views/UnitTestView.h"
#include "views/AssertResultView.h"

class AssertPresenter {
public:
	string getString(AssertResultView);
};

class UnitTestInitPresenter {
	AssertPresenter m_assertPresenter;
public:
	string getString(UnitTestView);
};

class TestClassInitPresenter {
	UnitTestInitPresenter m_UnitTestInitPresenter;
public:
	string getString(TestClassView);
};

class ModuleInitPresenter {
	TestClassInitPresenter m_TestClassInitPresenter;
public:
	string getString(ModuleView);
};


class Presenter {
	ModuleInitPresenter m_ModuleInitPresenter;
public:
	string getStringFromTestResult(sharedptr<TestData>);
};

