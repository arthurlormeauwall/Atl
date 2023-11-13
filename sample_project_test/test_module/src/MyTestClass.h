#pragma once
#include "atl_includes.h"


class MyTestClass: public TestClassBuilder {
public:
	MyTestClass(TestData td) : TestClassBuilder(td) {}
	virtual void addChildren() override;
};