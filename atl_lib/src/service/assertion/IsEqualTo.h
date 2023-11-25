#pragma once
#include "../../template.h"
#include "../../model/Result.h"

template<typename T>
class IsEqualTo {
	T m_expected;
	T m_actual;
public:
	IsEqualTo(T, T);
	Result getResult();
};


template<typename T>
IsEqualTo<T>::IsEqualTo(T actual, T expected) : m_actual(actual), m_expected(expected) {

}

template<typename T>
Result IsEqualTo<T>::getResult(){
	bool pass = (m_actual == m_expected);
	string message;
	if (pass) {
		message = "assertion is good :) ";
	}
	else {
		message = "expected to be equal to: " + std::to_string(m_expected) + " but was equal to: " + std::to_string(m_actual);
	}
	return Result(pass, message);
}

template<>
Result IsEqualTo<std::string>::getResult();
