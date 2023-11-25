#pragma once
#include "../../template.h"
#include "../../model/Result.h"

template<typename T>
class IsEqualTo {
	T m_expected;
	T m_actual;
public:
	IsEqualTo(T, T);
	Result getResult(bool (*compare)(T a, T b), string (*toString)(T it));
};


template<typename T>
IsEqualTo<T>::IsEqualTo(T actual, T expected) : m_actual(actual), m_expected(expected) {
}

template<typename T>
Result IsEqualTo<T>::getResult(bool (*compare)(T a, T b), string (*toString)(T it)){
	bool pass = compare(m_actual, m_expected);
	string message;
	if (pass) {
		message = "assertion is good :) ";
	}
	else {
		message = "expected to be equal to: " + toString(m_expected) + " but was equal to: " + toString(m_actual);
	}
	return Result(pass, message);
}
