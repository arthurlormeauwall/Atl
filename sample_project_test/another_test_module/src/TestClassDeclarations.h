#pragma once
#include "atl_includes.h"

class AThirdTestClass : public TestClass {
public:
	AThirdTestClass(const string& n) : TestClass(n) {}
	void addTests();
};

class AnotherTestClass : public TestClass {
public:
	AnotherTestClass(const string& n) : TestClass(n) {}
	void addTests();
};

