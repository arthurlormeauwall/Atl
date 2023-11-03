#pragma once
#include "../template.h"
#include "../model/Result.h"
#include "../model/UnitTest.h"
#include "../model/TestClass.h"
#include "../model/Module.h"
#include "../model/Test.h"
#include "../model/AllTest.h"
#include "views/CommonViews.h"

//class AssertPresenter {
//public:
//	string getString(sharedptr<Result>);
//};
//
//class UnitTestPresenter {
//	AssertPresenter m_assertPresenter;
//public:
//	string getString(Test);
//};
//
//class TestClassPresenter {
//	UnitTestPresenter m_unitTestPresenter;
//public:
//	string getString(Test);
//};
//
//class ModulePresenter {
//	TestClassPresenter m_testClassPresenter;
//public:
//	string getString(Test);
//};


class Presenter {
public:
	string getStringFromTestResult(sharedptr<Test>);
};

