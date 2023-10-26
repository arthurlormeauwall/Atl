#include "Assertion.h"

sharedptr<Result> isEqualToAssertion<std::string>::getResult(Path path)
{
	std::string actual, expected;
	actual = Assertion<std::string>::m_actual;
	expected = Assertion<std::string>::m_expected;

	bool pass = (actual == expected);
	string message;
	if (pass) {
		message = "assertion is good :) ";
	}
	else {
		message = "expected to be equal to: " + Assertion<std::string>::m_expected + " but was equal to: " + Assertion<std::string>::m_actual;
	}
	return std::make_shared<Result>(pass, message);
}