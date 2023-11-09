#pragma once
#include "atl_includes.h"

class AnotherTestClass : public TestClass {
public:
	AnotherTestClass(TestData td) : TestClass(td) {}
	void addChildren();
};

class AThirdTestClass : public TestClass {
public:
	AThirdTestClass(TestData td) : TestClass(td) {}
	void addChildren();
};

