#pragma once
#include "atl_includes.h"


class MyTestClass : public TestClass {
public:
	MyTestClass(const string& n) : TestClass(n) {}
	void addTests();
};