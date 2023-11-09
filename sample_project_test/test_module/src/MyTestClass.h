#pragma once
#include "atl_includes.h"


class MyTestClass : public TestClass {
public:
	MyTestClass(TestData td) : TestClass(td) {}
	void addChildren();
};