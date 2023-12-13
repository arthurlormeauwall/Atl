#pragma once
#include "atl_includes.h"

class AnotherTestClass : public TestClassBuilder {
public:
	AnotherTestClass(string name) : TestClassBuilder(name) {}
	void addUnitTests() override;
};

class AThirdTestClass : public TestClassBuilder {
public:
	AThirdTestClass(string name) : TestClassBuilder(name) {}
	void addUnitTests() override;
};

