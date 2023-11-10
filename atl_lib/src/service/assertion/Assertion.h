#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "../../model/Path.h"

template<typename T>
class Assertion {
protected:
	T m_expected;
	T m_actual;
public:
	Assertion() : m_expected(0.00), m_actual(0.00) {}
	Assertion(T actual, T expected) : m_expected(expected), m_actual(actual) {}
	virtual Result getResult() = 0;
};

