#pragma once
#include "../pch.h"
#include "../model/AllTests.h"
#include "views/Views.h"

class AssertPresenter {
public:
	string getString(sharedptr<Result>);
};
class UnitTestPresenter {
	AssertPresenter m_assertPresenter;
public:
	string getString(sharedptr<UnitTest>);
};

class TestClassPresenter {
	UnitTestPresenter m_unitTestPresenter;
public:
	string getString(sharedptr<TestClass>);
};

class ModulePresenter {
	TestClassPresenter m_testClassPresenter;
public:
	string getString(sharedptr<Module>);
};

class AllTestPresenter {
	ModulePresenter m_modulePresenter;
public:
	string getString(sharedptr<Test>);
};

class Presenter {
	AllTestPresenter m_allTestPresenter;
public:
	string getStringFromTestResult(sharedptr<Test>);
};

