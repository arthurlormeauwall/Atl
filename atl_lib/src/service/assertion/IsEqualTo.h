#pragma once
#include "../../template.h"
#include "../../model/Result.h"

class ResultResolver {
public:
	virtual Result getResult() = 0;
};

template<typename T>
struct to_string {
	static string toString(T v) {
		return "undefined to_string";
	}
};

template<>
struct to_string<int> {
	static string toString(int v) {
		return std::to_string(v);
	}
};

template<>
struct to_string<long double> {
	static string toString(long double value) {
		return std::to_string(value);
	}
};

template<>
struct to_string<float> {
	static string toString(float value) {
		return std::to_string(value);
	}
};
template<>
struct to_string<double> {
	static string toString(double value) {
		return std::to_string(value);
	}
};
template<>
struct to_string<unsigned long long> {
	static string toString(unsigned long long value) {
		return std::to_string(value);
	}
};
template<>
struct to_string<unsigned long> {
	static string toString(unsigned long value) {
		return std::to_string(value);
	}
};
template<>
struct to_string<unsigned> {
	static string toString(unsigned value) {
		return std::to_string(value);
	}
};
template<>
struct to_string<long long> {
	static string toString(long long value) {
		return std::to_string(value);
	}
};
template<>
struct to_string<long> {
	static string toString(long value) {
		return std::to_string(value);
	}
};

template<>
struct to_string<string> {
	static string toString(string value) { return value; }
};



template<typename T>
class ComparatorResultResolver : public ResultResolver {
	bool (*compare)(T, T) = NULL;
	string(*toString)(T) = NULL;
	T m_actual;
	T m_expected;
public:
	ComparatorResultResolver(T* a, T* e, bool (*c)(T, T), string(*ts)(T)) :
		m_actual(*a), m_expected(*e), compare(c), toString(ts) {
	}

	ComparatorResultResolver(T* a, T* e, string (*ts)(T)) :
		m_actual(*a), m_expected(*e), toString(ts) {
	}

	ComparatorResultResolver(T* a, T* e) :
		m_actual(*a), m_expected(*e) {
	}

	Result getResult() {
		bool pass = false;
		if (compare != NULL) {
			pass = compare(m_actual, m_expected);
		}
		else {
			pass = m_actual == m_expected;
		}
		string message, expectedString, actualString;
		if (toString != NULL) {
			expectedString = toString(m_expected);
			actualString = toString(m_actual);
		}
		else {
			expectedString = to_string<T>::toString(m_expected);
			actualString = to_string<T>::toString(m_actual);
		}

		if (pass) {
			message = "assertion is good :) ";
		}
		else {
			message = "expected to be equal to: \"" + expectedString
				+ "\" but was equal to: \"" + actualString + "\"";
		}

		return Result(pass, message);
	}
};

template<typename T>
class IsEqualTo {
	T m_expected;
	T m_actual;
	sharedptr<ResultResolver> resultResolver;
public:
	IsEqualTo(T, T);
	Result getResult(bool (*compare)(T a, T b), string(*toString)(T it));
	Result getResultWithCustomToString(string (*toString)(T it));
	Result getResult();
};


template<typename T>
IsEqualTo<T>::IsEqualTo(T actual, T expected) : m_actual(actual), m_expected(expected) {
}

template<typename T>
Result IsEqualTo<T>::getResult(bool (*compare)(T a, T b), string(*toString)(T it)) {
	resultResolver = std::make_shared<ComparatorResultResolver<T>>(&m_actual,
		&m_expected,
		compare,
		toString);
	return resultResolver->getResult();
}

template<typename T>
Result IsEqualTo<T>::getResultWithCustomToString(string (*toString)(T it)) {
	resultResolver = std::make_shared<ComparatorResultResolver<T>>(&m_actual,
		&m_expected,
		toString);
	return resultResolver->getResult();
}
template<typename T>
Result IsEqualTo<T>::getResult() {
	resultResolver = std::make_shared<ComparatorResultResolver<T>>(&m_actual,
		&m_expected);
	return resultResolver->getResult();
}
