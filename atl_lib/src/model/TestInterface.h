#pragma once
#include "TestData.h"

class TestInterface {
public: 
	virtual void init() = 0;
	virtual void run() = 0;
	virtual TestData getData()=0;
};