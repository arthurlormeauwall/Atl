#pragma once
#include "../template.h"
#include "Test.h"
#include "TestData.h"
#include "Path.h"

class AllTest : public Test {
public:
	AllTest() {}
	template<typename T>
	sharedptr<T> createModule(string name) {
		m_testData.hasChildren = true;
		return std::make_shared<T>(TestData(Path(name)));
	}

};
