#pragma once
#include "atl_includes.h"

class AnotherTestClass : public TestClassBuilder {
public:
	AnotherTestClass(TestData td) : TestClassBuilder(td) {}
	void addChildren();
};

class AThirdTestClass : public TestClassBuilder{
public:
	AThirdTestClass(TestData td) : TestClassBuilder(td) {}
	void addChildren();
};

