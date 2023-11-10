#pragma once
#include "../template.h"
#include "../model/Result.h"
#include "../model/UnitTest.h"
#include "../model/TestClass.h"
#include "../model/Module.h"
#include "../model/TestInterface.h"
#include "../model/AllTest.h"
#include "views/CommonViews.h"
#include "views/ModuleView.h"
#include "views/TestClassView.h"
#include "views/UnitTestView.h"
#include "views/AssertResultView.h"

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
	UnitTestPresenter m_unitTestPresenter;
public:
	string getString(TestClassView);
};

class ModulePresenter {
	TestClassPresenter m_testClassPresenter;
public:
	string getString(ModuleView);
};


class Presenter {
	ModulePresenter m_modulePresenter;
public:
	string getStringFromTestResult(sharedptr<TestInterface>);
};

