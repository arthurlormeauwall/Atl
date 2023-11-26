#pragma once
#include "../../template.h"

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
