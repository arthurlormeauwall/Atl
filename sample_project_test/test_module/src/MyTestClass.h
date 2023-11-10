#pragma once
#include "atl_includes.h"


class MyTestClass: public TestClassInit {
public:
	MyTestClass(TestData td) : TestClassInit(td) {}
	void addChildren();
};