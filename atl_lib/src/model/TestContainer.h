#pragma once
#include "../pch.h"
#include "TestResultContainer.h"

struct UnitTest
{
	Path path;
	vector<sharedptr<Result>>(*unitTestRunnable)(Path);
	UnitTest(const string& name,
		vector<sharedptr<Result>>(*function)(Path)) :
		unitTestRunnable(function) {
		path.unitTestName = name;
	}
	void setPath(const string& moduleName, const string& testClassName) {
		path.moduleName = moduleName;
		path.testClassName = testClassName;
	}
};

struct TestClass {
	string name;
	string moduleName;
	vector<sharedptr<UnitTest>> unitTests;
	TestClass(string name) :
		name(name) {
	}
	virtual void addTests() = 0;
	void addUnitTest(sharedptr<UnitTest> ut) {
		unitTests.push_back(ut);
	}
	void setModuleName(const string& m) {
		moduleName = m;
		setNames();
	}
	void setNames() {
		for (sharedptr<UnitTest> ut : unitTests) {
			ut->setPath(moduleName, name);
		}
	}
};

struct Module {
	string name;
	vector<sharedptr<TestClass>> testClasses;
	Module(string name) :
		name(name) {
	}
	void addTestClass(sharedptr<TestClass> tc) {
		testClasses.push_back(tc);
	}
	virtual void addTestClasses() = 0;
	void addTcs() {
		addTestClasses();
		vector<sharedptr<TestClass>>::iterator it;
		for (it = testClasses.begin(); it != testClasses.end(); it++) {
			(*it)->addTests();
		}
		setNames();
	}
	void setNames() {
		vector<sharedptr<TestClass>>::iterator it;
		for (it = testClasses.begin(); it != testClasses.end(); it++) {
			(*it)->setModuleName(name);
		}
	}
};

struct AllTest {
	vector<sharedptr<Module>> modules;
	void addm() {
		addModules();
		vector<sharedptr<Module>>::iterator it;
		for (it = modules.begin(); it != modules.end(); it++) {
			(*it)->addTcs();
		}
	}
	virtual void addModules() = 0;
};


