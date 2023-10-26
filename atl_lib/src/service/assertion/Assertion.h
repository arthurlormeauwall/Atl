#pragma once
#include "../../pch.h"
#include "../../model/TestResultContainer.h"

template<typename T>
class Assertion {
protected:
	T m_expected;
	T m_actual;
public:
	Assertion() : m_expected(0.00), m_actual(0.00) {}
	Assertion(T actual, T expected) : m_expected(expected), m_actual(actual) {}
	virtual sharedptr<Result> getResult(Path path) = 0;
};

template<typename T>
class AssertBuilder {
private:
	T m_actual;
public:
	void setValueToTest(T);
	sharedptr<Assertion<T>> isEqualTo(T);
};

template<typename T>
AssertBuilder<T> assertThat(T actual);

template<typename T>
class isEqualToAssertion : public Assertion<T> {
public:
	isEqualToAssertion(T, T);
	sharedptr<Result> getResult(Path path);
};

template<typename T>
sharedptr<Assertion<T>> AssertBuilder<T>::isEqualTo(T expected)
{
	return std::make_shared<isEqualToAssertion<T>>(m_actual, expected);
}

template<typename T>
AssertBuilder<T> assertThat(T actual) {
	AssertBuilder<T> builder;
	builder.setValueToTest(actual);
	return builder;
}


template<typename T>
void AssertBuilder<T>::setValueToTest(T actual)
{
	m_actual = actual;
}


template<typename T>
isEqualToAssertion<T>::isEqualToAssertion(T actual, T expected) : Assertion<T>(actual, expected) {

}

template<typename T>
sharedptr<Result> isEqualToAssertion<T>::getResult(Path path)
{
	T actual, expected;
	actual = Assertion<T>::m_actual;
	expected = Assertion<T>::m_expected;
	
	bool pass = (actual == expected);
	string message;
	if (pass) {
		message = "assertion is good :) ";
	}
	else {
		message = "expected to be equal to: " + std::to_string(Assertion<T>::m_expected) + " but was equal to: " + std::to_string(Assertion<T>::m_actual);
	}
	return std::make_shared<Result>(pass, message);
}
