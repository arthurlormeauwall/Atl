#pragma once
#include "Assertion.h"
#include "IsEqualTo.h"


template<typename T>
class AssertBuilder {
private:
	T m_actual;
public:
	void setValueToTest(T);
	//sharedptr<Assertion<T>> isEqualTo(T);
};

template<typename T>
AssertBuilder<T> assertThat(T actual);

//template<typename T>
//sharedptr<Assertion<T>> AssertBuilder<T>::isEqualTo(T expected)
//{
//	return std::make_shared<IsEqualTo<T>>(m_actual, expected);
//}

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