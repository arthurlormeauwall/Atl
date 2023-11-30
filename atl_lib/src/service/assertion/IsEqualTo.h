#pragma once
#include "../../template.h"
#include "../../model/Result.h"
#include "ToStringTemplate.h"

template<typename T>
class ResultResolver {
public:
	virtual bool getPass(T& expected, T& actual) = 0;
	virtual sharedptr<vector<string>> getFailedMessageTokens(const T& expected, const T& actual) = 0;
};

template<typename T>
class ComparatorResultResolver : public ResultResolver<T> {
	bool (*compare)(T, T) = NULL;
	string(*toString)(T) = NULL;
public:
	ComparatorResultResolver(bool (*c)(T, T), string(*ts)(T)) : compare(c), toString(ts) {
	}

	ComparatorResultResolver(string(*ts)(T)) : toString(ts) {
	}

	ComparatorResultResolver() {
	}

	bool getPass(T& expected, T& actual) override {
		bool pass = false;
		if (compare != NULL) {
			pass = compare(actual, expected);
		}
		else {
			pass = actual == expected;
		}
		return pass;
	}

	sharedptr<vector<string>> getFailedMessageTokens(const T& expected, const T& actual) override {
		string expectedString, actualString;
		if (toString != NULL) {
			expectedString = toString(expected);
			actualString = toString(actual);
		}
		else {
			expectedString = to_string<T>::toString(expected);
			actualString = to_string<T>::toString(actual);
		}
		auto message = std::make_shared<vector<string>>(vector<string>({
		string("expected :       ==> \"").append(actualString).append("\""),
		string("to be equal to : ==> \"").append(expectedString).append("\"")}));
		return message;
	}
};

template<typename T>
class IsEqualTo {
	T m_expected;
	T m_actual;
public:
	IsEqualTo(T, T);
	Result getResult(bool (*compare)(T a, T b), string(*toString)(T it));
	Result createResult(sharedptr<ResultResolver<T>> resultResolver);
	Result getResultWithCustomToString(string(*toString)(T it));
	Result getResult();
};

template<typename T>
IsEqualTo<T>::IsEqualTo(T actual, T expected) : m_actual(actual), m_expected(expected) {
}

template<typename T>
Result IsEqualTo<T>::getResult(bool (*compare)(T a, T b), string(*toString)(T it)) {
	return createResult(std::make_shared<ComparatorResultResolver<T>>(compare,
		toString));
}

template<typename T>
Result IsEqualTo<T>::getResultWithCustomToString(string(*toString)(T it)) {
	return createResult(std::make_shared<ComparatorResultResolver<T>>(toString));
}

template<typename T>
Result IsEqualTo<T>::getResult() {
	return createResult(std::make_shared<ComparatorResultResolver<T>>());
}

template<typename T>
Result IsEqualTo<T>::createResult(sharedptr<ResultResolver<T>> resultResolver) {
	vector<string>messageTokens;
	bool pass = resultResolver->getPass(m_actual, m_expected);
	if (!pass) {
		messageTokens = *(resultResolver->getFailedMessageTokens(m_actual, m_expected));
	}
	return Result(pass, messageTokens);
}