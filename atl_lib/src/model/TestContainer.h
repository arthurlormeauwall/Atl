#pragma once
#include "../pch.h"
#include "TestResultContainer.h"

struct UnitTest
{
	Path path;
	string name;
	vector<sharedptr<Result>>(*unitTestRunnable)(Path);
	UnitTest(const string& moduleName,
		const string& testClassName,
		const string& unitTestName,
		vector<sharedptr<Result>>(*function)(Path)) :
		path(Path(moduleName, testClassName, unitTestName)),
		unitTestRunnable(function) {}
};

struct TestClass {
	string name;
	testMap<sharedptr<UnitTest>> unitTests;
	TestClass(string name, testMap<sharedptr<UnitTest>> unitTests) :
		name(name), unitTests(unitTests) {}
};

struct Module {
	string name;
	testMap<TestClass> testClasses;
	Module(string name, testMap<TestClass> testClasses) :
		name(name), testClasses(testClasses) {}
};

struct AllTest {
	testMap<Module> modules;
};

class TestContainer
{
	AllTest m_allTest;
public : 
	void addUnitTest(sharedptr<UnitTest>);
	vector<sharedptr<UnitTest>> getAllUnitTest();
};

