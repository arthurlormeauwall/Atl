#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "../../model/Path.h"

template<typename T>
class IsEqualTo : public Assertion<T> {
public:
	IsEqualTo(T, T);
	Result getResult();
};


template<typename T>
IsEqualTo<T>::IsEqualTo(T actual, T expected) : Assertion<T>(actual, expected) {

}

template<typename T>
Result IsEqualTo<T>::getResult(){
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
	return Result(pass, message);
}

template<>
Result IsEqualTo<std::string>::getResult();
